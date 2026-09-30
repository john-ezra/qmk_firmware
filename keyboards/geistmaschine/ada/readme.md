# Ada

Ada is a HHKB style keyboard, reinventing tray mount for an optimal typing experience and easy assembly.

* Keyboard Maintainer: [ebastler](https://github.com/ebastler)
* Hardware Supported: Ada rev1
* Hardware Availability: [geistmaschine.io](https://geistmaschine.io/)

Make example for this keyboard (after setting up your build environment):

    qmk compile -kb geistmaschine/ada -km default

Flashing example for this keyboard:

    qmk flash -kb geistmaschine/ada -km default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (Escape) and plug in the keyboard
* **Physical reset button**: Briefly short the two pads marked "RESET" on the back of the PCB
