# mbenecke keyboard firmware

The controller board hardware is described
[here](http://michael.stapelberg.de/Artikel/kinesis_custom_controller)

This keymap emulates most keys of the Dvorak International layout on PCs that have German set as input language.
This allows the use of the keyboard on any PC in Germany without the need to change any settings. 
The default layer is a modified version of [Dvorak International](http://arjenvankol.com/dvorak.php) credits to Arjen van Kol

I used as an additional layer the default german _querz_ keymap, just in case, which is not tested completely. Maybe a future project

## Building the Hardware

For this I followed 100% the [kinT](https://github.com/kinx-project/kint) description for my Kinesis Advantage (KB500) with a [Teensy 4.1](https://www.pjrc.com/store/teensy41.html)

## Keymaps

### Default

To build with the default keymap, run `make kinesis/mbenecke` while in the QMK directory.

### Documentation

The Basic Idea of the Keymap is from [Arjen van
Kol](http://arjenvankol.com/img/dvorakie.png) Not fully implemented in this
keymap, cause I am too lazy. I am a German (native) I need only this
[Layout](https://kbdlayout.info/kbdgr ).

### How to get German Umlauts in QMK 

The `SEND_STRING()` funktion is a bit piky and does not like to send special Keymaps, to implement a german Umlaut. I used this Workflow:
1. First check the keymap_german.h for the character: https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_german.h
2. Lets use for example this

```C
#define DE_ODIA KC_SCLN // Ö
```

   as you can see here, the Keyboard sends a `KC_SCLN` to the OS, which then
   interpreted it as character <kbd>ö</kbd> and if you send `LSHIFT + KC_SCLN` it
   is interpreted as <kbd>Ö</kbd>

3. Next is the `send_string_keycodes.h` https://github.com/qmk/qmk_firmware/blob/master/quantum/send_string/send_string_keycodes.h

```C
#define X_SCLN X_SEMICOLON
```
   
   as you can read in https://docs.qmk.fm/#/feature_send_string?id=keycodes 

> All of the keycodes in the Basic Keycode range are supported (as these are
> the only ones that will actually be sent to the host), but with an X_
> prefix instead of KC_.
    
    
4. I implemented a Macro in my Keymap this way

```C
case KC_O:
  if (record->event.pressed) {
    // Detect the activation of either shift keys
    if (mod_state & MOD_MASK_ALT) {
       // First temporarily canceling both shifts so that
       // shift isn't applied to the KC_DEL keycode
       del_mods(MOD_MASK_ALT);
       SEND_STRING(SS_TAP(X_SCLN));
       // Reapplying modifier state
       set_mods(mod_state);
       return false;
       }
    }
    break;
```
        
I have no Idea if this is a good Practice or even if it will be work in future QMK releases. But for me **it operates fine**, at the moment.

## Research
I made some experiments in `send_unicode_string` but it is not possible to use it in my special case:
- no change in the OS regarding keyboard layout
- no installation of autohotkey or wincompose.
- no change to the language of the workstation
- both target OS (Windows, Linux) are treated similar 

## Future Targets
- I like to use the 4 capslook/numlock/… LED’s to signal some state
- Add a layer for running coding short cuts, like `SEND_STRING("git pull")` or dynamic macros 
- Add a third layer which is used for Media Keys or browser control
- I would like to implement also some **RGB** lights. 

## Disclaimer

- I use the Teensy 4.1, so I do not really care regarding the Performance of the Code nor the needed Memory.
- That the Keyboard operates in the current state costs me nearly one year of
  gathering knowledge and experience in a wide range of special Skills. If it is
  not running for you after a Weekend of tinkering, don’t give up, it is possible. 
- it is not a budget solution, yes it is cheaper than buying the (Kinesis
  Advantage 356)[https://kinesis-ergo.com/keyboards/advantage360/] but only if
  do not like to count the working hours and frustration days. 
  So be warned.
