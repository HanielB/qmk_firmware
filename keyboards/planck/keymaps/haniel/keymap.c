// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "backlight.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DV_EM 0
#define _DV 1
#define _LW 2
#define _RS 3
#define _MD 4
#define _MV 5

/* See https://gist.github.com/pocketkk/ab50ff5012b8bf779d6267047e0e6bbc for 8
   layers, left-hand chording and right-hand picking (??) */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Dvorak for Emacs
  |--------------+-----+------+----------+---------+-------+-------+---------+----------+-----+-----+-------------|
  | BackSpace    | '   | ,    | .        | p       | y     | f     | g       | c        | r   | l   | BackSpace   |
  |--------------+-----+------+----------+---------+-------+-------+---------+----------+-----+-----+-------------|
  | CapsLock     | a   | o    | e/Arrows | u       | i     | d     | h       | t/Media  | n   | s   | CapsLock    |
  |--------------+-----+------+----------+---------+-------+-------+---------+----------+-----+-----+-------------|
  | Delete/Shift | :   | d    | j        | k       | x     | b     | m       | w        | v   | z   | Enter/Shift |
  |--------------+-----+------+----------+---------+-------+-------+---------+----------+-----+-----+-------------|
  | Enter/LGui   | L2  | RAlt | Tab/Ctrl | Lower   | Space | Space | Raise   | Tab/Ctrl | Alt | ESC | Enter/LGui  |
  |--------------+-----+------+----------+---------+-------+-------+---------+----------+-----+-----+-------------|
*/

[_DV_EM] = { /* Dvorak for Emacs */
  {KC_BSPC,KC_QUOT, KC_COMM, KC_DOT,KC_P, KC_Y, KC_F, KC_G, KC_C,  KC_R,    KC_L,    KC_BSPC},
  {KC_CAPSLOCK, KC_A, KC_O, LT(_MV, KC_E), KC_U, KC_I,KC_D, KC_H, LT(_MD, KC_T), KC_N,KC_S,  KC_CAPSLOCK},
  {SFT_T(KC_DELT), KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, SFT_T(KC_ENT) },
  {GUI_T(KC_ENT),TG(1),KC_RALT,CTL_T(KC_TAB),MO(_RS),KC_SPC,KC_SPC,MO(_LW),CTL_T(KC_TAB),KC_RALT,KC_ESC,GUI_T(KC_ENT)}
},

/* Keymap 1: Dvorak
  |--------------+-----+------+----------+---------+-------+-------+---------+----------+-----+-----+-------------|
  | BackSpace    | '   | ,    | .        | p       | y     | f     | g       | c        | r   | l   | /           |
  |--------------+-----+------+----------+---------+-------+-------+---------+----------+-----+-----+-------------|
  | CapsLock     | a   | o    | e/Arrows | u       | i     | d     | h       | t/Media  | n   | s   | -           |
  |--------------+-----+------+----------+---------+-------+-------+---------+----------+-----+-----+-------------|
  | Delete/Shift | :   | d    | j        | k       | x     | b     | m       | w        | v   | z   | Enter/RShift |
  |--------------+-----+------+----------+---------+-------+-------+---------+----------+-----+-----+-------------|
  | Enter/LGui   | L1  | RAlt | Tab/Ctrl | Lower   | Space | Space | Raise   | Tab/Ctrl | ↓   | ESC | ↑           |
  |--------------+-----+------+----------+---------+-------+-------+---------+----------+-----+-----+-------------|
*/

[_DV] = { /* Dvorak */
  {KC_BSPC, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC},
  {KC_CAPSLOCK,  KC_A, KC_O, LT(_MV, KC_E), KC_U,KC_I, KC_D, KC_H, LT(_MD, KC_T), KC_N, KC_S, KC_MINS},
  {SFT_T(KC_DELT), KC_SCLN, KC_Q, KC_J, KC_K,  KC_X,  KC_B, KC_M, KC_W, KC_V, KC_Z, RSFT_T(KC_ENT) },
  {GUI_T(KC_ENT),TG(1),KC_RALT,CTL_T(KC_TAB),MO(_RS),KC_SPC,KC_SPC,MO(_LW),CTL_T(KC_TAB),KC_RALT,KC_ESC,GUI_T(KC_ENT)}
},

/* Keymap 2: Lower (symbols and Functions)
  |---+-------+-----+-----+-----+-------+-------+-----+------+-------+-----+------|
  | [ | !     | @   | #   | $   | %     | ^     | &   | *    | =     | +   | {    |
  |---+-------+-----+-----+-----+-------+-------+-----+------+-------+-----+------|
  | ] | `     | ~   | -   | \   | (     | )     | /   | _    | \vert | ?   | }    |
  |---+-------+-----+-----+-----+-------+-------+-----+------+-------+-----+------|
  |   | F1    | F2  | F3  | F4  | F5    | F6    | F7  | F8   | F9    | F10 |      |
  |---+-------+-----+-----+-----+-------+-------+-----+------+-------+-----+------|
  |   | Reset |     |     |     | Space | Space |     | Home | PgDn  | End | PgUp |
  |---+-------+-----+-----+-----+-------+-------+-----+------+-------+-----+------|
*/

