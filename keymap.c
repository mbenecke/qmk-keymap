/* Copyright 2022 Marco Benecke
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "sendstring_german.h"

uint8_t mod_state;

enum custom_keycodes { MB_LBRC = SAFE_RANGE, MB_RBRC, MB_SCLN, MB_PLEQ, MB_SLASH, MB_BACKSLASH };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {
        case MB_LBRC:
            if (record->event.pressed) {
                // when keycode MB_LBRC is pressed
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING("{}" SS_TAP(X_LEFT));
                    // Reapplying modifier state
                    set_mods(mod_state);
                    return false;
                } else {
                    SEND_STRING("[]" SS_TAP(X_LEFT));
                }
            }
            break;

        case MB_RBRC:
            if (record->event.pressed) {
                // when keycode MB_RBRC is pressed
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING("}" SS_TAP(X_LEFT));
                    // Reapplying modifier state
                    set_mods(mod_state);
                    return false;
                } else {
                    SEND_STRING("]" SS_TAP(X_LEFT));
                    return false;
                }
            } else {
                // when keycode MB_RBRC is released
            }
            break;

        case MB_SCLN:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(":");
                    set_mods(mod_state);
                    return false;
                } else {
                    SEND_STRING(";");
                    return false;
                }
            }
            break;

        case KC_2:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING("@");
                    set_mods(mod_state);
                    return false;
                }
            }
            break;

        case KC_3:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING("#");
                    set_mods(mod_state);
                    return false;
                }
            }
            break;

        case KC_6:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING("^");
                    set_mods(mod_state);
                    return false;
                }
            }
            break;

        case KC_7:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING("&");
                    set_mods(mod_state);
                    return false;
                }
            }
            break;

        case KC_8:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING("*");
                    set_mods(mod_state);
                    return false;
                }
            }
            break;

        case KC_9:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING("(");
                    set_mods(mod_state);
                    return false;
                }
            }
            break;

        case KC_0:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(")");
                    set_mods(mod_state);
                    return false;
                }
            }
            break;

        case MB_PLEQ:
            if (record->event.pressed) {
                // when keycode MB_LBRC is pressed
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING("+");
                    // Reapplying modifier state
                    set_mods(mod_state);
                    return false;
                } else {
                    SEND_STRING("=");
                }
            }
            break;

        case MB_SLASH:
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING("?");
                    // Reapplying modifier state
                    set_mods(mod_state);
                    return false;
                } else {
                    SEND_STRING("/");
                }
            }
            break;

        case MB_BACKSLASH:
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING("|");
                    // Reapplying modifier state
                    set_mods(mod_state);
                    return false;
                } else {
                    SEND_STRING("\\");
                }
            }
            break;

        case KC_BSPC:
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_LSFT(SS_TAP(X_INSERT)));
                    // Reapplying modifier state
                    set_mods(mod_state);
                    return false;
                }
            }
            break;

        case KC_A:
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_ALT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_ALT);
                    SEND_STRING(SS_TAP(X_QUOT));
                    // Reapplying modifier state
                    set_mods(mod_state);
                    return false;
                }
            }
            break;
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
        case KC_U:
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_ALT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_ALT);
                    SEND_STRING(SS_TAP(X_LBRC));
                    // Reapplying modifier state
                    set_mods(mod_state);
                    return false;
                }
            }
            break;
        case KC_S:
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_ALT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_ALT);
                    SEND_STRING(SS_TAP(X_MINS));
                    // Reapplying modifier state
                    set_mods(mod_state);
                    return false;
                }
                break;
            }
        case KC_COMM:
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_TAP(X_NUBS));
                    // Reapplying modifier state
                    set_mods(mod_state);
                    return false;
                }
            }
            break;
        case KC_DOT:
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(SS_LSFT(SS_TAP(X_NUBS)));
                    // Reapplying modifier state
                    set_mods(mod_state);
                    return false;
                }
            }
            break;
    }
    return true;
};

#define DVORAK 0 // Base Dvorak
#define QWERTZ 2 // qwertz

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[DVORAK] = LAYOUT(KC_EQL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, DE_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, DE_Y, KC_ESC, KC_A, KC_O, KC_E, KC_U, KC_I, KC_LSFT, MB_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_GRV, MB_BACKSLASH, KC_LEFT, KC_RGHT, KC_LCTL, KC_LALT, TO(QWERTZ), KC_BSPC, KC_DEL, KC_END, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SCROLL_LOCK, KC_PAUS, KC_NO, QK_BOOT, KC_6, KC_7, KC_8, KC_9, KC_0, MB_PLEQ, KC_F, KC_G, KC_C, KC_R, KC_L, MB_SLASH, KC_D, KC_H, KC_T, KC_N, KC_S, DE_MINS, KC_B, KC_M, KC_W, KC_V, DE_Z, KC_RSFT, KC_UP, KC_DOWN, MB_LBRC, MB_RBRC, KC_LWIN, KC_RALT, KC_PGUP, KC_PGDN, KC_ENTER, KC_SPC),

                                                              [QWERTZ] = LAYOUT(KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_ESCAPE, KC_A, KC_S, KC_D, KC_F, KC_G, KC_LSFT, DE_Y, KC_X, KC_C, KC_V, KC_B, KC_GRV, KC_INS, KC_LEFT, KC_RGHT, KC_LCTL, KC_LALT, TO(DVORAK), KC_BSPC, KC_DEL, KC_END, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SCROLL_LOCK, KC_PAUS, KC_NO, QK_BOOT, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, DE_Z, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DOWN, KC_LBRC, KC_RBRC, KC_LWIN, KC_RALT, KC_PGUP, KC_PGDN, KC_ENTER, KC_SPC)};
