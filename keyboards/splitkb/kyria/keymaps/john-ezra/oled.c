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
	return OLED_ROTATION_180;
}

// Loop to create line by line rendering for Horizontal display
// Input is oled_render_image(how many rows tall, how many pixels wide, what to render, X pos, Y pos, Frame offset)
void oled_render_image(int lines, int px, const char render_line[][px], int X_pos, int Y_pos, int frame) {
    for (uint8_t i = 0; i < lines; i++){
        oled_set_cursor(X_pos, Y_pos + i);
        oled_write_raw_P(render_line[i + frame], px);
    }
}

static void render_layers(void) {
    static const char PROGMEM layer_background_r1[1][38] = {
        {0x00, 0xf8, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x82, 0x82, 0x82, 0x42, 0x42, 0x42, 0x22,
		     0x22, 0x22, 0x12, 0x12, 0x12, 0x22, 0x22, 0x22, 0x42, 0x42, 0x42, 0x82, 0x82, 0x82, 0x02, 0x02,
		     0x02, 0x02, 0x02, 0x02, 0x04, 0xf8}
			  };
		static const char PROGMEM layer_background_r2[1][38] = {
        {0x00, 0xff, 0x00, 0x22, 0x22, 0x22, 0x55, 0x55, 0x55, 0x88, 0x88, 0x88, 0x10, 0x10, 0x10, 0x20,
		     0x20, 0x20, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x88, 0x88, 0x88, 0x55, 0x55,
		     0x55, 0x22, 0x22, 0x22, 0x00, 0xff}
			  };
		static const char PROGMEM layer_background_r3[1][38] = {
        {0x00, 0xff, 0x00, 0x22, 0x22, 0x22, 0x55, 0x55, 0x55, 0x88, 0x88, 0x88, 0x11, 0x11, 0x11, 0x22,
		     0x22, 0x22, 0x44, 0x44, 0x44, 0x22, 0x22, 0x22, 0x11, 0x11, 0x11, 0x88, 0x88, 0x88, 0x55, 0x55,
		     0x55, 0x22, 0x22, 0x22, 0x00, 0xff}};

		static const char PROGMEM layer_background_r4[1][38] = {
        {0x00, 0x1f, 0x20, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x41, 0x41, 0x41, 0x42,
		     0x42, 0x42, 0x44, 0x44, 0x44, 0x42, 0x42, 0x42, 0x41, 0x41, 0x41, 0x40, 0x40, 0x40, 0x40, 0x40,
		     0x40, 0x40, 0x40, 0x40, 0x20, 0x1f}
			  };
		static const char PROGMEM base[1][38] = {
				{0x00, 0xff, 0x00, 0x22, 0x22, 0x22, 0x57, 0x57, 0x57, 0x8f, 0x8f, 0x8f, 0x1f, 0x1f, 0x1f, 0x3e,
				 0x3e, 0x3e, 0x7c, 0x7c, 0x7c, 0x3e, 0x3e, 0x3e, 0x1f, 0x1f, 0x1f, 0x8f, 0x8f, 0x8f, 0x57, 0x57,
				 0x57, 0x22, 0x22, 0x22, 0x00, 0xff}
				};
		static const char PROGMEM lower[2][38] = {
		 		{0x00, 0xff, 0x00, 0x22, 0x22, 0x22, 0x75, 0x75, 0x75, 0xf8, 0xf8, 0xf8, 0xf1, 0xf1, 0xf1, 0xe2,
				 0xe2, 0xe2, 0xc4, 0xc4, 0xc4, 0xe2, 0xe2, 0xe2, 0xf1, 0xf1, 0xf1, 0xf8, 0xf8, 0xf8, 0x75, 0x75,
				 0x75, 0x22, 0x22, 0x22, 0x00, 0xff},
		 	 	{0x00, 0x1f, 0x20, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x41, 0x41, 0x41, 0x43,
				 0x43, 0x43, 0x47, 0x47, 0x47, 0x43, 0x43, 0x43, 0x41, 0x41, 0x41, 0x40, 0x40, 0x40, 0x40, 0x40,
				 0x40, 0x40, 0x40, 0x40, 0x20, 0x1f}
			 	};
		static const char PROGMEM raise[][38] = {
				{0x00, 0xff, 0x00, 0x22, 0x22, 0x22, 0x75, 0x75, 0x75, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0,
	     	 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf8, 0xf8, 0xf8, 0x75, 0x75,
	       0x75, 0x22, 0x22, 0x22, 0x00, 0xff},
				{0x00, 0xff, 0x00, 0x22, 0x22, 0x22, 0x55, 0x55, 0x55, 0x88, 0x88, 0x88, 0x11, 0x11, 0x11, 0x23,
	     	 0x23, 0x23, 0x47, 0x47, 0x47, 0x23, 0x23, 0x23, 0x11, 0x11, 0x11, 0x88, 0x88, 0x88, 0x55, 0x55,
	       0x55, 0x22, 0x22, 0x22, 0x00, 0xff}
		 		};
		static const char PROGMEM adjust[][38] = {
				{0x00, 0xf8, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x82, 0x82, 0x82, 0xc2, 0xc2, 0xc2, 0xe2,
				 0xe2, 0xe2, 0xf2, 0xf2, 0xf2, 0xe2, 0xe2, 0xe2, 0xc2, 0xc2, 0xc2, 0x82, 0x82, 0x82, 0x02, 0x02,
				 0x02, 0x02, 0x02, 0x02, 0x04, 0xf8},
				{0x00, 0xff, 0x00, 0x22, 0x22, 0x22, 0x57, 0x57, 0x57, 0x8f, 0x8f, 0x8f, 0x1f, 0x1f, 0x1f, 0x3f,
				 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x1f, 0x8f, 0x8f, 0x8f, 0x57, 0x57,
				 0x57, 0x22, 0x22, 0x22, 0x00, 0xff}
			 	};
		static const char PROGMEM custom[][38] = {
		 		{0x00, 0xf8, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x82, 0x82, 0x82, 0x42, 0xc2, 0x42, 0xa2,
		     0x62, 0xa2, 0x52, 0xb2, 0x52, 0xa2, 0x62, 0xa2, 0x42, 0xc2, 0x42, 0x82, 0x82, 0x82, 0x02, 0x02,
		     0x02, 0x02, 0x02, 0x02, 0x04, 0xf8},
		 		{0x00, 0xff, 0x00, 0x22, 0x22, 0x22, 0x55, 0x77, 0x55, 0xaa, 0xdd, 0xaa, 0x55, 0xba, 0x55, 0xaa,
		     0x75, 0xaa, 0x55, 0xea, 0x55, 0xaa, 0x75, 0xaa, 0x55, 0xba, 0x55, 0xaa, 0xdd, 0xaa, 0x55, 0x77,
		     0x55, 0x22, 0x22, 0x22, 0x00, 0xff},
		 		{0x00, 0xff, 0x00, 0x22, 0x22, 0x22, 0x55, 0x77, 0x55, 0xaa, 0xdd, 0xaa, 0x55, 0xbb, 0x55, 0xaa,
		     0x77, 0xaa, 0x55, 0xee, 0x55, 0xaa, 0x77, 0xaa, 0x55, 0xbb, 0x55, 0xaa, 0xdd, 0xaa, 0x55, 0x77,
		     0x55, 0x22, 0x22, 0x22, 0x00, 0xff},
		 		{0x00, 0x1f, 0x20, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x41, 0x41, 0x41, 0x42,
		     0x43, 0x42, 0x45, 0x46, 0x45, 0x42, 0x43, 0x42, 0x41, 0x41, 0x41, 0x40, 0x40, 0x40, 0x40, 0x40,
		     0x40, 0x40, 0x40, 0x40, 0x20, 0x1f}
		 	  };

		switch (get_highest_layer(layer_state)) {
				case 0:
						oled_render_image(1, 38, layer_background_r1, 15, 4, 0);
						oled_render_image(1, 38, layer_background_r2, 15, 5, 0);
		 		    oled_render_image(1, 38, base, 15, 6, 0);
						oled_render_image(1, 38, layer_background_r4, 15, 7, 0);
		 			break;
		 		case 1:
		 		    oled_render_image(2, 38, lower, 15, 6, 0);
		 			break;
				case 2:
						oled_render_image(1, 38, layer_background_r1, 15, 4, 0);
						oled_render_image(2, 38, raise, 15, 5, 0);
						oled_render_image(1, 38, layer_background_r4, 15, 7, 0);
					break;
				case 3:
						oled_render_image(2, 38, adjust, 15, 4, 0);
						oled_render_image(1, 38, layer_background_r3, 15, 6, 0);
						oled_render_image(1, 38, layer_background_r4, 15, 7, 0);
					break;
				default:
						oled_render_image(4, 38, custom, 15, 4, 0);
					break;
		}
}

