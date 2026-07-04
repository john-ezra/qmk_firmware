/* Copyright 2020 Garret Gartner (Kingly-Keys)
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

enum layers {
    _BASE,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* _BASE: QWERTY with left numpad cluster */
    [_BASE] = LAYOUT(
        KC_7,    KC_8,    KC_9,    QK_GESC, KC_CAPS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, KC_NUHS,
        KC_4,    KC_5,    KC_6,             KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,          KC_BSPC,
        KC_1,    KC_2,    KC_3,    KC_UP,   KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_0,    KC_0,    KC_LEFT, KC_DOWN, KC_RGHT, KC_LCTL, KC_LGUI, KC_LALT, LT(_FN, KC_ENT), LT(_FN, KC_SPC), KC_RALT, KC_RGUI, KC_RCTL, QK_BOOT
    ),

    /* _FN: numbers, F-keys, navigation, media, RGB */
    [_FN] = LAYOUT(
        KC_F7,   KC_F8,   KC_F9,   KC_GRV,  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______,
        KC_F4,   KC_F5,   KC_F6,            _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,          KC_DEL,
        KC_F1,   KC_F2,   KC_F3,   KC_PGUP, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______,
        KC_F10,  KC_F11,  KC_HOME, KC_PGDN, KC_END,  _______, _______, _______, _______, _______, _______, UG_TOGG, UG_NEXT, QK_BOOT
    ),
};
