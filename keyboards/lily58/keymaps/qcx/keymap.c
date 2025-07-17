#include QMK_KEYBOARD_H

#include "users/holykeebs/holykeebs.h"

enum layer_number {
  _QWERTY = 0,
  _RAISE,
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(MS_WHLD, MS_WHLU),  ENCODER_CCW_CW(MS_WHLL, MS_WHLR)  },
    [_RAISE] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
};
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  |       |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+----------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  [       |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+----------|
 * |LCTRL/caps |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | RCTL / ' |
 * |--------+------+------+------+------+------|lclick |    | rclick|------+------+------+------+------+----------|
 * |Sft/Home|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift/End|
 * `-----------------------------------------/       /     \      \-----------------------------------------------'
 *                   | LGUI | LAlt |BackSP| /Del    /       \Enter \  |Space |RAISE |  ]   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,               KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
  KC_TAB,               KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
  MT(KC_LCTL, KC_CAPS), KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MT(KC_RCTL, KC_QUOT),
  MT(KC_LSFT, KC_HOME),  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, MS_BTN1,    MS_BTN2,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(KC_RSFT, KC_END),
                                KC_LGUI, KC_LALT, KC_BSPC, KC_DEL,                      KC_ENT, KC_SPC, LT(_RAISE, TG(_RAISE)), KC_RBRC
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |      |      |  up  |      |      |                    | PGUP |  7   |  8   |  9   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  lef |  dn |  rt  |      |-------.    ,-------|  PGDN |  4   |  5   |  6   |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |  [   |      |      |      |      |      |-------|    |-------|      |  1   |   2  |  3   |      |   ]  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |  0   |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(
  KC_F1,     KC_F2,   KC_F3, KC_F4,      KC_F5,    KC_F6,                         KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  KC_GRV,  _______, _______, KC_UP,    _______,  _______,                       KC_PGUP, KC_KP_7, KC_KP_8, KC_KP_9, _______, _______,
  _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT,  _______,                       KC_PGDN, KC_KP_4, KC_KP_5, KC_KP_6, _______, _______,
  KC_LBRC, _______, _______, _______,  _______,  _______, _______,    _______,  _______, KC_KP_1, KC_KP_2, KC_KP_3, _______, KC_RBRC,
                             _______,  _______,  _______, _______,    _______,  KC_KP_0, _______, _______
),

};

/*layer_state_t layer_state_set_user(layer_state_t state) {*/
/*  return update_tri_layer_state(state, _RAISE);*/
/*}*/

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

// Redefined elsewhere; how come this works for the HK build, but not for us?

/*bool oled_task_user(void) {*/
/*  if (!is_keyboard_master()) {*/
/*    // If you want to change the display of OLED, you need to change here*/
/*    oled_write_ln(read_layer_state(), false);*/
/*    oled_write_ln(read_keylog(), false);*/
/*    oled_write_ln(read_keylogs(), false);*/
/*    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);*/
/*    //oled_write_ln(read_host_led_state(), false);*/
/*    //oled_write_ln(read_timelog(), false);*/
/*  } else {*/
/*    oled_write(read_logo(), false);*/
/*  }*/
/*    return false;*/
/*}*/
#endif // OLED_ENABLE
/**/
/*bool process_record_user(uint16_t keycode, keyrecord_t *record) {*/
/*  if (record->event.pressed) {*/
/*#ifdef OLED_ENABLE*/
/*    set_keylog(keycode, record);*/
/*#endif*/
/*    // set_timelog();*/
/*  }*/
/*  return true;*/
/*}*/
