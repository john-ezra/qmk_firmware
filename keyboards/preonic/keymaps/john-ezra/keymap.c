/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _HNTS,
  _GAME,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  HNTS = SAFE_RANGE,
  GAME,
  LOWER,
  RAISE,
  CPY_PST,
  UNDO
};

#define HNTS DF(_HNTS)
#define GAME DF(_GAME)
#define BSP_CMD MT(MOD_LCTL, KC_BSPC)
#define SFT_ENT MT(MOD_LSFT, KC_ENT)
#define UNDO C(KC_Z)
#define FIND C(KC_F)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* HNTS
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Z  |   R  |   L  |   D  |   W  |   Y  |   P  |   U  |   X  |   Q  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   H  |   N  |   T  |   S  |   C  |   B  |   I  |   E  |   O  |   A  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   K  |   V  |   M  |   F  |   G  |   J  |   ;  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |Space |Shift |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_HNTS] = LAYOUT_preonic_grid(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ENT,
  FIND,    KC_Z,    KC_R,    KC_L,    KC_D,    KC_W,    KC_Y,    KC_P,    KC_U,    KC_X,    KC_Q,    KC_BSLS,
  CPY_PST, KC_H,    KC_N,    KC_T,    KC_S,    KC_C,    KC_B,    KC_I,    KC_E,    KC_O,    KC_A,    KC_ESC,
  UNDO,    KC_K,    KC_V,    KC_M,    KC_F,    KC_G,    KC_J,    KC_SCLN, KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
  KC_LSFT, KC_LGUI, KC_LALT, BSP_CMD, LOWER, KC_SPC,  SFT_ENT,   RAISE,   KC_TAB,  KC_MPRV, KC_MPLY, KC_MNXT
),

/* Game
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Z  |   R  |   L  |   D  |   W  |   Y  |   P  |   U  |   X  |   Q  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   H  |   N  |   T  |   S  |   C  |   B  |   I  |   E  |   O  |   A  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   K  |   V  |   M  |   F  |   G  |   J  |   ;  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |Space |Shift |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
  KC_ENT,  KC_Z,    KC_R,    KC_L,    KC_D,    KC_W,    KC_Y,    KC_P,    KC_U,    KC_X,    KC_Q,    KC_ENT,
  KC_ESC,  KC_H,    KC_N,    KC_T,    KC_S,    KC_C,    KC_B,    KC_I,    KC_E,    KC_O,    KC_A,    KC_BSPC,
  KC_MINS, KC_K,    KC_V,    KC_M,    KC_F,    KC_G,    KC_J,    KC_SCLN, KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
  KC_SCLN, KC_COMM,  KC_DOT, KC_SLSH, KC_QUOT, KC_SPC,  KC_RSFT, KC_PLUS, KC_TAB,  KC_LALT, RAISE,   LOWER
),

/* Lower : Symbols
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   *  |   /  |   +  |   -  |   =  |   |  |   {  |   }  |   @  |   !  |  `   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Left |Right |  Up  | Down | Bri+ |   \  |   (  |   )  |   $  |   $  |  #   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Vol- | Vol+ | Prev | Play | Next | Bri- |   _  |   [  |   ]  |   ^  |   %  |  &   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_ASTR, KC_SLSH, KC_PLUS, KC_MINS, KC_EQL,  KC_PIPE, KC_LCBR, KC_RCBR, KC_AT,   KC_EXLM, KC_GRV,
  _______, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, KC_BRIU, KC_BSLS, KC_LPRN, KC_RPRN, KC_DLR,  KC_HASH, KC_TILD,
  KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC, KC_PERC, KC_AMPR,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|HNTS|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  RESET,   DEBUG,   TERM_ON, TERM_OFF,_______, _______, _______, _______, _______, _______, GAME,    HNTS,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, _______,   NK_ON, NK_OFF,  CG_SWAP, CG_NORM, _______,
  _______, _______, RGB_SAD, RGB_HUD, RGB_VAD,RGB_RMOD, _______, _______, _______, _______, _______,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______
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
                  register_mods(mod_config(MOD_LCTL));
                  tap_code(KC_C);
                  unregister_mods(mod_config(MOD_LCTL));
                } else {
                  register_mods(mod_config(MOD_LCTL));
                  tap_code(KC_V);
                  unregister_mods(mod_config(MOD_LCTL));
                }
              }
          }
          break;
        case UNDO:  // Undo Redo
          if ((get_mods() & MOD_BIT(KC_LCTL)) == MOD_BIT(KC_LCTL)) {
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
