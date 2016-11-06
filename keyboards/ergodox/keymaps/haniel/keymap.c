#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

/* #define BASE 0 // default layer */
/* #define SYMB 1 // symbols */
/* #define MDIA 2 // media keys */

#define _DV_EM 0
#define _DV 1
#define _LW 2
#define _RS 3
#define _MD 4


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Dvorak for Emacs
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   ~    |   1  |   2  |   3  |  4   |   5  | LEFT |           |  L1  |   6  |   7  |   8  |   9  |   0  |   \    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | BkSp   |   '  |   ,  |   .  |   P  |   Y  |Space |           |  Space |   F  |   G  |   C  |   R  |   L  | Backspace|
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | CapsL  |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |T / L2|   N  |   S  |CapsLock|
   * |--------+------+------+------+------+------| Enter|           | Enter  |------+------+------+------+------+--------|
   * | Space |   :  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |Z/Ctrl| RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |Enter/LGui| Alt_R|  Alt | Down |←/Lower|                                   |→/Raise | Up |   [  |   ]  |Space/LGui|
   *   `-----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | Del  | App  |       | Alt_R  |  Esc |
   *                             ,----------|------|------|       |------+--------+-----------.
   *                             |          |      | Home |       | PgUp |        |           |
   *                             |Space/LGui|Tab/Ctrl|------|       |------|Tab/Ctrl| Space/LGui|
   *                             |          |      | End  |       | PgDn |        |           |
   *                             `------------------------'       `---------------------------'
   */
  // If it accepts an argument (i.e, is a function), it doesn't need KC_.
  // Otherwise, it needs KC_*
  [_DV_EM] = KEYMAP(  // layer 0 : default
                    // left hand
                    KC_GRV,         KC_1,           KC_2,    KC_3,   KC_4,   KC_5,   KC_LEFT,
                    KC_BSPC,        KC_QUOT,        KC_COMM, KC_DOT, KC_P,   KC_Y,   KC_SPC,
                    KC_CAPSLOCK,    KC_A,           KC_O,    KC_E, KC_U, KC_I,
                    KC_LSFT,  KC_SCLN,        KC_Q,    KC_J,   KC_K,   KC_X,   KC_ENTER,
                    MO(_RS),KC_RALT,      KC_LALT,  KC_DOWN, LT(_RS, KC_LEFT),

                    KC_DELT, ALT_T(KC_APP),
                    KC_HOME,
                    GUI_T(KC_SPC), CTL_T(KC_TAB), KC_END,
                    // right hand
                    TG(1),       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_BSLS,
                    KC_SPC,      KC_F,   KC_G,   KC_C,   KC_R,   KC_L,             KC_BSPC,
                                 KC_D,   KC_H,   LT(_MD, KC_T), KC_N,       KC_S, KC_CAPSLOCK,
                    KC_ENTER,KC_B,   KC_M,   KC_W,   KC_V,   CTL_T(KC_Z),      KC_RSFT,
                    LT(_LW, KC_RIGHT),  KC_UP,KC_LBRC,KC_RBRC, MO(_LW),

                    KC_RALT,        KC_ESC,
                    KC_PGUP,
                    KC_PGDN, CTL_T(KC_TAB),GUI_T(KC_SPC)
                      ),
  /* Keymap 1: Dvorak
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   ~    |   1  |   2  |   3  |  4   |   5  | LEFT |           |  L1  |   6  |   7  |   8  |   9  |   0  |   \    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | BkSp   |   '  |   ,  |   .  |   P  |   Y  |  =   |           |  Tab |   F  |   G  |   C  |   R  |   L  |   /    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | CapsL  |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |T / L2|   N  |   S  |   -    |
   * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
   * | LShift |   :  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |Z/Ctrl| RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |Enter/LGui| Alt_R|  Alt | Down |←/Lower|                                   |→/Raise | Up |   [  |   ]  |Space/LGui|
   *   `-----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | Del  | App  |       | Alt_R  |  Esc |
   *                             ,----------|------|------|       |------+--------+-----------.
   *                             |          |      | Home |       | PgUp |        |           |
   *                             |Enter/LGui|Tab/Ctrl|------|       |------|Tab/Ctrl| Space/LGui|
   *                             |          |      | End  |       | PgDn |        |           |
   *                             `------------------------'       `---------------------------'
   */
  // layer 1 : dvorak
  [_DV] = KEYMAP(
                 // left hand
                 KC_GRV,         KC_1,           KC_2,    KC_3,   KC_4,   KC_5,   KC_LEFT,
                 KC_BSPC,        KC_QUOT,        KC_COMM, KC_DOT, KC_P,   KC_Y,   KC_EQL,
                 KC_CAPSLOCK,    KC_A,           KC_O,    KC_E, KC_U, KC_I,
                 KC_LSFT,  KC_SCLN,        KC_Q,    KC_J,   KC_K,   KC_X,   ALL_T(KC_NO),
                 GUI_T(KC_ENT),KC_RALT,      KC_LALT,  KC_DOWN,LT(_RS, KC_LEFT),
                 KC_DELT, ALT_T(KC_APP),
                 KC_HOME,
                 GUI_T(KC_ENT), CTL_T(KC_TAB), KC_END,
                 // right hand
                 TG(1),       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_BSLS,
                 KC_TAB,      KC_F,   KC_G,   KC_C,   KC_R,   KC_L,             KC_SLSH,
                              KC_D,   KC_H,   LT(_MD, KC_T), KC_N,       KC_S, KC_MINS,
                 MEH_T(KC_NO),KC_B,   KC_M,   KC_W,   KC_V,   CTL_T(KC_Z),      KC_RSFT,
                 LT(_LW, KC_LEFT),  KC_UP,KC_LBRC,KC_RBRC, GUI_T(KC_SPC),
                 KC_RALT,        KC_ESC,
                 KC_PGUP,
                 KC_PGDN, CTL_T(KC_TAB),GUI_T(KC_SPC)
                 ),
  /* Keymap 2: Lower
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   F11  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F12  |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |   [    |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |  &   |   *  |   =  |   +  |   {    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |   ]    |   #  |   $  |   (  |   )  |   `  |------|           |------|   )  |   /  |   _  |   |  |   ?  |   }    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |     |     |     |     |     |      |           |      |     |     |     |     |     |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |     |     |     |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // Lower
  [_LW] = KEYMAP(
                 // left hand
                 KC_F11,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,              KC_TRNS,
                 KC_LBRC,KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,       KC_TRNS,
                 KC_RBRC,LSFT(KC_SLSH),KC_TILD, KC_MINS, KC_BSLS, KC_LPRN,
                 KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,           KC_TRNS,
                 KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,

                 KC_TRNS,KC_TRNS,
                 KC_TRNS,
                 KC_TRNS,KC_TRNS,KC_TRNS,
                 // right hand
                 KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F12,
                 KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL, KC_PLUS, KC_LCBR,
                          KC_RPRN, KC_SLSH, KC_UNDS, KC_PIPE, KC_GRV, KC_RCBR,
                 KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
                 KC_TRNS,KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,
                 KC_TRNS, KC_TRNS,
                 KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS
                 ),
  /* Keymap 3: Raise
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   F11  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F12  |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |   [    |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |  &   |   *  |   =  |   +  |   {    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |   ]    |   #  |   $  |   (  |   )  |   `  |------|           |------|   )  |   /  |   _  |   |  |   ?  |   }    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // Raise
  [_RS] = KEYMAP(
                 // left hand
                 KC_F11,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
                 KC_TRNS,KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_TRNS,
                 KC_TRNS,KC_1,  KC_2,  KC_3,  KC_4,  KC_5,
                 KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
                 KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,

                 KC_TRNS,KC_TRNS,
                 KC_TRNS,
                 KC_TRNS,KC_TRNS,KC_TRNS,
                 // right hand
                 KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F12,
                 KC_TRNS, KC_6,   KC_7,  KC_8,   KC_9,   KC_0,  KC_TRNS,
                          KC_6,   KC_7,  KC_8,   KC_9,   KC_0,  KC_MINS,
                 KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                 KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,

                 KC_TRNS, KC_TRNS,
                 KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS
                 ),
  /* Keymap 4: Media and mouse keys
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |MsWhLf|MsLeft|MsDown|MsRght|MsWhRg|------|           |------|      | Mute |      | Prev | Next |  Play  |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |MsWhDw|MsWhUp|      |      |           |      |      |      |      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      | BTN1 | Back |                                       |  Fwd |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 | Lclk | Rclk |------|       |------| Mute | Mclk |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // MEDIA AND MOUSE
  [_MD] = KEYMAP(
                 KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS,       KC_TRNS, KC_MS_U, KC_MS_WH_RIGHT, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_MS_WH_LEFT, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_WBAK,

                 KC_TRNS, KC_TRNS,
                 KC_TRNS,
                 KC_BTN1, KC_BTN2, KC_TRNS,
                 // right hand
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_DOWN, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_MPLY, KC_TRNS, KC_MPRV, KC_MNXT, KC_MINS,
                 KC_TRNS, KC_TRNS, KC_VOLD, KC_TRNS, KC_VOLU, KC_TRNS, KC_TRNS,
                 KC_WFWD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                 KC_TRNS, KC_TRNS,
                 KC_TRNS,
                 KC_TRNS, GUI_T(KC_MUTE), KC_BTN3
         ),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(_LW),                // FN1 - Momentary Layer 1 (Lower)
  [2] = ACTION_LAYER_TAP_TOGGLE(_RS)                // FN2 - Momentary Layer 1 (Raise)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            ergodox_board_led_on();
            break;
        default:
            // none
            break;
    }

};
