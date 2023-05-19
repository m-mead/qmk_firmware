#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,  // Default
  _RAISE,       // Navigation
  _LOWER,       // Symbols
  _ADJUST,      // Unused
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ------
 * Standard QWERTY layout for the most part.
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |C/Esc |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| O/[   |    |  C/]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LOpt | LGui | Lower | /Space /        \Enter \  | Raise| RGui| ROpt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_QWERTY] = LAYOUT(
  KC_GRV,          KC_1,    KC_2,    KC_3,                KC_4,   KC_5,                                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
  KC_TAB,          KC_Q,    KC_W,    KC_E,                KC_R,   KC_T,                                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSLS,
  LCTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,                KC_F,   KC_G,                                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
  KC_LSFT,         KC_Z,    KC_X,    KC_C,                KC_V,   KC_B,   LOPT_T(KC_LBRC),  RCTL_T(KC_RBRC), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                   KC_LOPT, KC_LGUI, LT(_LOWER, KC_BSPC), KC_SPC, KC_ENT, MO(_RAISE),       KC_RGUI,         KC_ROPT
),
/* Raise
 * ,-----------------------------------------.                    ,--------------------------------------------.
 * |      |      |      |      |      |      |                    |        |      |      |       |      |      |
 * |------+------+------+------+------+------|                    |--------+------+------+-------+------+------|
 * |      |      |      |      |      | Caps |                    | Home   |  End | PgUp | PgDn  |      |      |
 * |------+------+------+------+------+------|                    |--------+------+------+-------+------+------|
 * |      |      |      |      |WLeft |WRight|-------.    ,-------|  Left  | Down |  Up  | Right |      |      |
 * |------+------+------+------+------+------|  C/[  |    | C/]   |--------+------+------+-------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|        |      |      |       |      |      |
 * `-----------------------------------------/       /     \      \--------------------------------------------'
 *                   | LOpt | LGui | Lower| /Space  /       \Enter \  | Raise | RGui| ROpt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 * TODO: numpad
 */
[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______,      _______,                         _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,      KC_CAPS,                         KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______, _______,
  _______, _______, _______, _______, LSG(KC_LEFT), LSG(KC_RGHT),                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______,      _______,      _______, _______,  _______, _______, _______, _______, _______, _______,
                             _______, _______,      _______,      _______, _______,  _______, _______, _______
),
/* Lower
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |   F6 |  F7  |   F8 |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   ~  |   =  |   _  |   {  |   }  |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------| O/[   |    | C/]   |------+------+------+------+------+------|
 * |      |   6  |   7  |  8   |   9  |   0  |-------|    |-------|   |  |   -  |   +  |   [  |   ]  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LOpt | LGui| Lower | /Space /        \Enter \   |Raise |RGui | ROpt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______, _______, _______, _______, _______,                   KC_TILD, KC_EQL, KC_UNDS, KC_LCBR, KC_RCBR,  KC_F12,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, KC_PIPE, KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LOpt | Lower |LGui | /Space  /       \Enter \  | RCtl |RGui  | ROpt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

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

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
