// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.
#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "backlight.h"

extern keymap_config_t keymap_config;

// Custom Keycodes
enum planck_keycodes {
  DVORAK = SAFE_RANGE,
  LOWER,
  RAISE,
};

enum funcs_keycodes {
  FN_SWAP_SPACE,
  FN_TGGL_ONHND,
};

/* time of "tapping" is set by "TAPPING_TERM" in config.h */

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DV       0
/* #define _DVORAK_CTRL  1 */
#define _ONEHAND      3
#define _LOWER        4
#define _RAISE        5
#define _MOUSE        6
#define _LFTMOUSE     8
#define _BOTHMOUSE     9
#define _MOVE         10
#define _GAME         11
#define _UTIL         12
#define _NEXUS        16

// Fillers to make layering more clear
#define _______       KC_TRNS
#define XXXXXXX       KC_NO

// Momentary layer
#define UTIL          MO(_UTIL)

// Layer on hold, Kc on Tap
#define LT_MV(kc)     LT(_MOVE, kc)
#define LT_MS(kc)     LT(_MOUSE, kc)

// Layer Toggle
#define TG_OHND       TG(_ONEHAND)
#define TG_MOVE       TG(_MOVE)
#define TG_BMOS       TG(_BOTHMOUSE)

#define SFT_DEL       SFT_T(KC_DELT)
#define SFT_ENT       SFT_T(KC_ENT)
#define GUI_ENT       GUI_T(KC_ENT)
#define CTL_TAB       CTL_T(KC_TAB)
#define ALT_TAB       ALT_T(KC_TAB)
#define CTL_ENT       CTL_T(KC_ENT)

#define SWP_HND       F(FN_SWAP_SPACE)
#define TPTG_OH       F(FN_TGGL_ONHND)

#define MV_SPC        LT_MV(KC_SPC)
#define MV_Z          LT_MV(KC_Z)
#define MV_SCLN       LT_MV(KC_SCLN)

#define MOUSE         MO(_MOUSE)
#define LFMOUSE       MO(_LFTMOUSE)

// IN CASE YOU WANT TO GO BACK TO THE OLD LAYERS, USE THIS!!!
#define KC_MV_E       LT_MV(KC_E) //Hold for navigation, tap for E
#define KC_MS_T       LT_MS(KC_T) //Hold for mouse, tap for T


