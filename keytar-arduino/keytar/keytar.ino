 #include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI   18
#define OLED_CLK   5
#define OLED_DC    19
#define OLED_CS    14
#define OLED_RESET 13
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
                         OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#include <analogWrite.h>

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include "BLE2902.h"
#include "BLEHIDDevice.h"
#include "HIDTypes.h"
#include "HIDKeyboardTypes.h"
#include <driver/adc.h>

// columns / rows (where a column corresponds to a finger )
int pins[] = {27, 33, 15, 32, 34, 39, 36, 4};
#define nrows 4
#define ncols 4
#define debounce_cycles 10
#define npins (nrows+ncols)
#define nkeys (ncols*nrows)
uint16_t keys;
uint16_t keyc; // 0-5, 4 times?
char keybounce[nkeys];

void keytar_setup() {
  for (int i = 0; i < npins; i++) {
    if (i < nrows) {
      pinMode(pins[i], OUTPUT);
    } else {
      pinMode(pins[i], INPUT_PULLDOWN);
    }
  }
}

void keytar_scan(void*) {
  while (true) {
    for (int i = 0; i < nrows; i++) {
      pinMode(pins[i], OUTPUT);
      digitalWrite(pins[i], HIGH);
      for (int j = 0; j < ncols; j++) {
        int k = (i * ncols) + j;
        if (digitalRead(pins[nrows + j])) {
          if (keybounce[k] > debounce_cycles) {
            keys |= 1 << k;
          } else {
            keybounce[k]++;
          }
        } else {
          if (keybounce[k] > 0) {
            keybounce[k]--;
          } else {

            keys &= ~(1 << k);
          }
        }
      }
      digitalWrite(pins[i], LOW);
      pinMode(pins[i], INPUT);

      //vTaskDelay(1);
    }
    vTaskDelay(1);
  }
}

/*
  NS
  _E
  WF
  12

  N NH    S S
    RL      D
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

*/

char kmap[] = {
  'n', 'r', 'x', '/', 'h', 'l', 'z', '`',
  'a', ' ', 'c', '=', 'i', 't', 'm', ']',
  'v', 'y', 'w', '\'', 'j', 'b', 'g', '-',
  '0', '7', '4', '1', '.', '9', '6', '3',
  0, 0, 0, 0, 's', 'd', 'q', '\\',
  0, 0, 0, 0, 'o', 'u', 'e', '[',
  0, 0, 0, 0, 'k', 'p', 'f', ';',
  0, 0, 0, 0, ',', '8', '5', '2'
};

char kmap_shift[] = {
  'N', 'R', 'X', '?', 'H', 'L', 'Z', '~',
  'A', '\t', 'C', '+', 'I', 'T', 'M', '}',
  'V', 'Y', 'W', '"', 'J', 'B', 'G', '_',
  ')', '&', '$', '!', '>', '(', '^', '#',
  0, 0, 0, 0, 'S', 'D', 'Q', '|',
  0, 0, 0, 0, 'O', 'U', 'E', '{',
  0, 0, 0, 0, 'K', 'P', 'F', ':',
  0, 0, 0, 0, '<', '*', '%' , '@'
};

#define kprint(a) display.print(a); Serial.print(a)

uint16_t kmapl = sizeof(kmap) / sizeof(kmap[0]);
#define fn_key (1 << 12)
#define shift_key (1 << 13)
#define ctrl_key (1 << 14)
#define alt_key (1 << 15)