[_LW] = { /* LOWER */
  {KC_LBRC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL, KC_PLUS, KC_LCBR},
  {KC_RBRC, LSFT(KC_SLSH),KC_TILD, KC_MINS, KC_BSLS, KC_LPRN, KC_RPRN, KC_SLSH, KC_UNDS, KC_PIPE, KC_GRV, KC_RCBR},
  {KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7, KC_F8, KC_F9, KC_F10,   KC_TRNS},
  {KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END, KC_PGUP}
},

/* Keymap 3: Raise (numbers and remaining function; [TODO] improve)
  |---+-------+-----+-----+-----+-------+-------+-----+-----+-----+-----+-----|
  |   | 1     | 2   | 3   | 4   | 5     | 6     | 7   | 8   | 9   | 0   |     |
  |---+-------+-----+-----+-----+-------+-------+-----+-----+-----+-----+-----|
  |   | 1     | 2   | 3   | 4   | 5     | 6     | 7   | 8   | 9   | 0   | -   |
  |---+-------+-----+-----+-----+-------+-------+-----+-----+-----+-----+-----|
  |   | F11   | F12 |     |     |       |       |     |     |     |     |     |
  |---+-------+-----+-----+-----+-------+-------+-----+-----+-----+-----+-----|
  |   | Reset |     |     |     | Space | Space |     |     |     |     |     |
  |---+-------+-----+-----+-----+-------+-------+-----+-----+-----+-----+-----|
*/

[_RS] = { /* RAISE */
  {KC_TRNS,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_TRNS},
  {KC_TRNS, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7, KC_8,  KC_9, KC_0, KC_MINS},
  {KC_TRNS, KC_F11,   KC_F12,   KC_N,   KC_TRNS,  KC_BSPC,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RSFT},
  {KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},

/* Keymap 4: Media / Mouse
  |------+--------+-------+--------+---------+------+------+---------+-----+----------+------+-----------|
  |      |        | Mclk  | MUp    | WhRight |      |      | ↓       |     | ↑        |      | BackSpace |
  |------+--------+-------+--------+---------+------+------+---------+-----+----------+------+-----------|
  |      | WhLeft | MLeft | MDown  | MRight  |      |      | Play    |     | Previous | Next | -         |
  |------+--------+-------+--------+---------+------+------+---------+-----+----------+------+-----------|
  |      |        |       | WhDown | WhUp    |      |      | VolDown |     | VolUp    |      |           |
  |------+--------+-------+--------+---------+------+------+---------+-----+----------+------+-----------|
  | Rclk |        |       |        | Bkwd    | Lclk | Lclk | Fwd     |     |          |      | Mute      |
  |------+--------+-------+--------+---------+------+------+---------+-----+----------+------+-----------|
*/

[_MD] = { /* MEDIA */
  {KC_TRNS, KC_TRNS, KC_BTN3, KC_MS_U, KC_MS_WH_RIGHT, KC_TRNS, KC_TRNS, KC_DOWN, KC_TRNS, KC_UP, KC_TRNS, KC_BSPC},
  {KC_TRNS, KC_MS_WH_LEFT, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_MPLY, KC_TRNS, KC_MPRV, KC_MNXT, KC_MINS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_TRNS, KC_TRNS, KC_VOLD, KC_TRNS, KC_VOLU, KC_TRNS, KC_TRNS},
  {KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_WBAK, KC_BTN1, KC_BTN1, KC_WFWD, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE}
},

/* Keymap 5: Arrows
  |------+--------+-------+--------+---------+------+------+---------+-----+-------+------+-----------|
  |      |        |       |        |         |      |      |  PgDwn  |  Up | PgUp  |      |           |
  |------+--------+-------+--------+---------+------+------+---------+-----+-------+------+-----------|
  |      |        |       |        |         |      |      |   Left  | Down| Right |      |           |
  |------+--------+-------+--------+---------+------+------+---------+-----+-------+------+-----------|
  |      |        |       |        |         |      |      |   Home  |     | End   |      |           |
  |------+--------+-------+--------+---------+------+------+---------+-----+-------+------+-----------|
  |      |        |       |        |         |      |      |         |     |       |      |           |
  |------+--------+-------+--------+---------+------+------+---------+-----+-------+------+-----------|
*/

[_MV] = { /* MOVING */
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PGDN,  KC_UP,    KC_PGUP,  KC_TRNS,  KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_TRNS,  KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_HOME,  KC_TRNS,   KC_END,  KC_TRNS,  KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS}
}
};

/* id for user defined functions & macros */
enum function_id {
    TEENSY_KEY,
    CUSTOM_KEY,
    L_CTRL_ALT_ENT,
    R_CTRL_ALT_ENT,
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            backlight_step();
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
