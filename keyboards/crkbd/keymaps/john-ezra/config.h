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


#pragma once

#define MASTER_LEFT

#define USE_SERIAL_PD2

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLIGHT_ANIMATIONS
    #define RGBLED_NUM 27
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#ifdef RGB_MATRIX_ENABLE
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
  #define RGB_MATRIX_HUE_STEP 4
  #define RGB_MATRIX_SAT_STEP 4
  #define RGB_MATRIX_VAL_STEP 4
  #define RGB_MATRIX_SPD_STEP 10

  #define DISABLE_RGB_MATRIX_BREATHING
  #define DISABLE_RGB_MATRIX_BAND_SAT
  #define DISABLE_RGB_MATRIX_BAND_VAL
  #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
  #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
  #define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
  #define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
  #define DISABLE_RGB_MATRIX_RAINDROPS
  #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
  #define DISABLE_RGB_MATRIX_HUE_BREATHING
  #define DISABLE_RGB_MATRIX_RAINBOW_BEACON
  #define DISABLE_RGB_RGB_MATRIX_CYCLE_SPIRAL
  #define DISABLE_RGB_MATRIX_HUE_PENDULUM
#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#define SPLIT_WPM_ENABLE
