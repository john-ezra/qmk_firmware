# Oblique60

Oblique60 is a 60% keyboard by Bowl with solder and hotswap PCB options.

* Keyboard Maintainer: [kindlestar](https://kindlestar.online/)
* Hardware Supported: Oblique60 PCBs with STM32F072 MCU
* Hardware Availability: [Bowl Oblique](https://bowlkeyboards.com/pages/oblique-landing-page)

Make example for this keyboard (after setting up your build environment):

    make bowl/oblique60:default

Flashing example for this keyboard:

    make bowl/oblique60:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with the [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Hold the reset button on the back of the PCB for 3 seconds
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
