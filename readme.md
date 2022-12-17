# mbenecke keyboard firmware

The controller board hardware is described
[here](http://michael.stapelberg.de/Artikel/kinesis_custom_controller)

This keymap emulates most keys of the Dvorak International layout on PCs that have German set as input language.
This allows the use of the keyboard on any PC in Germany without the need to change any settings. 
The default layer is a modified version of [Dvorak International](http://arjenvankol.com/dvorak.php) credits to Arjen van Kol

I used as an additional layer the default german _querz_ keymap, just in case

## Building the Hardware

For this I followed 100% the [kinT](https://github.com/kinx-project/kint) description for my Kinesis Advantage (KB500) with a [Teensy 4.1](https://www.pjrc.com/store/teensy41.html)

## Keymaps

### Default

To build with the default keymap, run `make kinesis/mbenecke` while in the QMK directory.