void render_mod_state(uint8_t modifiers) {
		static const char PROGMEM gui_off [][3]= {{0x80, 0x81, 0}, {0xa0, 0xa1, 0}};
		static const char PROGMEM gui_on [][3]= {{0xc0, 0xc1, 0}, {0xe0, 0xe1, 0}};
		static const char PROGMEM alt_off [][3]= {{0x82, 0x83, 0}, {0xa2, 0xa3, 0}};
		static const char PROGMEM alt_on [][3]= {{0xc2, 0xc3, 0}, {0xe2, 0xe3, 0}};
		static const char PROGMEM ctrl_off [][3]= {{0x84, 0x85, 0}, {0xa4, 0xa5, 0}};
		static const char PROGMEM ctrl_on [][3]= {{0xc4, 0xc5, 0}, {0xe4, 0xe5, 0}};
		static const char PROGMEM shift_off [][3]= {{0x86, 0x87, 0}, {0xa6, 0xa7, 0}};
		static const char PROGMEM shift_on [][3]= {{0xc6, 0xc7, 0}, {0xe6, 0xe7, 0}};

		// fillers between the modifier icons bleed into the icon frames

		static const char PROGMEM off_off [][2]= {{0x9e, 0}, {0xbe, 0}};
		static const char PROGMEM on_on [][2]= {{0xdf, 0}, {0xff, 0}};
		static const char PROGMEM on_off [][2]= {{0xde, 0}, {0xfe, 0}};
		static const char PROGMEM off_on [][2]= {{0x9f, 0}, {0xbf, 0}};

		// render icons

		if(modifiers & MOD_MASK_GUI) {
				oled_set_cursor(0, 4);
				oled_write_P(gui_on[0], false);
				oled_set_cursor(0, 5);
				oled_write_P(gui_on[1], false);
		} else {
				oled_set_cursor(0, 4);
				oled_write_P(gui_off[0], false);
				oled_set_cursor(0, 5);
				oled_write_P(gui_off[1], false);
		}
		if(modifiers & MOD_MASK_ALT) {
				oled_set_cursor(3, 4);
				oled_write_P(alt_on[0], false);
				oled_set_cursor(3, 5);
				oled_write_P(alt_on[1], false);
		} else {
				oled_set_cursor(3, 4);
				oled_write_P(alt_off[0], false);
				oled_set_cursor(3, 5);
				oled_write_P(alt_off[1], false);
		}
		if(modifiers & MOD_MASK_CTRL) {
				oled_set_cursor(0, 6);
				oled_write_P(ctrl_on[0], false);
				oled_set_cursor(0, 7);
				oled_write_P(ctrl_on[1], false);
		} else {
				oled_set_cursor(0, 6);
				oled_write_P(ctrl_off[0], false);
				oled_set_cursor(0, 7);
				oled_write_P(ctrl_off[1], false);
		}
		if(modifiers & MOD_MASK_SHIFT) {
				oled_set_cursor(3, 6);
				oled_write_P(shift_on[0], false);
				oled_set_cursor(3, 7);
				oled_write_P(shift_on[1], false);
		} else {
				oled_set_cursor(3, 6);
				oled_write_P(shift_off[0], false);
				oled_set_cursor(3, 7);
				oled_write_P(shift_off[1], false);
		}

		// render fillers

		if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
			  oled_set_cursor(2, 4);
        oled_write_P(on_on[0], false);
				oled_set_cursor(2, 5);
				oled_write_P(on_on[1], false);
    } else if(modifiers & MOD_MASK_GUI) {
			  oled_set_cursor(2, 4);
			  oled_write_P(on_off[0], false);
			  oled_set_cursor(2, 5);
			  oled_write_P(on_off[1], false);
    } else if(modifiers & MOD_MASK_ALT) {
			  oled_set_cursor(2, 4);
			  oled_write_P(off_on[0], false);
			  oled_set_cursor(2, 5);
			  oled_write_P(off_on[1], false);
    } else {
			  oled_set_cursor(2, 4);
		  	oled_write_P(off_off[0], false);
		  	oled_set_cursor(2, 5);
		  	oled_write_P(off_off[1], false);
    }

		if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
				oled_set_cursor(2, 6);
				oled_write_P(on_on[0], false);
				oled_set_cursor(2, 7);
				oled_write_P(on_on[1], false);
		} else if(modifiers & MOD_MASK_CTRL) {
				oled_set_cursor(2, 6);
				oled_write_P(on_off[0], false);
				oled_set_cursor(2, 7);
				oled_write_P(on_off[1], false);
		} else if(modifiers & MOD_MASK_SHIFT) {
				oled_set_cursor(2, 6);
				oled_write_P(off_on[0], false);
				oled_set_cursor(2, 7);
				oled_write_P(off_on[1], false);
		} else {
				oled_set_cursor(2, 6);
				oled_write_P(off_off[0], false);
				oled_set_cursor(2, 7);
				oled_write_P(off_off[1], false);
		}
}

