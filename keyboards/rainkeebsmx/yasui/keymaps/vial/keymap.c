#include "yasui.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
		KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT,
		KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_BSPC,
		KC_LCTL, KC_LALT, MO(1), KC_LSFT, KC_MPLY, KC_SPC, KC_SPC, MO(2), KC_RALT, KC_RCTL),

	KEYMAP(
		KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
		KC_ESC, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_MINS, KC_EQL, KC_QUOT, KC_SCLN, KC_TRNS,
		KC_TAB, KC_DEL, KC_PSCR, KC_LBRC, KC_RBRC, KC_BSLS, KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
		KC_GRV, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_PLUS, KC_DQUO, KC_COLN, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_PIPE, KC_QUES, KC_LABK, KC_RABK, KC_TRNS,
		KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(4), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

/*void encoder_update_user(uint8_t index, bool clockwise) {
	switch (get_highest_layer(layer_state)) {
        case 0:
             if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
            break;
        case 1:
            if (clockwise) {
            tap_code(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }
            break;
		case 2:
			if (clockwise) {
            tap_code(KC_WH_U);
        } else {
            tap_code(KC_WH_D);
        }
			break;
        case 3:
             if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
            break;
    }
}*/

oled_rotation_t oled_init_user(oled_rotation_t rotation) {return OLED_ROTATION_180;}

char wpm[10];

void oled_task_user(void) {
    sprintf(wpm, "WPM: %03d", get_current_wpm());

    // Host Keyboard Layer Status
    oled_write_P(PSTR("       yasui \n"), false);
    oled_write_P(PSTR(" Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case 4:
            oled_write_P(PSTR("Toggle\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    oled_write_P(PSTR(" "), false);
    oled_write(wpm, false);
}
