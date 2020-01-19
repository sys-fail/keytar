#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "freertos/queue.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"

// columns / rows (where a column corresponds to a finger)
int pins[] = {32, 15, 33, 27, 34, 39, 36, 4};
#define ncols 4
#define nrows 4
#define debounce_cycles 3
#define npins (nrows+ncols)
#define nkeys (ncols*nrows)
uint16_t keys;
static xQueueHandle key_evt_queue = NULL;
char keybounce[nkeys];

void keytar_scan_task(void*);

void keytar_setup() {
  for (int i = 0; i < npins; i++) {
    gpio_pad_select_gpio(pins[i]);
    gpio_pullup_dis(pins[i]);
    if (i < nrows) {
      // outputs (set to input to tristate until needed)
      gpio_set_direction(pins[i], GPIO_MODE_INPUT);
    } else {
      gpio_set_direction(pins[i], GPIO_MODE_INPUT);
      gpio_pulldown_en(pins[i]);
    }
  }
  key_evt_queue = xQueueCreate(10, sizeof(uint16_t));
  xTaskCreate(keytar_scan_task, "keytarscan", 20000, NULL, 5, NULL);
}

void keytar_scan_task(void* _) {
  while (true) {
    uint16_t lkeys=keys;
    for (int i = 0; i < nrows; i++) {
      gpio_set_direction(pins[i], GPIO_MODE_OUTPUT);
      gpio_set_level(pins[i], 1);
      for (int j = 0; j < ncols; j++) {
        int k = (i * nrows) + j;
	gpio_pulldown_en(pins[nrows+j]);
        if (gpio_get_level(pins[nrows + j])) {
          if (keybounce[k] > debounce_cycles) {
            keys |= 1 << k;
	    keybounce[k] = 0;
          } else {
            keybounce[k]++;
          }
        } else {
          if (keybounce[k] > 0) {
            keybounce[k]--;
          } else {
            keys &= ~(1 << k);
	    keybounce[k] = 0;
          }
        }
	gpio_pulldown_dis(pins[nrows+j]);
      }
      gpio_set_level(pins[i], 0);
      gpio_set_direction(pins[i], GPIO_MODE_INPUT);
      gpio_pullup_dis(pins[i]);
    }
    vTaskDelay(1);
    if (lkeys ^ keys) {
      xQueueSend(key_evt_queue, &keys, (unsigned int) NULL);
      //      printf("scan_task: %x\n", keys);
    }
  }
}

/*
  NS

  _E
  WF
  12

--------------
  NN_ N_H    S S
  _R_ L      D
    XZ      Q
    /`      \

    AI      O
  _ _T    E E
    CM      U
    =]      [

    VJ      K
    YB      P
  W WG    F F
    '-      ;

    0.      ,
    79      8
    46      5
  1 13    2 2
--------------

011=S
012=D
014=Q
018=\
-----
021=O
022=E
024=U
028=[
-----
041=K
042=P
044=F
048=;
-----
081=,
082=8
084=5
088=2

101=H
102=L
104=Z
108=`
-----
110=N
120=R
140=X
180=/

201=I
202=T
204=M
208=]
-----
210=A
220=_
240=C
280==

401=J
402=B
404=G
408=-
-----
410=V
420=Y
440=W
480='

801=.
802=9
804=6
808=3
-----
810=0
820=7
840=4
880=1

|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

011=S=0
012=D=1
014=Q=2
018=\=3
021=O=4
022=E=5
024=U=6
028=[=7

041=K=8
042=P=9
044=F=a
048=;=b
081=,=c
082=8=d
084=5=e
088=2=f

101=H=10
102=L=11
104=Z=12
108=`=13
110=N=14
120=R=15
140=X=16
180=/=17

201=I=18
202=T=19
204=M=1a
208=]=1b
210=A=1c
220=_=1d
240=C=1e
280===1f

401=J=20
402=B=21
404=G=22
408=-=23
410=V=24
420=Y=25
440=W=26
480='=27

801=.=28
802=9=29
804=6=2a
808=3=2b
810=0=2c
820=7=2d
840=4=2e
880=1=2f

||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

110=N 
120=R 
130=X 
140=/
210=A 
220=_ 
230=C 
240==
310=V 
320=Y 
330=W 
340='
410=0 
420=7 
430=4 
440=1
011=S
012=D
013=Q 
014=\
021=O 
022=E 
023=U 
024=[
031=K 
032=P 
033=F 
034=;
041=, 
042=8 
043=5 
044=2
101=H 
201=I 
301=J
401=.
102=L 
202=T 
302=B 
402=9
103=Z 
203=M 
303=G 
403=6
104=` 
204=] 
304=- 
404=3


||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

110=N 120=R 130=X 140=/
210=A 220=_ 230=C 240==
310=V 320=Y 330=W 340='
410=0 420=7 430=4 440=1

011=S 012=D 013=Q 014=\
021=O 022=E 023=U 024=[
031=K 032=P 033=F 034=;
041=, 042=8 043=5 044=2

101=H 201=I 301=J 401=.
102=L 202=T 302=B 402=9
103=Z 203=M 303=G 403=6
104=` 204=] 304=- 404=3
*/