void render_bootmagic_status(void) {
		static const char PROGMEM nkro_off [][3]= {{0x88, 0x89, 0}, {0xa8, 0xa9, 0}};
		static const char PROGMEM nkro_on [][3]= {{0xc8, 0xc9, 0}, {0xe8, 0xe9, 0}};
		static const char PROGMEM mac_os_off [][6]= {{0x90, 0x91, 0x92, 0x93, 0x94, 0}, {0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0}};
		static const char PROGMEM mac_os_on [][6]= {{0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0}, {0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0}};
		static const char PROGMEM windows_off [][6]= {{0x95, 0x96, 0x97, 0x98, 0x99, 0}, {0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0}};
		static const char PROGMEM windows_on [][6]= {{0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0}, {0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0}};

		if (keymap_config.nkro) {
			  oled_set_cursor(5, 4);
			  oled_write_P(nkro_on[0], false);
			  oled_set_cursor(5, 5);
			  oled_write_P(nkro_on[1], false);
		}	else {
				oled_set_cursor(5, 4);
				oled_write_P(nkro_off[0], false);
				oled_set_cursor(5, 5);
				oled_write_P(nkro_off[1], false);
		}
		if (keymap_config.swap_lctl_lgui) {
				oled_set_cursor(10, 6);
				oled_write_P(windows_on[0], false);
				oled_set_cursor(10, 7);
				oled_write_P(windows_on[1], false);
				oled_set_cursor(10, 4);
				oled_write_P(mac_os_off[0], false);
				oled_set_cursor(10, 5);
				oled_write_P(mac_os_off[1], false);
		}	else {
				oled_set_cursor(10, 4);
				oled_write_P(mac_os_on[0], false);
				oled_set_cursor(10, 5);
				oled_write_P(mac_os_on[1], false);
				oled_set_cursor(10, 6);
				oled_write_P(windows_off[0], false);
				oled_set_cursor(10, 7);
				oled_write_P(windows_off[1], false);
		}
}

