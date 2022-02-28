# mbenecke keyboard firmware

The controller board hardware is described
[here](http://michael.stapelberg.de/Artikel/kinesis_custom_controller)

The default layer is a modified version of [Dvorak International](http://arjenvankol.com/dvorak.php) credits to Arjen van Kol

I used as an additional layer the default german _querz_ keymap, just in case

## Building the Hardware

For this I followed 100% the [kinT](https://github.com/kinx-project/kint) description for my Kinesis Advantage (KB500) with a [Teensy 4.1](https://www.pjrc.com/store/teensy41.html)

## Keymaps

### Default

To build with the default keymap, run `make kinesis/mbenecke` while in the QMK directory.


