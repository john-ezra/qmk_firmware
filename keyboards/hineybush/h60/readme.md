# h60

![h60](https://live.staticflickr.com/65535/49952697531_2efeaa0bd6_k.jpg)

A GH60 form factor PCB for 60% keyboards. Uses a USB Type C connector. The matrix supports split backspace, ANSI or ISO enter, ANSI or ISO left shift, split right shift, and 6.25u, 7u, HHKB, or split space bottom rows. `standard` is the bare PCB; `korsa_mini` and `moontower` are the same PCB as built into the Merisi Works Korsa Mini and the ATXKB Moontower, differing only in their USB product string.

* Keyboard Maintainer: [hineybush](https://github.com/hineybush)
* Hardware Supported: h60 (standard, Korsa Mini, Moontower)
* Hardware Availability: [hiney.cc](https://hiney.cc), [ATXKB Moontower kit](https://atxkb.com/moontower-v3-kit-jan-2024/)

Make example for this keyboard (after setting up your build environment):

    make hineybush/h60/standard:default
    make hineybush/h60/korsa_mini:default
    make hineybush/h60/moontower:default

Flashing example for this keyboard:

    make hineybush/h60/moontower:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