void render_lock_status(void) {
		static const char PROGMEM caps_off [][3]= {{0x8a, 0x8b, 0}, {0xaa, 0xab, 0}};
		static const char PROGMEM caps_on [][3]= {{0xca, 0xcb, 0}, {0xea, 0xeb, 0}};
		static const char PROGMEM num_off [][3]= {{0x8c, 0x8d, 0}, {0xac, 0xad, 0}};
		static const char PROGMEM num_on [][3]= {{0xcc, 0xcd, 0}, {0xec, 0xed, 0}};
		static const char PROGMEM scrl_off [][3]= {{0x8e, 0x8f, 0}, {0xae, 0xaf, 0}};
		static const char PROGMEM scrl_on [][3]= {{0xce, 0xcf, 0}, {0xee, 0xef, 0}};

		static const char PROGMEM off_off [][2]= {{0x9e, 0}, {0xbe, 0}};
		static const char PROGMEM on_on [][2]= {{0xdf, 0}, {0xff, 0}};
		static const char PROGMEM on_off [][2]= {{0xde, 0}, {0xfe, 0}};
		static const char PROGMEM off_on [][2]= {{0x9f, 0}, {0xbf, 0}};

		led_t led_usb_state = host_keyboard_led_state();
		if (led_usb_state.caps_lock) {
			  oled_set_cursor(8, 4);
			  oled_write_P(caps_on[0], false);
			  oled_set_cursor(8, 5);
		  	oled_write_P(caps_on[1], false);
		}	else {
			  oled_set_cursor(8, 4);
			  oled_write_P(caps_off[0], false);
			  oled_set_cursor(8, 5);
			  oled_write_P(caps_off[1], false);
		}
		if (led_usb_state.num_lock) {
				oled_set_cursor(5, 6);
				oled_write_P(num_on[0], false);
				oled_set_cursor(5, 7);
				oled_write_P(num_on[1], false);
		}	else {
				oled_set_cursor(5, 6);
				oled_write_P(num_off[0], false);
				oled_set_cursor(5, 7);
				oled_write_P(num_off[1], false);
		}
		if (led_usb_state.scroll_lock) {
				oled_set_cursor(8, 6);
				oled_write_P(scrl_on[0], false);
				oled_set_cursor(8, 7);
				oled_write_P(scrl_on[1], false);
		}	else {
				oled_set_cursor(8, 6);
				oled_write_P(scrl_off[0], false);
				oled_set_cursor(8, 7);
				oled_write_P(scrl_off[1], false);
		}

	// render fillers

	if ((led_usb_state.caps_lock) && (keymap_config.nkro)) {
			oled_set_cursor(7, 4);
			oled_write_P(on_on[0], false);
			oled_set_cursor(7, 5);
			oled_write_P(on_on[1], false);
	} else if(keymap_config.nkro) {
			oled_set_cursor(7, 4);
			oled_write_P(on_off[0], false);
			oled_set_cursor(7, 5);
			oled_write_P(on_off[1], false);
	} else if(led_usb_state.caps_lock) {
			oled_set_cursor(7, 4);
			oled_write_P(off_on[0], false);
			oled_set_cursor(7, 5);
			oled_write_P(off_on[1], false);
	} else {
			oled_set_cursor(7, 4);
			oled_write_P(off_off[0], false);
			oled_set_cursor(7, 5);
			oled_write_P(off_off[1], false);
	}
	if ((led_usb_state.num_lock) && (led_usb_state.scroll_lock)) {
			oled_set_cursor(7, 6);
			oled_write_P(on_on[0], false);
			oled_set_cursor(7, 7);
			oled_write_P(on_on[1], false);
	} else if(led_usb_state.num_lock) {
			oled_set_cursor(7, 6);
			oled_write_P(on_off[0], false);
			oled_set_cursor(7, 7);
			oled_write_P(on_off[1], false);
	} else if(led_usb_state.scroll_lock) {
			oled_set_cursor(7, 6);
			oled_write_P(off_on[0], false);
			oled_set_cursor(7, 7);
			oled_write_P(off_on[1], false);
	} else {
			oled_set_cursor(7, 6);
			oled_write_P(off_off[0], false);
			oled_set_cursor(7, 7);
			oled_write_P(off_off[1], false);
	}
}

