#include "XCH17.h"
#include QMK_KEYBOARD_H
#define  _QWERTY 0	
#define  _LOWER  1
	
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


	[_QWERTY] = LAYOUT_ALL(
		KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, 
		KC_P7,   KC_P8,   KC_P9,   KC_CALC, 
		KC_P4,   KC_P5,   KC_P6,   KC_PPLS, 
		KC_P1,   KC_P2,   KC_P3,   KC_NO, 
		LT(1, KC_P0),     KC_PDOT, KC_ENT),

	[_LOWER] = LAYOUT_ALL(
		KC_TRNS, KC_TRNS, KC_TRNS, RESET, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS,          KC_TRNS, KC_TRNS),

	
};

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		DDRD |= (1 << 0); PORTD &= ~(1 << 0);
	} else {
		DDRD &= ~(1 << 0); PORTD &= ~(1 << 0);
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_WH_U);
        } else {
            tap_code(KC_WH_D);
        }
    }
    return true;
}