std::string print_pattern(int k, int mi, bool sel) {
  char* km = (k & shift_key) ? kmap_shift : kmap;
  std::string s;
  if (sel) {
    for (int r = 0; r < 4; r++) {
      if (mi < 4) {
        s += (mi == r) ? "X" : " ";
        s += km[mi * 8 + r];
        s += km[mi * 8 + r + 4];
        s += "\n";
      } else if (mi >= 4 && mi < 8) {
        kprint(km[r * 8 + mi - 4]);
        kprint((mi == (r + 4)) ? "X" : " ");
        kprint(km[mi * 8 + r + 4]); kprint("\n");
      } else if (mi >= 8 && mi < 12) {
        kprint(km[r * 8 + 4 + mi - 8]);
        kprint(km[r * 8 + 4 + mi - 8 + 32]);
        kprint((mi == (r + 8)) ? "X\n" : "\n");
      }
    }
  } else {
    for (int r = 0; r < 4; r++) {
      if (mi < 4) {
        kprint((mi == r) ? "X" : " ");
        kprint(km[mi * 8 + r]);
        kprint(km[mi * 8 + r + 4]); kprint("\n");
      } else if (mi >= 4 && mi < 8) {
        kprint(km[r * 8 + mi - 4]);
        kprint((mi == (r + 4)) ? "X" : " ");
        kprint(km[mi * 8 + r + 4]); kprint("\n");
      } else if (mi >= 8 && mi < 12) {
        kprint(km[r * 8 + 4 + mi - 8]);
        kprint(km[r * 8 + 4 + mi - 8 + 32]);
        kprint((mi == (r + 8)) ? "X\n" : "\n");
      }
    }
  }
}


char keytar_eato(uint16_t c) {
  static uint16_t lc = 0;
  char r = 0;
  char* km = (c & shift_key) ? kmap_shift : kmap;

  if  (c != lc) {
    int npressed = 0; for (int x = (c & 0xFFF); x; npressed++) x &= x - 1;
    int np = 0;
    int pi = 0;
    display.clearDisplay();
    display.setTextSize(3);             // Normal 1:1 pixel scale
    display.setTextColor(WHITE);        // Draw white text
    display.setCursor(0, 0);
    display.invertDisplay(false);

    if (npressed > 0) {
      for (int i = 0; i < 12; i++) {
        if (c & (1 << i)) {
          np++;
          if (npressed == 1) {
            print_pattern(c, i, false);
            break;
          } else if (np == 2 && c > lc) {
            int mi = (pi * 8) + i - 4;
            print_pattern(c, i, true);
            r = km[mi];
            break;
          }
          pi=i;
        }
      }

    } else {
      // Draw a single pixel in white
      display.drawPixel(0, 0, WHITE);
    }
    display.display();
  }
  lc = c;
  return r;
}

BLEHIDDevice* hid;
BLECharacteristic* input;
BLECharacteristic* output;

uint8_t buttons = 0;
uint8_t button1 = 0;
uint8_t button2 = 0;
uint8_t button3 = 0;
bool connected = false;

class MyCallbacks : public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      connected = true;
      BLE2902* desc = (BLE2902*)input->getDescriptorByUUID(BLEUUID((uint16_t)0x2902));
      desc->setNotifications(true);
    }

    void onDisconnect(BLEServer* pServer) {
      connected = false;
      BLE2902* desc = (BLE2902*)input->getDescriptorByUUID(BLEUUID((uint16_t)0x2902));
      desc->setNotifications(false);
    }
};

/*
   This callback is connect with output report. In keyboard output report report special keys changes, like CAPSLOCK, NUMLOCK
   We can add digital pins with LED to show status
   bit 0 - NUM LOCK
   bit 1 - CAPS LOCK
   bit 2 - SCROLL LOCK
*/
class MyOutputCallbacks : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic* me) {
      uint8_t* value = (uint8_t*)(me->getValue().c_str());
      ESP_LOGI(LOG_TAG, "special keys: %d", *value);
    }
};

