# Hannah65 Rev. 1

![hannah65](https://i.imgur.com/qf0BYI2l.png)

Mechlovin' 65% PCB on an STM32F303 with the STM32 ROM DFU bootloader. The matrix supports split backspace, ANSI or ISO enter, ANSI or ISO left shift, and 6.25u or 7u bottom rows, with a caps lock indicator and single colour backlight. Rev. 1 ships under two names that differ only in their USB product string: `haus` for the Hand Engineering Haus and `sessantacinque` for the Merisi Works Sessantacinque.

* Keyboard Maintainer: [Team Mechlovin](https://github.com/mechlovin)
* Hardware Supported: Hannah65 Rev. 1 (Haus, Merisi Sessantacinque), STM32F303
* Hardware Availability: [Mechlovin' Studio](https://mechlovin.studio)

Make example for this keyboard (after setting up your build environment):

    make mechlovin/hannah65/rev1/haus:default
    make mechlovin/hannah65/rev1/sessantacinque:default

Flashing example for this keyboard:

    make mechlovin/hannah65/rev1/sessantacinque:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
