# Planck Layout

this github repo is dedicated to a custom planck assembly and layout by Matthew Garelli

![planck build picture](./rsrc/keeb.png)

# Installation

### [Documentation](https://docs.qmk.fm)

### Setup

```
yay -Sy qmk
qmk setup mrgarelli/qmk_firmware
```

# Building and Developemnt

- path to current configuration

```
./keyboards/planck/keymaps/ergo
```

- command to compile only

```
qmk compile -kb planck/rev6 -km nanvenomous
qmk compile -kb keebio/nyquist/rev3 -km nanvenomous
```

- command to flash (board must be in reset mode)

```
qmk flash -kb planck/rev6 -km nanvenomous
qmk flash -kb keebio/nyquist/rev3 -km nanvenomous
```

# Other Resources

[standard qmk keycodes](https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md)

[all unicode symbols](https://fsymbols.com/keyboard/linux/compose/)

### Quantum Mechanical Keyboard Firmware

This is a keyboard firmware based on the [tmk_keyboard firmware](https://github.com/tmk/tmk_keyboard) with some useful features for Atmel AVR and ARM controllers.

### Supported Keyboards

- [Planck](/keyboards/planck/)
- [Preonic](/keyboards/preonic/)
- [ErgoDox EZ](/keyboards/ergodox_ez/)
- [Clueboard](/keyboards/clueboard/)
- [Cluepad](/keyboards/clueboard/17/)
- [Atreus](/keyboards/atreus/)

### Maintainers

QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The OLKB product firmwares are maintained by [Jack Humbert](https://github.com/jackhumbert), the Ergodox EZ by [ZSA Technology Labs](https://github.com/zsa), the Clueboard by [Zach White](https://github.com/skullydazed), and the Atreus by [Phil Hagelberg](https://github.com/technomancy).

### [Official Website](https://qmk.fm)
