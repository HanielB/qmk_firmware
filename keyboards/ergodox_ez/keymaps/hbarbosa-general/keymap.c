#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

/* time of "tapping" is set by "TAPPING_TERM" in config.h */

extern keymap_config_t keymap_config;

// Custom Keycodes
enum planck_keycodes {
  DVORAK = SAFE_RANGE,
  LOWER,
  RAISE,
};

// Fillers to make layering more clear
#define _______       KC_TRNS
#define XXXXXXX       KC_NO

#define _DV 0
#define _DV_CTRL 1
#define _LW 2
#define _RS 3
#define _MV 4
#define _LW_CTRL 6
#define _RS_CTRL 7
#define _MS 8
#define _MS_R 9
#define _GM 10

#define ALT_TAB       ALT_T(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: Dvorak */
  [_DV] = LAYOUT_ergodox(
                 KC_GRV,      KC_1,    KC_2,    KC_3,          KC_4,    KC_5, TG(_MV),
                 KC_BSPC,     KC_QUOT, KC_COMM, KC_DOT,        KC_P,    KC_Y, TG(_DV_CTRL),
                 KC_CAPSLOCK, KC_A,    KC_O,    LT(_MS_R, KC_E), KC_U,    KC_I,
                 KC_LSFT,     KC_SCLN, KC_Q,    KC_J,          KC_K,    KC_X, KC_ENTER,
                 MO(_MV),     KC_RALT, KC_LALT, F(1),          LOWER ,

                         KC_DELT, ALT_T(KC_APP),
                                        KC_HOME,
                 CTL_T(KC_SPC), ALT_TAB, KC_END,

                 TG(_MV),    KC_6, KC_7, KC_8,          KC_9,  KC_0,  KC_BSLS,
                 TG(_DV_CTRL),    KC_F, KC_G, KC_C,          KC_R,  KC_L,  KC_BSPC,
                 KC_D, KC_H, LT(_MS, KC_T), KC_N,  KC_S,  KC_CAPSLOCK,
                 KC_ENTER, KC_B, KC_M, KC_W,          KC_V,  KC_Z,  KC_RSFT,
                 RAISE, F(1),          KC_NO, KC_NO, MO(_MV),

                 KC_RALT, KC_ESC,
                 KC_PGUP,
                 KC_PGDN, ALT_TAB, CTL_T(KC_SPC)
                 ),
  /* 1: Dvorak with "control" */
  [_DV_CTRL] = LAYOUT_ergodox(
                 _______, F(64), F(65), F(66), F(67), F(68), _______,
                 _______, F(69), F(70), F(71), F(72), F(73), _______,
                 _______, F(74), F(75), F(76), F(77), F(78),
                 _______, F(79), F(80), F(81), F(82), F(83), _______,
                 _______, _______,  _______,  _______, MO(_RS_CTRL),

                          _______, _______,
                                   _______,
                 _______, _______, _______,

                 _______, F(84), F(85),  F(86),  F(87),  F(88),  _______,
                 _______, F(89), F(90),  F(91),  F(92),  F(93),  _______,
                          F(94), F(95),  F(96),  F(97),  F(98),  _______,
                 _______, F(99), F(100), F(101), F(102), F(103), _______,
                 MO(_LW_CTRL), _______,_______,_______, _______,

                 _______, _______,
                 _______,
                 _______, _______, _______
                 ),
  /* 2: Lower */
  [_LW] = LAYOUT_ergodox(
                 KC_F11,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,              _______,
                 _______, KC_6  , KC_7   , KC_8   , KC_9   , KC_0,       _______,
                 _______, KC_1  , KC_2   , KC_3   , KC_4   , KC_5,
                 _______,_______,_______,  _______, _______, _______,           _______,
                 _______,_______,_______,_______,_______,

                 _______,_______,
                 _______,
                 _______,_______,_______,

                 _______, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F12,
                 _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL, KC_PLUS, _______,
                          KC_RPRN, KC_SLSH, KC_UNDS, KC_PIPE, KC_GRV, _______,
                 _______, _______, _______,   _______,    _______,    _______, _______,
                 RAISE  , _______, _______,    _______,  _______,

                 _______, _______,
                 _______,
                 _______, _______, _______
                 ),
  /* 3: Raise */
  [_RS] = LAYOUT_ergodox(
                 KC_F11,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  _______,
                 _______,KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,  _______,
                 _______,KC_QUES, KC_TILD, KC_MINS, KC_BSLS, KC_LPRN,
                 _______,_______,_______,KC_LBRC, KC_RBRC,_______,_______,
                 _______,_______,_______,_______,LOWER,

                 _______,_______,
                 _______,
                 _______,_______,_______,

                 _______, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F12,
                 _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5,  _______,
                          KC_6,   KC_7,  KC_8,   KC_9,   KC_0,  KC_MINS,
                 _______, _______, KC_LCBR, KC_RCBR,_______,_______, _______,
                 _______,_______,  _______, TO(_GM),  _______,

                 _______, _______,
                 _______,
                 _______, _______, _______
                 ),
  /* 4: Moving */
  [_MV] = LAYOUT_ergodox(
                 _______, _______, _______, _______, _______, _______, _______,
                 _______, KC_BSPC, KC_HOME, KC_UP  , KC_END , KC_PGUP, TG(_MS),
                 _______, KC_SPC , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
                 _______, KC_MPLY, KC_VOLD, KC_MPRV, KC_DEL , XXXXXXX, _______,
                 _______, _______, _______, _______, _______,

                 _______, _______,
                 _______,
                 _______, _______, _______,
                 // right hand
                 _______, _______, _______, _______, _______, _______, _______,
                 TG(_MS_R), KC_PGUP, KC_HOME, KC_UP  , KC_END , KC_BSPC, _______,
                          KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC , _______,
                 _______, XXXXXXX, KC_DEL , KC_MNXT, KC_VOLU, KC_MUTE, _______,
                          _______, _______, _______, _______, _______,

                 _______, _______,
                 _______,
                 _______, _______, _______
         ),

  /* 6: Lower with "control" */
  [_LW_CTRL] = LAYOUT_ergodox(
                 _______, F(144), F(145), F(146), F(147), F(148), _______,
                 _______, F(149), F(150), F(151), F(152), F(153), _______,
                 _______, F(154), F(155), F(156), F(157), F(158),
                 _______, F(159), F(160), F(161), F(162), F(163), _______,
                 _______, _______,  _______,  _______, _______,

                          _______, _______,
                                   _______,
                 _______, _______, _______,

                 _______, F(164), F(165), F(166), F(167), F(168),  _______,
                 _______, F(169), F(170), F(171), F(172), F(173),  _______,
                          F(174), F(175), F(176), F(177), F(178),  _______,
                 _______, F(179), F(180), F(181), F(182), F(183), _______,
                 _______, _______,_______,_______, _______,

                 _______, _______,
                 _______,
                 _______, _______, _______
                 ),
  /* 7: Raise with "control" */
  [_RS_CTRL] = LAYOUT_ergodox(
                 _______, F(104), F(105), F(106), F(107), F(108), _______,
                 _______, F(109), F(110), F(111), F(112), F(113), _______,
                 _______, F(114), F(115), F(116), F(117), F(118),
                 _______, F(119), F(120), F(121), F(122), F(123), _______,
                 _______, _______,  _______,  _______, _______,

                          _______, _______,
                                   _______,
                 _______, _______, _______,

                 _______, F(124), F(125), F(126), F(127), F(128),  _______,
                 _______, F(129), F(130), F(131), F(132), F(133),  _______,
                          F(134), F(135), F(136), F(137), F(138),  _______,
                 _______, F(139), F(140), F(141), F(142), F(143), _______,
                 _______, _______,_______,_______, _______,

                 _______, _______,
                 _______,
                 _______, _______, _______
                 ),
  /* 8: Media and mouse */
  [_MS] = LAYOUT_ergodox(
                 _______, _______,       _______, _______,       _______,         _______, TG(_MS),
                 _______, _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_BTN3, _______,
                 _______, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,
                 _______, _______, _______, KC_WH_D, KC_WH_U, _______, _______,
                 _______, _______,       _______, _______,       KC_WBAK,

                 _______, _______,
                 _______,
                 KC_BTN1, GUI_T(KC_BTN2), _______,

                 _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______,
                          _______, KC_ACL2, _______, KC_ACL1, KC_ACL0, _______,
                 _______, _______, _______, _______, _______, _______, _______,
                 KC_WFWD, _______, _______, _______, _______,

                 _______, _______,
                 _______,
                 _______, GUI_T(KC_BTN2), KC_BTN1
         ),
  /* 9: Media and mouse with right */
  [_MS_R] = LAYOUT_ergodox(
                 _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______,
                 _______, KC_ACL0, KC_ACL1, _______, KC_ACL2, _______,
                 _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, KC_WBAK,

                 _______, _______,
                 _______,
                 KC_BTN1, GUI_T(KC_BTN2), _______,

                 TG(_MS_R), _______,       _______,       _______,     _______,        _______, _______,
                 _______,   KC_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
                            KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, KC_BTN5,
                 _______,   _______,       KC_MS_WH_DOWN, KC_MS_WH_UP, _______,        _______, _______,
                 KC_WFWD,   _______,       _______,       _______,     _______,

                 _______, _______,
                 _______,
                 _______, GUI_T(KC_BTN2), KC_BTN1
         ),
  /* 10: Gaming */
  [_GM] = LAYOUT_ergodox(
                 KC_GRV,   KC_1,    KC_2,    KC_3,  KC_4,    KC_5, TG(_MV),
                 KC_BSPC,  KC_Q,    KC_W,    KC_E,  KC_R,    KC_T, KC_NO,
                 KC_CAPS,  KC_A,    KC_S,    KC_D,  KC_F,    KC_G,
                 KC_LSFT,  KC_Z,    KC_X,    KC_C,  KC_V,    KC_B, KC_ENTER,
                 KC_ENTER, KC_RALT, KC_LALT, F(1),  LOWER ,

                  KC_DELT, ALT_T(KC_APP),
                                 KC_HOME,
                 KC_LCTL, ALT_TAB, KC_END,

                 TG(_MV),  KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_BSLS,
                 KC_NO,    KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
                           KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_LGUI,
                 KC_ENTER, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                 RAISE,    F(1), KC_NO, TO(_DV), MO(_MV),

                 KC_RALT, KC_ESC,
                 KC_PGUP,
                 KC_PGDN, ALT_TAB, KC_SPC
                 ),

};

