# Merisi Sessantacinque

Mechlovin' Hannah65 Rev. 1 PCB as shipped in the Merisi Works Sessantacinque, a 65% keyboard sold in WK and WKL cases. It is the Haus Rev. 1 PCB with the USB product string changed. Mechlovin' never merged the source upstream; this port follows the `merisi` branch of their fork and the VIA definition behind their `mechlovin_hannah65_rev1_sessantacinque_via.bin`, which adds the 7u bottom row the Haus definition lacked.

* Keyboard Maintainer: [Team Mechlovin](https://github.com/mechlovin)
* Hardware Supported: Merisi Sessantacinque (Hannah65 Rev. 1), STM32F303
* Hardware Availability: [Merisi Works](https://merisi.works/collections/merisi-sessantacinque)

Make example for this keyboard (after setting up your build environment):

    make mechlovin/hannah65/rev1/sessantacinque:default

Flashing example for this keyboard:

    make mechlovin/hannah65/rev1/sessantacinque:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
