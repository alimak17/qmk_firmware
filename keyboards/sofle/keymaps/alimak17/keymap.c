 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include QMK_KEYBOARD_H
#include "oled.c"
#include "encoder.c"

//Default keymap. This can be changed in Via. Use oled.c and encoder.c to change beavior that Via cannot change.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY with home row
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | TG(1)| TG(2)| /Enter| Caps  | /Space  /       \Space \  |RAISE |/Bspc | Caps | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[0] = LAYOUT(
  KC_GRV,    KC_1,                KC_2,                KC_3,               KC_4,               KC_5,                             KC_6,               KC_7,                KC_8,               KC_9,                KC_0,               KC_GRV,
  KC_ESC,    KC_Q,                KC_W,                KC_E,               KC_R,               KC_T,                             KC_Y,               KC_U,                KC_I,               KC_O,                KC_P,               KC_BSPC,
  KC_TAB,    KC_A,                KC_S,                KC_D,               KC_F,               KC_G,                             KC_H,               KC_J,                KC_K,               KC_L,                KC_SCLN,            KC_QUOT,
  KC_LSFT,   MT(MOD_LGUI, KC_Z),  MT(MOD_LCTL, KC_X),  MT(MOD_LALT, KC_C), MT(MOD_LSFT, KC_V), KC_B,      KC_MUTE,          XXXXXXX,  KC_N,               MT(MOD_LSFT, KC_M), MT(MOD_LALT, KC_COMM), MT(MOD_LCTL, KC_DOT), MT(MOD_LGUI, KC_SLSH), KC_RSFT,
                         TG(1),   TG(2),               LT(2, KC_ENT),      KC_CAPS,            LT(3, KC_SPC),               LT(3, KC_SPC),      KC_CAPS,             LT(2, KC_BSPC),      KC_RALT,             KC_RGUI
),
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |  F4  |  F5  |  F6  |  F7  |  F8  |                    |   Y  |   U  |  Up  |   O  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   ;  |  F4  |   W  |Shift |   G  |-------.    ,-------|   H  | Left | Down | Right|   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   I  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | TG(1)| LAlt | LCTR | Enter | Space   /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */

[1] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
  KC_ESC,   KC_F4,  KC_F5,   KC_F6,   KC_F7,   KC_F8,                    KC_Y,    KC_U,   KC_UP,    KC_O, KC_SCLN,  KC_BSPC,
  KC_TAB, KC_SCLN,  KC_F4,    KC_W, KC_LSFT,    KC_G,                    KC_H, KC_LEFT, KC_DOWN, KC_RGHT,   KC_O,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_I, KC_MUTE,      XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                    TG(1),KC_LALT,KC_LCTL, KC_ENT, KC_SPC,      KC_SPC,  KC_TRNS, KC_RCTL, KC_RALT, KC_RGUI
),