void render_wpm(void) {
		currwpm = get_current_wpm();  //get current WPM value
		if(timer_elapsed(timer) > graph_refresh_interval){  //check if it's been long enough before refreshing graph
			x = 64 - ((currwpm / max_wpm) * 64);  // main calculation to plot graph line
			for(int i = 0; i <= graph_line_thickness - 1; i++){  //first draw actual value line
				oled_write_pixel(1, x + i, true);
			}
			if(vert_line){  //then fill in area below the value line
				if(vert_count == vert_interval){
					vert_count = 0;
					while(x <= 64){
						oled_write_pixel(1, x, true);
						x++;
					}
				} else {
					for(int i = 64; i > x; i--){
						if(i % graph_area_fill_interval == 0){
							oled_write_pixel(1, i, true);
						}
					}
					vert_count++;
				}
			} else {
				for(int i = 64; i > x; i--){
					if(i % graph_area_fill_interval == 0){
						oled_write_pixel(1, i, true);
					}
				}
			}
			oled_pan(false);  //then move the entire graph one pixel to the right
			timer = timer_read();  //refresh the timer for the next iteration
		}
		char buf[4];  //format current WPM value into a printable string
		oled_set_cursor(14, 0);
		oled_write("WPM:", false);
		buf[0] = currwpm >= 100 ? ((currwpm/100) + '0') : ' ';
		buf[1] = currwpm >= 10 ? (((currwpm/10) % 10) + '0') : ' ';
		buf[2] = (currwpm % 10) + '0';
		buf[3] = 0;
		oled_write(buf, false);
}

void render_status_main(void) {
	  render_layers();
		render_mod_state(get_mods());
		render_bootmagic_status();
		render_lock_status();

}

void render_status_secondary(void) {
	  render_wpm();
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }
}

#endif
