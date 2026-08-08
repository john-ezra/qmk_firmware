# Manta 65

![Manta 65](https://i.imgur.com/jcNcx2g.png)

The Manta 65 is a 65% keyboard designed by Bowl and Alexotos. The PCB was designed by Gondolindrim, who is also the firmware maintainer. Both PCB variants use an STM32F072 microcontroller.

* Keyboard Maintainer: [Gondolindrim](https://github.com/Gondolindrim)
* Hardware Supported: Manta 65H hotswap and Manta 65S solder PCBs
* Hardware Availability: The Manta 65 group buy ended in May 2026.

Make example for this keyboard (after setting up your build environment):

    make bowl/manta65/<version>:default

Where `version` is either `manta65s` for solder or `manta65h` for hotswap.

After building or downloading the firmware, put the PCB into DFU mode by holding the reset button for at least five seconds and upload the firmware with a utility such as `dfu-util` or QMK Toolbox. Alternatively, build and flash with:

    make bowl/manta65/<version>:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with the [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
