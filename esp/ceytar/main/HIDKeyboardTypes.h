/* Copyright (c) 2015 mbed.org, MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Note: this file was pulled from different parts of the USBHID library, in mbed SDK
 */

#ifndef KEYBOARD_DEFS_H
#define KEYBOARD_DEFS_H

#define REPORT_ID_KEYBOARD 1
#define REPORT_ID_VOLUME   3

/* Modifiers */
enum MODIFIER_KEY {
	KEY_CTRL = 1,
	KEY_SHIFT = 2,
	KEY_ALT = 4,
};


enum MEDIA_KEY {
    KEY_NEXT_TRACK,     /*!< next Track Button */
    KEY_PREVIOUS_TRACK, /*!< Previous track Button */
    KEY_STOP,           /*!< Stop Button */
    KEY_PLAY_PAUSE,     /*!< Play/Pause Button */
    KEY_MUTE,           /*!< Mute Button */
    KEY_VOLUME_UP,      /*!< Volume Up Button */
    KEY_VOLUME_DOWN,    /*!< Volume Down Button */
};

enum FUNCTION_KEY {
	KEY_F1 = 128,   /* F1 key */
	KEY_F2,		 /* F2 key */
	KEY_F3,		 /* F3 key */
	KEY_F4,		 /* F4 key */
	KEY_F5,		 /* F5 key */
	KEY_F6,		 /* F6 key */
	KEY_F7,		 /* F7 key */
	KEY_F8,		 /* F8 key */
	KEY_F9,		 /* F9 key */
	KEY_F10,		/* F10 key */
	KEY_F11,		/* F11 key */
	KEY_F12,		/* F12 key */

	KEY_PRINT_SCREEN,   /* Print Screen key */
	KEY_SCROLL_LOCK,	/* Scroll lock */
	KEY_CAPS_LOCK,	  /* caps lock */
	KEY_NUM_LOCK,	   /* num lock */
	KEY_INSERT,		 /* Insert key */
	KEY_HOME,		   /* Home key */
	KEY_PAGE_UP,		/* Page Up key */
	KEY_PAGE_DOWN,	  /* Page Down key */

	RIGHT_ARROW,		/* Right arrow */
	LEFT_ARROW,		 /* Left arrow */
	DOWN_ARROW,		 /* Down arrow */
	UP_ARROW,		   /* Up arrow */
};

typedef struct {
	unsigned char usage;
	unsigned char modifier;
} KEYMAP;

#define KEYMAP_SIZE (152)
extern const KEYMAP keymap[KEYMAP_SIZE];

#endif
