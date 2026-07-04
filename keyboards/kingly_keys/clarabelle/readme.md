# Clarabelle

![Clarabelle](https://i.imgur.com/l5ah6uMl.png)

A compact, staggered keyboard by Kingly-Keys (Garret Gartner). This QMK port is
derived from the publicly released Clarabelle firmware and VIA definition.

* Keyboard Maintainer: [ezra](https://github.com/john-ezra)
* Hardware Supported: Clarabelle PCB (ATmega32U4)
* Hardware Availability: Group buy / open-source files

Make example for this keyboard (after setting up your build environment):

    make kingly_keys/clarabelle:default

Flashing example for this keyboard:

    make kingly_keys/clarabelle:default:flash

To reset the board into bootloader mode, press the dedicated reset key
(bottom-right position) or the `QK_BOOT` keycode on the function layer.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools)
and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for
more information. Brand new to QMK? Start with our
[Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
