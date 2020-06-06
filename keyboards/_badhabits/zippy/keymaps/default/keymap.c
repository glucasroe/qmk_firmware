#include QMK_KEYBOARD_H


#define _BASE 0
#define _RAISE 1
#define _LOWER 2

// Fillers to make layering more clear

#define ____ KC_TRNS

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)

*/

[_BASE] = LAYOUT( \
  KC_Q, KC_W, KC_E,    KC_R,    KC_T,                                       KC_Y, KC_U,    KC_I,    KC_O,   KC_P,              \
  KC_A, KC_S, KC_D,    KC_F,    KC_G,                                       KC_H, KC_J,    KC_K,    KC_L,   KC_SCLN,           \
  LT(RAISE,KC_Z), KC_X, KC_C,    KC_V,    KC_B,                            KC_N, KC_M,    KC_COMM, KC_DOT, LT(LOWER, KC_QUOT), \
              CTL_T(KC_ESC), ALT_T(KC_GRV),                                RALT_T(KC_MINS), RCTL_T(KC_EQL),                    \
                      GUI_T(KC_SPC), LSFT_T(KC_BSPC),              RSFT_T(KC_TAB), RCMD_T(KC_ENT),                                                \

),

/* Raise */

[_RAISE] = LAYOUT( \
  ____, ____,  KC_MU, ____,  ____,                          KC_VOLU, ____,    KC_UP,   ____,     KC_PGUP,   \
  ____, KC_ML, KC_MD, KC_MR, ____,                          KC_MUTE, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDOWN, \
  ____, ____,  ____,  KC_LBRC, KC_RBRC,                     KC_VOLD, KC_SLSH, KC_BSLS, KC_QUES,  KC_PIPE,   \
        ____,  ____,                                                          KC_MB1,  KC_MB2,              \
                                   ____, ____,  ____, ____,                                                 \
),
/* Lower */

[_LOWER] = LAYOUT( \
  KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,                            KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  \
  KC_1,    KC_2,   KC_3,    KC_4,   KC_5,                             KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    \
  KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC,                          KC_CIRC, KC_AMPR,  KC_ASTR, ____, ____, \
           KC_F11, KC_F12,                                                               KC_LPRN,    KC_RPRN,             \
                                             ____, ____,  ____, ____,                                               \
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