const uint16_t PROGMEM fn_actions[] = {
  /* Toggles with a tap; momentary when held. */
  [1] = ACTION_SWAP_HANDS_TAP_TOGGLE(),

  /* Dvorak with control hold, for main keys */
  [64]  = ACTION_MODS_KEY(MOD_LGUI, KC_1),
  [65]  = ACTION_MODS_KEY(MOD_LGUI, KC_2),
  [66]  = ACTION_MODS_KEY(MOD_LGUI, KC_3),
  [67]  = ACTION_MODS_KEY(MOD_LGUI, KC_4),
  [68]  = ACTION_MODS_KEY(MOD_LGUI, KC_5),

  [69]  = ACTION_MODS_KEY(MOD_LGUI, KC_QUOT),
  [70]  = ACTION_MODS_KEY(MOD_LGUI, KC_COMM),
  [71]  = ACTION_MODS_KEY(MOD_LGUI, KC_DOT),
  [72]  = ACTION_MODS_KEY(MOD_LGUI, KC_P),
  [73]  = ACTION_MODS_KEY(MOD_LGUI, KC_Y),

  [74]  = ACTION_MODS_KEY(MOD_LGUI, KC_A),
  [75]  = ACTION_MODS_KEY(MOD_LGUI, KC_O),
  [76]  = ACTION_MODS_KEY(MOD_LGUI, KC_E),
  [77]  = ACTION_MODS_KEY(MOD_LGUI, KC_U),
  [78]  = ACTION_MODS_KEY(MOD_LGUI, KC_I),

  [79]  = ACTION_MODS_KEY(MOD_LGUI, KC_SCLN),
  [80]  = ACTION_MODS_KEY(MOD_LGUI, KC_Q),
  [81]  = ACTION_MODS_KEY(MOD_LGUI, KC_J),
  [82]  = ACTION_MODS_KEY(MOD_LGUI, KC_K),
  [83]  = ACTION_MODS_KEY(MOD_LGUI, KC_X),

  [84]  = ACTION_MODS_KEY(MOD_LGUI, KC_6),
  [85]  = ACTION_MODS_KEY(MOD_LGUI, KC_7),
  [86]  = ACTION_MODS_KEY(MOD_LGUI, KC_8),
  [87]  = ACTION_MODS_KEY(MOD_LGUI, KC_9),
  [88]  = ACTION_MODS_KEY(MOD_LGUI, KC_0),

  [89]  = ACTION_MODS_KEY(MOD_LGUI, KC_F),
  [90]  = ACTION_MODS_KEY(MOD_LGUI, KC_G),
  [91]  = ACTION_MODS_KEY(MOD_LGUI, KC_C),
  [92]  = ACTION_MODS_KEY(MOD_LGUI, KC_R),
  [93]  = ACTION_MODS_KEY(MOD_LGUI, KC_L),

  [94]  = ACTION_MODS_KEY(MOD_LGUI, KC_D),
  [95]  = ACTION_MODS_KEY(MOD_LGUI, KC_H),
  [96]  = ACTION_MODS_KEY(MOD_LGUI, KC_T),
  [97]  = ACTION_MODS_KEY(MOD_LGUI, KC_N),
  [98]  = ACTION_MODS_KEY(MOD_LGUI, KC_S),

  [99]  = ACTION_MODS_KEY(MOD_LGUI, KC_B),
  [100] = ACTION_MODS_KEY(MOD_LGUI, KC_M),
  [101] = ACTION_MODS_KEY(MOD_LGUI, KC_W),
  [102] = ACTION_MODS_KEY(MOD_LGUI, KC_V),
  [103] = ACTION_MODS_KEY(MOD_LGUI, KC_Z),

  /* Raise with control hold, for main keys */
  [104] = ACTION_MODS_KEY(MOD_LGUI, KC_F1),
  [105] = ACTION_MODS_KEY(MOD_LGUI, KC_F2),
  [106] = ACTION_MODS_KEY(MOD_LGUI, KC_F3),
  [107] = ACTION_MODS_KEY(MOD_LGUI, KC_F4),
  [108] = ACTION_MODS_KEY(MOD_LGUI, KC_F5),

  [109] = ACTION_MODS_KEY(MOD_LGUI, KC_1),
  [110] = ACTION_MODS_KEY(MOD_LGUI, KC_2),
  [111] = ACTION_MODS_KEY(MOD_LGUI, KC_3),
  [112] = ACTION_MODS_KEY(MOD_LGUI, KC_4),
  [113] = ACTION_MODS_KEY(MOD_LGUI, KC_5),

  [114] = ACTION_MODS_KEY(MOD_LGUI, KC_1),
  [115] = ACTION_MODS_KEY(MOD_LGUI, KC_2),
  [116] = ACTION_MODS_KEY(MOD_LGUI, KC_3),
  [117] = ACTION_MODS_KEY(MOD_LGUI, KC_4),
  [118] = ACTION_MODS_KEY(MOD_LGUI, KC_5),

  [119] = ACTION_MODS_KEY(MOD_LGUI, KC_PERC),
  [120] = ACTION_MODS_KEY(MOD_LGUI, KC_CIRC),
  [121] = ACTION_MODS_KEY(MOD_LGUI, KC_LBRC),
  [122] = ACTION_MODS_KEY(MOD_LGUI, KC_RBRC),
  [123] = ACTION_MODS_KEY(MOD_LGUI, KC_TILD),

  [124] = ACTION_MODS_KEY(MOD_LGUI, KC_F6),
  [125] = ACTION_MODS_KEY(MOD_LGUI, KC_F7),
  [126] = ACTION_MODS_KEY(MOD_LGUI, KC_F8),
  [127] = ACTION_MODS_KEY(MOD_LGUI, KC_F9),
  [128] = ACTION_MODS_KEY(MOD_LGUI, KC_F10),

  [129] = ACTION_MODS_KEY(MOD_LGUI, KC_6),
  [130] = ACTION_MODS_KEY(MOD_LGUI, KC_7),
  [131] = ACTION_MODS_KEY(MOD_LGUI, KC_8),
  [132] = ACTION_MODS_KEY(MOD_LGUI, KC_9),
  [133] = ACTION_MODS_KEY(MOD_LGUI, KC_0),

  [134] = ACTION_MODS_KEY(MOD_LGUI, KC_6),
  [135] = ACTION_MODS_KEY(MOD_LGUI, KC_7),
  [136] = ACTION_MODS_KEY(MOD_LGUI, KC_8),
  [137] = ACTION_MODS_KEY(MOD_LGUI, KC_9),
  [138] = ACTION_MODS_KEY(MOD_LGUI, KC_0),

  [139] = ACTION_MODS_KEY(MOD_LGUI, KC_AMPR),
  [140] = ACTION_MODS_KEY(MOD_LGUI, KC_1),
  [141] = ACTION_MODS_KEY(MOD_LGUI, KC_2),
  [142] = ACTION_MODS_KEY(MOD_LGUI, KC_3),
  [143] = ACTION_MODS_KEY(MOD_LGUI, KC_BSLS),

  /* Lower with control hold, for main keys */
  [144] = ACTION_MODS_KEY(MOD_LGUI, KC_F1),
  [145] = ACTION_MODS_KEY(MOD_LGUI, KC_F2),
  [146] = ACTION_MODS_KEY(MOD_LGUI, KC_F3),
  [147] = ACTION_MODS_KEY(MOD_LGUI, KC_F4),
  [148] = ACTION_MODS_KEY(MOD_LGUI, KC_F5),

  [149] = ACTION_MODS_KEY(MOD_LGUI, KC_EXLM),
  [150] = ACTION_MODS_KEY(MOD_LGUI, KC_AT),
  [151] = ACTION_MODS_KEY(MOD_LGUI, KC_HASH),
  [152] = ACTION_MODS_KEY(MOD_LGUI, KC_DLR),
  [153] = ACTION_MODS_KEY(MOD_LGUI, KC_PERC),

  [154] = ACTION_MODS_KEY(MOD_LGUI, KC_SLSH),
  [155] = ACTION_MODS_KEY(MOD_LGUI, KC_TILD),
  [156] = ACTION_MODS_KEY(MOD_LGUI, KC_MINS),
  [157] = ACTION_MODS_KEY(MOD_LGUI, KC_BSLS),
  [158] = ACTION_MODS_KEY(MOD_LGUI, KC_LPRN),

  [159] = ACTION_MODS_KEY(MOD_LGUI, _______),
  [160] = ACTION_MODS_KEY(MOD_LGUI, _______),
  [161] = ACTION_MODS_KEY(MOD_LGUI, _______),
  [162] = ACTION_MODS_KEY(MOD_LGUI, _______),
  [163] = ACTION_MODS_KEY(MOD_LGUI, _______),

  [164] = ACTION_MODS_KEY(MOD_LGUI, KC_F6),
  [165] = ACTION_MODS_KEY(MOD_LGUI, KC_F7),
  [166] = ACTION_MODS_KEY(MOD_LGUI, KC_F8),
  [167] = ACTION_MODS_KEY(MOD_LGUI, KC_F9),
  [168] = ACTION_MODS_KEY(MOD_LGUI, KC_F10),

  [169] = ACTION_MODS_KEY(MOD_LGUI, KC_CIRC),
  [170] = ACTION_MODS_KEY(MOD_LGUI, KC_AMPR),
  [171] = ACTION_MODS_KEY(MOD_LGUI, KC_ASTR),
  [172] = ACTION_MODS_KEY(MOD_LGUI, KC_EQL),
  [173] = ACTION_MODS_KEY(MOD_LGUI, KC_PLUS),

  [174] = ACTION_MODS_KEY(MOD_LGUI, KC_RPRN),
  [175] = ACTION_MODS_KEY(MOD_LGUI, KC_SLSH),
  [176] = ACTION_MODS_KEY(MOD_LGUI, KC_UNDS),
  [177] = ACTION_MODS_KEY(MOD_LGUI, KC_PIPE),
  [178] = ACTION_MODS_KEY(MOD_LGUI, KC_GRV),

  [179] = ACTION_MODS_KEY(MOD_LGUI, _______),
  [180] = ACTION_MODS_KEY(MOD_LGUI, _______),
  [181] = ACTION_MODS_KEY(MOD_LGUI, _______),
  [182] = ACTION_MODS_KEY(MOD_LGUI, _______),
  [183] = ACTION_MODS_KEY(MOD_LGUI, _______)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
  case 0:
    if (record->event.pressed) {
      register_code(KC_RSFT);
      /* backlight_step(); */
    } else {
      unregister_code(KC_RSFT);
    }
    break;
  }
  return MACRO_NONE;
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

