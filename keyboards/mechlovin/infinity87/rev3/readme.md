# Infinity87 Rev. 3

![Infinity87 Rev. 3](https://i.imgur.com/QuK1EnNl.png)

Mechlovin' replacement PCB for TKL keyboards, A87 form factor with south-facing stabilisers, on an STM32F103 (APM32F103) with the stm32duino bootloader. The standard PCB has 24 WS2812 underglow LEDs and supports ANSI, ISO, and ABNT2 with split backspace, split right shift, and 6.25u or 7u bottom rows. It ships in the Merisi Works 500C/M.

* Keyboard Maintainer: [Mechlovin' Studio](https://mechlovin.studio/)
* Hardware Supported: Infinity87 Rev. 3 Standard
* Hardware Availability: [Mechlovin' Studio](https://mechlovin.studio/)

Make example for this keyboard (after setting up your build environment):

    make mechlovin/infinity87/rev3/standard:default

Flashing example for this keyboard:

    make mechlovin/infinity87/rev3/standard:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