void taskServer(void*) {
  BLEDevice::init("keytar");
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyCallbacks());

  hid = new BLEHIDDevice(pServer);
  input = hid->inputReport(1); // <-- input REPORTID from report map
  output = hid->outputReport(1); // <-- output REPORTID from report map

  output->setCallbacks(new MyOutputCallbacks());

  std::string name = "conrailqualitycontent";
  hid->manufacturer()->setValue(name);

  hid->pnp(0x02, 0xe502, 0xa111, 0x0210);
  hid->hidInfo(0x00, 0x02);

  BLESecurity *pSecurity = new BLESecurity();
  //  pSecurity->setKeySize();
  pSecurity->setAuthenticationMode(ESP_LE_AUTH_BOND);

  const uint8_t report[] = {
    USAGE_PAGE(1),      0x01,       // Generic Desktop Ctrls
    USAGE(1),           0x06,       // Keyboard
    COLLECTION(1),      0x01,       // Application
    REPORT_ID(1),       0x01,        //   Report ID (1)
    USAGE_PAGE(1),      0x07,       //   Kbrd/Keypad
    USAGE_MINIMUM(1),   0xE0,
    USAGE_MAXIMUM(1),   0xE7,
    LOGICAL_MINIMUM(1), 0x00,
    LOGICAL_MAXIMUM(1), 0x01,
    REPORT_SIZE(1),     0x01,       //   1 byte (Modifier)
    REPORT_COUNT(1),    0x08,
    HIDINPUT(1),           0x02,       //   Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position
    REPORT_COUNT(1),    0x01,       //   1 byte (Reserved)
    REPORT_SIZE(1),     0x08,
    HIDINPUT(1),           0x01,       //   Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position
    REPORT_COUNT(1),    0x06,       //   6 bytes (Keys)
    REPORT_SIZE(1),     0x08,
    LOGICAL_MINIMUM(1), 0x00,
    LOGICAL_MAXIMUM(1), 0x65,       //   101 keys
    USAGE_MINIMUM(1),   0x00,
    USAGE_MAXIMUM(1),   0x65,
    HIDINPUT(1),           0x00,       //   Data,Array,Abs,No Wrap,Linear,Preferred State,No Null Position
    REPORT_COUNT(1),    0x05,       //   5 bits (Num lock, Caps lock, Scroll lock, Compose, Kana)
    REPORT_SIZE(1),     0x01,
    USAGE_PAGE(1),      0x08,       //   LEDs
    USAGE_MINIMUM(1),   0x01,       //   Num Lock
    USAGE_MAXIMUM(1),   0x05,       //   Kana
    HIDOUTPUT(1),          0x02,       //   Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile
    REPORT_COUNT(1),    0x01,       //   3 bits (Padding)
    REPORT_SIZE(1),     0x03,
    HIDOUTPUT(1),          0x01,       //   Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile
    END_COLLECTION(0)
  };

  hid->reportMap((uint8_t*)report, sizeof(report));
  hid->startServices();

  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->setAppearance(HID_KEYBOARD);
  pAdvertising->addServiceUUID(hid->hidService()->getUUID());
  pAdvertising->start();
  hid->setBatteryLevel(7);

  ESP_LOGD(LOG_TAG, "Advertising started!");
  delay(portMAX_DELAY);

};

void setup() {
  Serial.begin(115200);
  //pinMode(13, OUTPUT);
  keytar_setup();

  Serial.println("Starting BLE");
  xTaskCreate(taskServer, "blesetup", 20000, NULL, 5, NULL);
  xTaskCreate(keytar_scan, "keytarscan", 20000, NULL, 5, NULL);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  display.setRotation(3);

  display.clearDisplay();

  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(10, 0);
  display.println("keytar");
  display.display();
}

void loop() {

  uint16_t k = keys;
  char c = keytar_eato(k);
  if (connected && c > 16) {
    KEYMAP map = keymap[c];
    Serial.println("1");
    uint8_t msg[] = {map.modifier, 0x0, map.usage, 0x0, 0x0, 0x0, 0x0, 0x0};
    input->setValue(msg, sizeof(msg));
    input->notify();
    Serial.println("2");
    uint8_t msg1[] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    Serial.println("3");
    input->setValue(msg1, sizeof(msg1));
    Serial.println("4");
    input->notify();
    Serial.println("5");
    delay(200);
    Serial.println("6");
  }
}



/*
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *ww
 */