static bool inverted_l = false;
static bool inverted_r = false;

// Process KeyPress
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case LOWER:
    if (record->event.pressed)
      {
        layer_on(_LW);
        if (IS_LAYER_ON(_RS))
          {
            layer_off(_RS);
            inverted_r = true;
          }
        /* update_tri_layer(_LW, _RS, _NEXUS); */
      }
    else
      {
        layer_off(_LW);
        inverted_l = false;
        if (inverted_r)
          {
            layer_on(_RS);
            inverted_r = false;
          }
        /* update_tri_layer(_LW, _RS, _NEXUS); */
      }
    return false;
    break;
  case RAISE:
    if (record->event.pressed)
      {
        layer_on(_RS);
        if (IS_LAYER_ON(_LW))
          {
            layer_off(_LW);
            inverted_l = true;
          }
        /* update_tri_layer(_LW, _RS, _NEXUS); */
      }
    else
      {
        layer_off(_RS);
        inverted_r = false;
        if (inverted_l)
          {
            layer_on(_LW);
            inverted_l = false;
          }
        /* update_tri_layer(_LW, _RS, _NEXUS); */
      }
    return false;
    break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 4:
            ergodox_right_led_3_on();
            break;
        case 5:
            ergodox_right_led_2_on();
            break;
        case 8:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_board_led_on();
            break;
        case 9:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