char kmap[][nrows] = {"nav0", // col 2, row 1
		      "r y7", // col 2, row 2
		      "xcw4", // col 2, row 3
		      "/='1", // col 2, row 4

		      "sok,", // col 1, row 1
		      "dep8", // col 1, row 2
		      "quf5", // col 1, row 3
		      "\\[;2",// col 1, row 4

		      "hlz`", // col 3, row 1
		      "itm]", // col 3, row 2
		      "jbg-", // col 3, row 3
		      ".963", // col 3, row 4
};

#include "HIDKeyboardTypes.h"
KEYMAP fnmap[] = {{0,0}, // dunna do anythin
		  {0x28, 0},          /* LF  */  /* Keyboard Return (Enter) */
		  {0, 0},             // magical "really forward key"
		  {0x4f, 0},          /* RIGHT_ARROW */
		  {0, 0},
		  
		  {0x2b, 0},          /* TAB */  /* Keyboard Tab */
		  {0x52, 0},          /* UP_ARROW */
		  {0x51, 0},          /* DOWN_ARROW */
		  {0, 0},
		  
		  {0x2a, 0},          /* BS  */  /* Keyboard Delete (Backspace) */
		  {0, 0},             /* ESC */
		  {0x50, 0},          /* LEFT_ARROW */
		  {0, 0},
};
		
KEYMAP keytar_eato(uint16_t k) {
  // first we transform k into which key of each column is being pressed
  char kc[4] = {(k&0x000f),
		((k>>4)&0x000f),
		((k>>8)&0x000f),
		((k>>12)&0x000f)};

  // now reduce kc to which bit is set and
  // switch on whether or not more than 1 key is pressed in any column
  for (int icol=1; icol<4; icol++) {
    int zrow=0; while ((kc[icol]>>zrow++) > 0); // first row going down that is not pressed in this column
    // check it's not oversaturated:
    if ( kc[icol] & ~(1 << (zrow-2)) ) {
      printf("ERROR: MULTIPLE KEYS IN A COLUMN WERE PRESSED, %x %x\n", kc[icol], ~(1 << (zrow-2)));
    }
    // for now we just return the highest value pressed key (down has precedence, maybe we should switch it so people's hands don't cause mroe accodietnal clicks?
    kc[icol]=zrow-1;
   
    // if 1, then none are pressed
    // if 2, then 1 is pressed
    // if 3, then 2 and possibly 1 are pressed.
    //printf("col %d, row %d\n", icol, kc[icol]);
  }

  uint16_t fk=0;
  if (kc[3]>0) fk=8+kc[3];
  if (kc[2]>0) fk=4+kc[2];
  if (kc[1]>0) fk=0+kc[1];
  
  // ==========================
  // now that preperations are complete:
  KEYMAP m = {0, 0};

  // first deal with modifier keys
  if (kc[0]&0x2) m.modifier |= KEY_SHIFT;
  if (kc[0]&0x4) m.modifier |= KEY_CTRL;
  if (kc[0]&0x8) m.modifier |= KEY_ALT;
   
  // find the first column that is pressed.
  // find the second column that is pressed.
  // line up the array indicies into kmap so it just works?
  //printf("3: %d, 2: %d, 1: %d, 0: %d\n", kc[3], kc[2], kc[1], kc[0]);
  uint16_t c=0;
  if (kc[3]>0 && kc[2]>0 && kc[1]<=0) c=kmap[kc[2]-1][kc[3]-1];
  if (kc[3]>0 && kc[2]<=0 && kc[1]>0) c=kmap[8+kc[3]-1][kc[1]-1];
  if (kc[3]<=0 && kc[2]>0 && kc[1]>0) c=kmap[4+kc[1]-1][kc[2]-1];
  m.usage = keymap[c].usage;
  m.modifier |= keymap[c].modifier;


  if (kc[0]&0x1 && fk>0) {
    printf("fk: %x\n", fk);
    m=fnmap[fk]; // Fn key maps to some weirder stuff, someday will support release and chords
  }

  return m;
}
  	
#include "ble_hid.h"

void app_main()
{
  gpio_pad_select_gpio(13);
  gpio_set_direction(13, GPIO_MODE_OUTPUT);
  gpio_set_level(13, 1);

  printf("keytar r0\n");
  keytar_setup();
  ble_hid_setup();
  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);
  printf("ESP32: %d CPU cores, WiFi%s%s, ",
	 chip_info.cores,
	 (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
	 (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
  
  printf("silicon rev %d, ", chip_info.revision);
  printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024*1024),
	 (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");
  
  uint16_t keys;
  KEYMAP c;
  while (1) {
    if(xQueueReceive(key_evt_queue, &keys, portMAX_DELAY)) {
      c = keytar_eato(keys);
      //if (c>0) printf("%c", c); fflush(stdout);
      ble_hid_send(c);
      gpio_set_level(13, 1);
    }
    vTaskDelay(10 / portTICK_PERIOD_MS);
    gpio_set_level(13, 0);
  }
}
