#include "planck.h"
#include "action_layer.h"
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers
{
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum planck_keycodes
{
    QWERTY = SAFE_RANGE,
    EXT_PLV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |rotary|   Q  |   W  |   E  |   0  |   1  |   4  |   7  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |lifes.|   A  |   S  |   D  |   0  |   2  |   5  |   8  |   /  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | wheel|   Z  |   X  |   C  |   .  |   3  |   6  |   9  |   *  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |lhouse|  \   | GUI  | Alt  |     Enter   |     Plus    |   -  | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
    [_QWERTY] = LAYOUT_planck_grid(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_P0,   KC_P1,   KC_P4,   KC_P7,   KC_NLCK,    KC_O,    KC_P,    KC_MINS,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_P0,   KC_P2,   KC_P5,   KC_P8,   KC_PSLS, KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_PDOT, KC_P3,   KC_P6,   KC_P9,   KC_PAST, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_BSLS, KC_LGUI, KC_LALT, KC_PENT, KC_PENT, KC_PPLS, KC_PPLS, KC_PMNS, KC_DOWN, KC_UP,   KC_RGHT),

    /* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  | Left | Down |  Up  |Right |      |      |      |   +  |   [  |   ]  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |BKSPC |Enter |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
    [_LOWER] = LAYOUT_planck_grid(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_DEL, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______, _______, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END, _______,
        _______, _______, _______, _______, _______, KC_BSPC, KC_ENT, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

    /* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      |      |      |      |      |      |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |   0  |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |BKSPC |Enter |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
    [_RAISE] = LAYOUT_planck_grid(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_DEL, _______, _______, _______, _______, _______, _______, KC_4, KC_5, KC_6, _______, _______,
        KC_LSFT, _______, _______, _______, _______, _______, KC_0, KC_1, KC_2, KC_3, _______, _______,
        _______, _______, _______, _______, _______, KC_BSPC, KC_ENT, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

    /* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Reset|      |Aud on|Audoff|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    [_ADJUST] = LAYOUT_planck_grid(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        _______, RESET, MU_MOD, AU_ON, AU_OFF, _______, _______, _______, _______, _______, _______, _______,
        _______, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
    case QWERTY:
        if (record->event.pressed)
        {
            print("mode just switched to qwerty and this is a huge string\n");
            set_single_persistent_default_layer(_QWERTY);
        }
        return false;
    }
    return true;
}

void encoder_update(bool clockwise)
{
    if (clockwise)
    {
        register_code(KC_AUDIO_VOL_UP);
        wait_ms(10);
        unregister_code(KC_AUDIO_VOL_UP);
    }
    else
    {
        register_code(KC_AUDIO_VOL_DOWN);
        wait_ms(10);
        unregister_code(KC_AUDIO_VOL_DOWN);
    }
}