/* RAISE optimized for Dvorak layout
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   <  |   &  |   *  | =/+  |   [  |                    |   ]  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   -  |   !  |   @  |   #  |   (  |-------.    ,-------|   )  |   4  |   5  |   6  |  \/| |   /  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|   >  |   $  |   %  |   ^  |   {  |-------|    |-------|   }  |   1  |   2  |   3  |   ?  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE |  0   | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[2] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  KC_GRV,    S(KC_W),  KC_AMPR,   KC_ASTR,  KC_RBRC,  KC_MINS,                KC_EQL,  KC_7,    KC_8,    KC_9, KC_RBRC,  KC_F12,
  _______,   KC_QUOT,   KC_EXLM, KC_AT,  KC_HASH, S(KC_9),                    S(KC_0), KC_4,    KC_5,    KC_6,    KC_BSLS, KC_LBRC,
  _______,  S(KC_E), KC_DLR, KC_PERC, KC_CIRC, S(KC_MINS), _______,       _______, S(KC_EQL), MT(MOD_LSFT,KC_P1), MT(MOD_LALT,KC_P2), MT(MOD_LCTL,KC_P3), S(KC_LBRC), _______,
                       _______, _______, _______, _______, _______,       _______, _______, _______, KC_0, _______
),
/* LOWER
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |  ‚   |  ‘   |  ’   |  „   |  “   |  ”   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |   |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |--------|   |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[3] = LAYOUT(
  S(LGUI(KC_0)),      LGUI(KC_EQL),   S(LGUI(KC_EQL)),      S(LGUI(KC_COMM)), LGUI(KC_MINS),    S(LGUI(KC_MINS)),             _______,  _______,  _______,  _______,  _______,  _______,
  _______,           KC_INS,        KC_PSCR,              KC_APP,          XXXXXXX,       XXXXXXX,                        KC_PGUP,  _______,  KC_UP,     _______,  _______,  KC_BSPC,
  _______,           KC_LALT,       KC_LCTL,              KC_LSFT,         XXXXXXX,       KC_CAPS,                        KC_PGDN,  KC_LEFT,  KC_DOWN,   KC_RGHT,  KC_DEL,   KC_BSPC,
  _______,           KC_UNDO,       KC_CUT,               KC_COPY,         KC_PASTE,      XXXXXXX,                    _______,  _______,  _______,  _______,  XXXXXXX,  _______,  XXXXXXX,  _______,
                                                  _______,  _______,  _______,  _______,  _______,                    _______,  _______,  _______,  _______,  _______
)
};

enum custom_keycodes {
    OS_UNDO = SAFE_RANGE,
    OS_CUT,
    OS_COPY,
    OS_PASTE,
};

// Karabiner maps left Command to left Option. These shortcuts are defined by
// the custom macOS Dvorak CS-DE input source.
static const uint16_t lower_quote_keycodes[] = {
    S(LGUI(KC_0)),       // ‚
    LGUI(KC_EQL),        // ‘
    S(LGUI(KC_EQL)),     // ’
    S(LGUI(KC_COMM)),    // „
    LGUI(KC_MINS),       // “
    S(LGUI(KC_MINS)),    // ”
};

static void send_edit_shortcut(uint16_t keycode) {
    const os_variant_t os = detected_host_os();
    // Favor the primary macOS workflow until host detection settles. Windows
    // and Linux are switched to Control as soon as they are identified.
    const bool is_macos = os != OS_WINDOWS && os != OS_LINUX;

    // Karabiner maps the Sofle's left Option to macOS Command. Windows and
    // Linux receive their native Control shortcuts after host detection.
    tap_code16(is_macos ? LALT(keycode) : LCTL(keycode));
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // VIA's saved layout can override the compiled keycodes. Handle these six
    // Lower-layer positions directly, without changing other VIA customizations.
    if (layer_state_is(3) && record->event.key.row == 0 && record->event.key.col <= 5) {
        if (record->event.pressed) {
            tap_code16(lower_quote_keycodes[record->event.key.col]);
        }
        return false;
    }

    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case KC_UNDO:
        case OS_UNDO:
            send_edit_shortcut(KC_SLSH);
            return false;
        case KC_CUT:
        case OS_CUT:
            send_edit_shortcut(KC_B);
            return false;
        case KC_COPY:
        case OS_COPY:
            send_edit_shortcut(KC_I);
            return false;
        case KC_PASTE:
        case OS_PASTE:
            send_edit_shortcut(KC_DOT);
            return false;
    }

    return true;
}

bool caps_word_press_user(uint16_t keycode) {
    // Resolve wrapped keys to their TAP key so HRMs/LT() don't break Caps Word.
    uint16_t tap_kc = keycode;
    if (IS_QK_MOD_TAP(keycode)) {
        tap_kc = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    } else if (IS_QK_LAYER_TAP(keycode)) {
        tap_kc = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    }

    switch (tap_kc) {
        // Keep Caps Word and apply Shift (works even if Option/Kana are held)
        case KC_A ... KC_Z:
        case KC_QUOT:
        case KC_MINS:
        case KC_SCLN:
        case KC_COMM:
        case KC_DOT:
        case KC_SLSH:
            add_weak_mods(MOD_BIT(KC_LSFT));  // shift next key
            return true;

        // Keep Caps Word, but DON'T add Shift for these alone
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_LALT: case KC_RALT:  // Option
        case KC_LNG1: case KC_LNG2:  // Kana / Eisu
        case KC_INT4: case KC_INT5:  // Henkan / Muhenkan
        case KC_CAPS:
            return true;

        default:
            return false;  // exit Caps Word
    }
}