/* See https://gist.github.com/pocketkk/ab50ff5012b8bf779d6267047e0e6bbc for 8
   layers, left-hand chording and right-hand picking (??) */

  const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Dvorak for Emacs
       +========+========+========+========+========+========+========+========+========+========+========+========+
       | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
       +========+========+========+========+========+========+========+========+========+========+========+========+
       | Bksp   | '      | ,      | .      | P      | Y      | F      | G      | C      | R      | L      | Bksp   |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       | CapsL  | A      | O      | E      | U      | I      | D      | H      | T      | N      | S      | CapsL  |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       | LShift | ;      | Q      | J      | K      | X      | B      | M      | W      | V      | Z      | En/Sh  |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       | En/Gui | RAlt   | OneHnd | Tb/Ctl | Lower  | SpcNav | SpcNav | Raise  | Tb/Ctl | Util   | Esc    | En/Gui |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    */
    [_DV] = {
      { KC_BSPC, KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   , KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_BSPC},
      { KC_CAPS, KC_A   , KC_O   , LT(_MOUSE, KC_E)   , KC_U   , KC_I   , KC_D   , KC_H   , LT(_LFTMOUSE, KC_T), KC_N   , KC_S   , KC_LGUI},
      { KC_LSFT, KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   , KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , SFT_ENT},
      { CTL_ENT , KC_RALT, TG_MOVE, ALT_TAB, LOWER  , MV_SPC , MV_SPC , RAISE, ALT_TAB, TG_MOVE, KC_ESC, CTL_ENT}
    },

    /* One Hand Layer - Dvorak
       +========+========+========+========+========+========+========+========+========+========+========+========+
       | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
       +========+========+========+========+========+========+========+========+========+========+========+========+
       |        |        |        |        |        |        |        |        |        |        |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        |        |        |        |        |        |        |        |        |        |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        | Nav/;  |        |        |        |        |        |        |        |        | Nav/Z  |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        |        |        |        |        | SpcSwp | SpcSwp |        |        | >>><<< |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    */
    [_ONEHAND] = {
      { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
      { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
      { _______, MV_SCLN, _______, _______, _______, _______, _______, _______, _______, _______, MV_Z   , _______},
      { _______, _______, _______, _______, _______, SWP_HND, SWP_HND, _______, _______, TG_OHND, _______, _______}
    },

    /* Lower
       +========+========+========+========+========+========+========+========+========+========+========+========+
       | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
       +========+========+========+========+========+========+========+========+========+========+========+========+
       |        | 6      | 7      | 8      | 9      | 0      | ^      | &      | *      | =      | +      |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        | 1      | 2      | 3      | 4      | 5      | )      | /      | _      | \vert  | `      |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       | F11    | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F19    | F10    | F12    |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        | Reset  |        |        | >>><<< | LFMouse| LFMouse|        |        |        |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    */
    [_LOWER] = {
      { _______, KC_6  , KC_7   , KC_8   , KC_9   , KC_0   , KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL , KC_PLUS, _______},
      { _______, KC_1  , KC_2   , KC_3   , KC_4   , KC_5   , KC_RPRN, KC_SLSH, KC_UNDS, KC_PIPE, KC_GRV , _______},
      { KC_F11 , KC_F1 , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F12 },
      { _______, RESET , _______, _______, _______, TG_BMOS, TG_BMOS, RAISE  , _______, _______, _______, _______}
    },

    /* Raise
       +========+========+========+========+========+========+========+========+========+========+========+========+
       | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
       +========+========+========+========+========+========+========+========+========+========+========+========+
       |        | !      | @      | #      | $      | %      | 1      | 2      | 3      | 4      | 5      |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        | ?      | ^      | -      | \      | (      | 6      | 7      | 8      | 9      | 0      |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        |        |        |        |        |        |        |        |        |        |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        | Reset  |        |        |        | Mouse  | Mouse  | >>><<< |        |        |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    */
    [_RAISE] = { /* RAISE */
      { _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______},
      { _______, KC_QUES, KC_TILD, KC_MINS, KC_BSLS, KC_LPRN, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______},
      { _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, KC_LCBR, KC_RCBR, _______, _______, _______},
      { _______, RESET  , _______, _______, LOWER  , TG_BMOS, TG_BMOS, _______, _______, _______, _______, _______}
    },

    /* Move
       +========+========+========+========+========+========+========+========+========+========+========+========+
       | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
       +========+========+========+========+========+========+========+========+========+========+========+========+
       |        | Bksp   | Home   | Up     | End    | Insert | Insert | Home   | Up     | End    | Bksp   |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        | Spc    | Right  | Down   | Left   | PgUp   | PgUp   | Left   | Down   | Right  | Spc    |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        |        |        |        | Del    | PgDown | PgDown | Del    |        |        |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        |        |        |        |        | >>><<< | >>><<< |        |        |        |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    */
    [_MOVE] = {
      { _______, KC_BSPC, KC_HOME, KC_UP  , KC_END , KC_PGUP, KC_PGUP, KC_HOME, KC_UP  , KC_END , KC_BSPC, _______},
      { _______, KC_SPC , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC , _______},
      { _______, KC_MPLY, KC_VOLD, KC_MPRV, KC_DEL , XXXXXXX, XXXXXXX, KC_DEL , KC_MNXT, KC_VOLU, KC_MUTE, _______},
      { _______, _______, _______, _______, _______, TO(_DV), TO(_DV), _______, _______, _______, _______, _______}
    },

    /* Mouse Layer
       +========+========+========+========+========+========+========+========+========+========+========+========+
       | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
       +========+========+========+========+========+========+========+========+========+========+========+========+
       |        |        |        |        |        |        |        |        | Up     | WhlRgt | Btn2   |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        |        | >>><<< |        |        |        |        | Left   | Down   | Right  |        | Btn5   |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        |        |        |        |        |        |        |        |        |        |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        |        |        |        |        | >>><<< | >>><<< |        |        |        |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    */
    [_MOUSE] = {
      { _______, _______, _______, _______, _______, _______, KC_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______},
      { _______, _______, _______, _______, _______, _______, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, KC_BTN5},
      { _______, _______, _______, _______, _______, _______, KC_WFWD, KC_WH_D, KC_WH_U, KC_WBAK, _______, _______},
      { KC_BTN1, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1}
      /* { KC_BTN1, _______, _______, _______, _______, MOUSE  , MOUSE  , _______, _______, _______, _______, KC_BTN1} */
    },

    /* Left Mouse Layer
       +========+========+========+========+========+========+========+========+========+========+========+========+
       | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
       +========+========+========+========+========+========+========+========+========+========+========+========+
       |        |        | WhlLft | Up     | WhlRgt | Btn2   |        |        |        |        |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        | >>><<< | Left   | Down   | Right  | WhlUp  |        |        | >>><<< |        |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        |        |        | Btn3   | Btn1   | WhlDwn |        |        |        |        |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        |        |        |        |        | >>><<< | >>><<< |        |        |        |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    */
    [_LFTMOUSE] = {
      { _______, _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_BTN3, _______, _______, _______, _______, _______, _______},
      { _______, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, _______, _______, _______, _______, _______, _______},
      { _______, _______, KC_WBAK, KC_WH_D, KC_WH_U, KC_WFWD, _______, _______, _______, _______, _______, _______},
      { KC_BTN1, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1}
    },


    /* Both Mouse Layer
       +========+========+========+========+========+========+========+========+========+========+========+========+
       | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
       +========+========+========+========+========+========+========+========+========+========+========+========+
       |        |        | WhlLft | Up     | WhlRgt | Btn2   |        |        | Up     | WhlRgt | Btn2   |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        | >>><<< | Left   | Down   | Right  | WhlUp  |        | Left   | Down   | Right  |        | Btn5   |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        |        |        | Btn3   | Btn1   | WhlDwn |        |        |        |        |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        |        |        |        |        | >>><<< | >>><<< |        |        |        |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    */
    [_BOTHMOUSE] = {
      { _______, _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_BTN3, KC_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______},
      { _______, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, KC_BTN5},
      { _______, _______, KC_WBAK, KC_WH_D, KC_WH_U, KC_WFWD, KC_WFWD, KC_WH_D, KC_WH_U, KC_WBAK, _______, _______},
      { KC_BTN1, _______, _______, _______, _______, TO(_DV), TO(_DV), _______, _______, _______, _______, KC_BTN1}
    },

    /* Util layer
       +========+========+========+========+========+========+========+========+========+========+========+========+
       | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
       +========+========+========+========+========+========+========+========+========+========+========+========+
       |        |        | Calc   | MyComp |        |        |        |        | WebRfr | WebFav |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        | WebBck | WebHom | Cut    | Copy   | Paste  | Undo   | Find   | Mail   | WebStp | WebFwd |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        | Power  |        |        |        |        |        |        |        |        |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        | Sleep  | Wake   |        |        |        |        |        |        | >>><<< |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    */
    [_UTIL] = {
      { XXXXXXX, XXXXXXX, KC_CALC, KC_MYCM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WREF, KC_WFAV, XXXXXXX, XXXXXXX},
      { XXXXXXX, KC_WBAK, KC_WHOM, KC_CUT , KC_COPY, KC_PAST, KC_UNDO, KC_FIND, KC_MAIL, KC_WSTP, KC_WFWD, XXXXXXX},
      { XXXXXXX, KC_PWR , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
      { XXXXXXX, KC_SLEP, KC_WAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX}
    },

    [_GAME] = { /* GAMING */
      { KC_BSPC, KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   , KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_BSPC},
      { KC_CAPS, KC_A   , KC_O   , KC_E   , KC_U   , KC_I   , KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_CAPS},
      { KC_LSFT, KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   , KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , KC_RSFT},
      { KC_ENT , KC_RALT, TG(0)  , KC_LCTL, RAISE  , KC_SPC , KC_SPC , LOWER  , KC_TAB , TG(0)  , KC_ESC , KC_ENT }
    },

    /* Nexus (Lower + Raise)
       +========+========+========+========+========+========+========+========+========+========+========+========+
       | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
       +========+========+========+========+========+========+========+========+========+========+========+========+
       | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        | Mute   | Vol -  | Vol +  | Prev   | QWERTY | DVORAK | Next   | Play   | Rwd    | Fwd    |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        | OSX    | Win    |        |        | AGnorm | AGswap |        |        | Game   | Linux  |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
       |        |        | Reset  |        | >>><<< |        |        | >>><<< |        |        |        |        |
       +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    */
    [_NEXUS] = {
      { KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 },
      { _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, XXXXXXX, XXXXXXX, KC_MNXT, KC_MPLY, KC_MRWD, KC_MFFD, _______},
      { _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AG_NORM, AG_SWAP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______},
      { _______, _______, RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______}
    }

  };

const uint16_t PROGMEM fn_actions[] = {
  [FN_SWAP_SPACE] = ACTION_SWAP_HANDS_TAP_KEY(KC_SPC),
  [FN_TGGL_ONHND] = ACTION_LAYER_TAP_TOGGLE(_ONEHAND),
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
        layer_on(_LOWER);
        if (IS_LAYER_ON(_RAISE))
          {
            layer_off(_RAISE);
            inverted_r = true;
          }
        /* update_tri_layer(_LOWER, _RAISE, _NEXUS); */
      }
    else
      {
        layer_off(_LOWER);
        inverted_l = false;
        if (inverted_r)
          {
            layer_on(_RAISE);
            inverted_r = false;
          }
        /* update_tri_layer(_LOWER, _RAISE, _NEXUS); */
      }
    return false;
    break;
  case RAISE:
    if (record->event.pressed)
      {
        layer_on(_RAISE);
        if (IS_LAYER_ON(_LOWER))
          {
            layer_off(_LOWER);
            inverted_l = true;
          }
        /* update_tri_layer(_LOWER, _RAISE, _NEXUS); */
      }
    else
      {
        layer_off(_RAISE);
        inverted_r = false;
        if (inverted_l)
          {
            layer_on(_LOWER);
            inverted_l = false;
          }
        /* update_tri_layer(_LOWER, _RAISE, _NEXUS); */
      }
    return false;
    break;
  }
  return true;
}
