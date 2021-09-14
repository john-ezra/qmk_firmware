/* Copyright 2021 John Ezra
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
#include <stdio.h>

enum crkbd_layers {
  _HNTS,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum crkbd_keycodes {
  HNTS = SAFE_RANGE,
  LOWER,
  RAISE,
  BSP_CMD,
  SFT_ENT,
  CPY_PST,
  FIND,
  UNDO
};

#define HNTS DF(_HNTS)
#define BSP_CMD MT(MOD_LGUI, KC_BSPC)
#define SFT_ENT MT(MOD_LSFT, KC_ENT)
#define UNDO G(KC_Z)
#define FIND G(KC_F)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_HNTS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         FIND,    KC_Z,    KC_R,    KC_L,    KC_D,    KC_W,                         KC_Y,    KC_P,    KC_U,    KC_X,    KC_Q, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CPY_PST,    KC_H,    KC_N,    KC_T,    KC_S,    KC_C,                         KC_B,    KC_I,    KC_E,    KC_O,    KC_A,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         UNDO,    KC_K,    KC_V,    KC_M,    KC_F,    KC_G,                         KC_J, KC_SCLN, KC_COMM,  KC_DOT, KC_SLSH, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          BSP_CMD,   LOWER,  KC_SPC,    SFT_ENT,   RAISE,  KC_TAB
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_ASTR, KC_SLSH, KC_PLUS, KC_MINS,  KC_EQL,                      KC_PIPE, KC_LCBR, KC_RCBR,   KC_AT, KC_EXLM,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, KC_BRIU,                      KC_BSLS, KC_LPRN, KC_RPRN,  KC_DLR, KC_HASH, KC_TILD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID,                      KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC, KC_PERC, KC_AMPR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    KC_CAPS, _______,  KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, _______, KC_LALT,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                      _______, NK_TOGG, CG_TOGG,    HNTS, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD,RGB_RMOD,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case CPY_PST:  // One key copy/paste
          {
            static uint16_t copy_paste_timer;
              if (record->event.pressed) {
                copy_paste_timer = timer_read();
              } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                  register_mods(mod_config(MOD_LGUI));
                  tap_code(KC_C);
                  unregister_mods(mod_config(MOD_LGUI));
                } else {
                  register_mods(mod_config(MOD_LGUI));
                  tap_code(KC_V);
                  unregister_mods(mod_config(MOD_LGUI));
                }
              }
          }
          break;
        case UNDO:  // Undo Redo
          if ((get_mods() & MOD_BIT(KC_LGUI)) == MOD_BIT(KC_LGUI)) {
            if (record->event.pressed) {
              register_code(KC_Y);
            } else {
              unregister_code(KC_Y);
            }
          return false;
          }
          return true;
    }
  return true;
};
