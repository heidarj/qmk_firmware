#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"



enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  POWERSHELL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ergodox(
    KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, TO(1),
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_HOME,
    KC_CAPSLOCK, KC_A, KC_S, KC_D, KC_F, KC_G,
    KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_END,
    KC_LCTL, KC_LGUI, KC_LALT, KC_RALT, MO(2),

    KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK,
    KC_GRAVE,
    KC_SPACE,
    KC_BSPACE,
    POWERSHELL,

    KC_ESCAPE, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS,
    KC_PGUP, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLASH,
    KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
    KC_PGDOWN, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT,
    MO(3), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,

    KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,
    KC_MEDIA_PLAY_PAUSE,
    KC_CALCULATOR,
    KC_ENTER,
    KC_SPACE
  ),

  [1] = LAYOUT_ergodox(
    KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, TO(0),
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_HOME,
    KC_CAPSLOCK, KC_A, KC_S, KC_D, KC_F, KC_G,
    KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_END,
    KC_LCTL, KC_LGUI, KC_LALT, KC_RALT, MO(2),

    KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK,
    KC_GRAVE,
    KC_SPACE,
    KC_BSPACE,
    POWERSHELL,

    KC_ESCAPE, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS,
    KC_PGUP, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRACKET,
    KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
    KC_PGDOWN, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT,
    MO(3), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,

    KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,
    KC_MEDIA_PLAY_PAUSE,
    KC_CALCULATOR,
    KC_ENTER,
    KC_SPACE
  ),

  [2] = LAYOUT_ergodox(KC_ESCAPE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_PSCREEN,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_TRANSPARENT,KC_LSHIFT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MINUS,KC_EQUAL,KC_DELETE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LBRACKET,KC_RBRACKET,KC_BSLASH,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LBRACKET,KC_RBRACKET,KC_ENTER,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [3] = LAYOUT_ergodox(KC_TRANSPARENT,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_UP,KC_MS_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN1,KC_MS_BTN2,KC_TRANSPARENT,KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_TRANSPARENT,KC_TRANSPARENT,KC_7,KC_8,KC_9,KC_TRANSPARENT,KC_F12,KC_TRANSPARENT,KC_4,KC_5,KC_6,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_0,KC_1,KC_2,KC_3,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RESET,KC_TRANSPARENT,KC_TRANSPARENT),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
    case POWERSHELL:
      if (record->event.pressed) {
        SEND_STRING (SS_DOWN(X_LGUI));
        SEND_STRING ("r");
        SEND_STRING (SS_UP(X_LGUI));
        SEND_STRING ("powershell.exe");
        SEND_STRING (SS_TAP(X_ENTER));
      }
      return false;
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;

};
