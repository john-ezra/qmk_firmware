# Otus60

Otus Engineering's 60% PCB, sold through Daji Keyboards and bundled with the Merisi Works Sessanta. It has an H60-compatible footprint, a solder-on JST connector for a USB-C daughterboard, and an STM32F072 running crystal-less from its internal oscillator. The matrix supports a Tsangan bottom row with optional split Backspace and split Right Shift.

The PCB ships with Vial firmware whose source was never published. This port was reconstructed from the board itself: the layouts come from the Vial definition the PCB reports over raw HID, and the matrix pins, diode direction, clock tree, and USB descriptors were recovered from the published `otusengineering_otus60stm32_vial.bin` image.

* Keyboard Maintainer: [John Ezra](https://github.com/john-ezra)
* Hardware Supported: Otus60 (STM32F072RB)
* Hardware Availability: [Daji Keyboards](https://dajikeyboards.com/products/otus-60-pcb)

Make example for this keyboard (after setting up your build environment):

    make otus_engineering/otus60:default

Flashing example for this keyboard:

    make otus_engineering/otus60:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

While the stock Vial firmware is still installed, its security lock blocks the bootloader jump until the keyboard is unlocked from the Vial GUI (Security > Unlock), after which Security > Reboot to bootloader works. Bootmagic reset and the physical reset work regardless.
