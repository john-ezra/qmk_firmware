# Zed60

![zed60](https://i.imgur.com/KyTpfmMl.png)

Mechlovin' 60% PCB family on an STM32F103 (APM32F103) with the stm32duino bootloader. Rev. 1 is the solder PCB with 22 WS2812 underglow LEDs and ANSI, ISO, split, and Tsangan layouts. Kaze Mini is the `MKP-Zed60-12-Hotswap` PCB Mechlovin' builds for the NRD Kaze Mini: same MCU, matrix, and caps lock indicator, but no underglow and only the Tsangan layout with split backspace, split right shift, and a stepped or 1.75u caps lock socket on the same matrix position.

* Keyboard Maintainer: [Mechlovin'](https://mechlovin.studio)
* Hardware Supported: Zed60 Rev. 1 (solder), Kaze Mini (hotswap)
* Hardware Availability: [Mechlovin'](https://mechlovin.studio), [NRD](https://nrdesigns.co/products/kaze-mini-pcbs)

Make example for this keyboard (after setting up your build environment):

    make mechlovin/zed60/rev1:default
    make mechlovin/zed60/kaze_mini:default

Flashing example for this keyboard:

    make mechlovin/zed60/kaze_mini:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 4 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
* **Bootloader**: Hold down the key at (0,13) in the matrix (Backspace) and plug in the keyboard
