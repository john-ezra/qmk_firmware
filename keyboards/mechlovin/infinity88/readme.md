# Infinity 88

![Infinity 88](https://i.imgur.com/9JGxJjVl.png)

A replacement PCB for F13 TKL keyboards with south-facing stabilisers. Rev. 1 uses an STM32F303; Rev. 2 uses an ATmega32U4 with two 74HC138 column decoders and is the standard solder PCB shipped with the NRD Kaze.

* Keyboard Maintainer: [Team Mechlovin'](https://github.com/mechlovin)
* Hardware Supported: Infinity 88 Rev. 1 (STM32F303), Infinity 88 Rev. 2 (ATmega32U4)
* Hardware Availability: [Mechlovin' Studio](https://mechlovin.studio/)

Make example for this keyboard (after setting up your build environment):

    make mechlovin/infinity88/rev1:default
    make mechlovin/infinity88/rev2:default

Flashing example for this keyboard:

    make mechlovin/infinity88/rev2:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
