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

//Sets up what the OLED screens display.

#include QMK_KEYBOARD_H

int timer = 0;
char wpm_counter[5];
int x = 31;
int currwpm = 0;
int vert_count = 0;

//=============  USER CONFIG PARAMS  ===============
float max_wpm = 150.0f; //WPM value at the top of the graph window
int graph_refresh_interval = 80; //in milliseconds
int graph_area_fill_interval = 3; //determines how dense the horizontal lines under the graph line are; lower = more dense
int vert_interval = 3; //determines frequency of vertical lines under the graph line
bool vert_line = false; //determines whether to draw vertical lines
int graph_line_thickness = 2; //determines thickness of graph line in pixels
//=============  END USER PARAMS  ===============

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;
  }
  return rotation;
}

void render_bootmagic_status(void) {
		oled_write_P((keymap_config.swap_lctl_lgui) ? PSTR("OS:    Windows\n\n") : PSTR("OS:    MacOS\n\n"), false);
		oled_write_P((keymap_config.nkro) ? PSTR("NKRO   ") : PSTR("       "), false);
}

void render_wpm(void) {
		//get current WPM value
		currwpm = get_current_wpm();
		//check if it's been long enough before refreshing graph
		if(timer_elapsed(timer) > graph_refresh_interval){
			// main calculation to plot graph line
			x = 32 - ((currwpm / max_wpm) * 32);
			//first draw actual value line
			for(int i = 0; i <= graph_line_thickness - 1; i++){
				oled_write_pixel(1, x + i, true);
			}
			//then fill in area below the value line
			if(vert_line){
				if(vert_count == vert_interval){
					vert_count = 0;
					while(x <= 32){
						oled_write_pixel(1, x, true);
						x++;
					}
				} else {
					for(int i = 32; i > x; i--){
						if(i % graph_area_fill_interval == 0){
							oled_write_pixel(1, i, true);
						}
					}
					vert_count++;
				}
			} else {
				for(int i = 32; i > x; i--){
					if(i % graph_area_fill_interval == 0){
						oled_write_pixel(1, i, true);
					}
				}
			}
			//then move the entire graph one pixel to the right
			oled_pan(false);
			//refresh the timer for the next iteration
			timer = timer_read();
		}
		//format current WPM value into a printable string
		char buf[4];
		oled_set_cursor(14, 0);
		oled_write("WPM:", false);
		buf[0] = currwpm >= 100 ? ((currwpm/100) + '0') : ' ';
		buf[1] = currwpm >= 10 ? (((currwpm/10) % 10) + '0') : ' ';
		buf[2] = (currwpm % 10) + '0';
		buf[3] = 0;
		oled_write(buf, false);
}

static void render_status(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

		render_bootmagic_status();

// Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
				render_status();
    } else {
				render_wpm();
    }
}
#endif
