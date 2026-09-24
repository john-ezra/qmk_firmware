// Copyright 2026 John Ezra (@john-ezra)
// SPDX-License-Identifier: GPL-2.0-or-later

#include <string.h>
#include "matrix.h"
#include "gpio.h"
#include "progmem.h"

/*
 * The ATmega32U4 does not have enough pins for 17 columns, so the Rev. 2 PCB
 * selects columns 0-15 through two 74HC138 3-to-8 decoders. Both decoders
 * share the address lines; each has its own active-high enable. A selected
 * output is driven low (the column is active), every other output is high.
 * Column 16 is wired straight to a GPIO.
 *
 *   address  A0 = F0, A1 = B7, A2 = B5
 *   enable   decoder 0 (columns 0-7) = B0, decoder 1 (columns 8-15) = F1
 *   direct   column 16 = E6
 */
#define DECODED_COLS 16
#define DIRECT_COL_PIN E6

static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static const pin_t address_pins[3]       = {F0, B7, B5};
static const pin_t enable_pins[2]        = {B0, F1};

/* Decoder output feeding each column. Columns 14 and 15 are routed to Y7 and
 * Y6 respectively, the reverse of their natural order. */
static const uint8_t col_address[DECODED_COLS] PROGMEM = {0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 7, 6};

static void select_col(uint8_t col) {
    if (col >= DECODED_COLS) {
        gpio_write_pin_low(DIRECT_COL_PIN);
        return;
    }
    uint8_t address = pgm_read_byte(&col_address[col]);
    for (uint8_t bit = 0; bit < 3; bit++) {
        gpio_write_pin(address_pins[bit], address & (1 << bit));
    }
    gpio_write_pin_high(enable_pins[col / 8]);
}

static void unselect_col(uint8_t col) {
    if (col >= DECODED_COLS) {
        gpio_write_pin_high(DIRECT_COL_PIN);
        return;
    }
    gpio_write_pin_low(enable_pins[col / 8]);
}

void matrix_init_custom(void) {
    for (uint8_t i = 0; i < 3; i++) {
        gpio_set_pin_output(address_pins[i]);
    }
    for (uint8_t i = 0; i < 2; i++) {
        gpio_set_pin_output(enable_pins[i]);
        gpio_write_pin_low(enable_pins[i]);
    }
    gpio_set_pin_output(DIRECT_COL_PIN);
    gpio_write_pin_high(DIRECT_COL_PIN);
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        gpio_set_pin_input_high(row_pins[row]);
    }
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    matrix_row_t next_matrix[MATRIX_ROWS] = {0};

    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        bool key_pressed = false;

        select_col(col);
        matrix_output_select_delay();
        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
            if (!gpio_read_pin(row_pins[row])) {
                next_matrix[row] |= (matrix_row_t)1 << col;
                key_pressed = true;
            }
        }
        unselect_col(col);
        matrix_output_unselect_delay(col, key_pressed);
    }

    bool changed = memcmp(current_matrix, next_matrix, sizeof(next_matrix)) != 0;
    if (changed) {
        memcpy(current_matrix, next_matrix, sizeof(next_matrix));
    }
    return changed;
}
