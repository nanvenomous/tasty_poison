/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _SYM,
  _NUM,
  _MOV,
  _FUN,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
};


#define SYM MO(_SYM)
#define NUM MO(_NUM)

#define MOV MO(_MOV)
#define FUN MO(_FUN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Ctrl | Alt  | GUI  | NUM  |Shift | MOV  | TAB  |Shift | SYM  | GUI  | Alt  | Ctrl |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |Space |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | CAPS |   Z  |   X  |   C  |   V  |   B  |   N  |   M  | LEAD |   .  |   ;  | FUN  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_LCTL, KC_LALT, KC_LGUI, NUM,     KC_LSFT, MOV,     KC_TAB,  KC_RSFT, SYM,     KC_RGUI, KC_RALT, KC_RCTL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SPC,  KC_ENT,
    KC_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_LEAD, KC_DOT,  KC_SCLN, FUN
),

/* SYM
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   !  |   @  |   {  |   }  |   _  |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   '  |   "  |   (  |   )  |   #  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   \  |   ?  |   [  |   ]  |   &  |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    KC_GRV,  KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_UNDS, _______, _______,  _______,  _______, _______, _______,
    KC_TILD, KC_QUOT, KC_DQT,  KC_LPRN, KC_RPRN, KC_HASH, _______, _______,  _______,  _______, _______, _______,
    _______, KC_BSLS, KC_QUES, KC_LBRC, KC_RBRC, KC_AMPR, _______, _______,  _______,  _______, _______, _______
),

/* NUM
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   *  |   +  |      |   %  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |   ^  |   7  |   8  |   9  |   $  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |   -  |   4  |   5  |   6  |   =  |  :   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   0  |   1  |   2  |   3  |   /  |  |   |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, KC_ASTR, KC_PLUS, _______, KC_PERC, _______,
    _______, _______, _______, _______, _______, _______, KC_CIRC, KC_7,    KC_8,    KC_9,    KC_DLR,  _______,
    _______, _______, _______, _______, _______, _______, KC_MINS, KC_4,    KC_5,    KC_6,    KC_EQL,  KC_COLN,
    _______, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_SLSH, KC_PIPE
),

/* MOV
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |  PU  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  LT  |  DN  |  UP  |  RT  |  PD  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  BK  | HOME | END  |  DL  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOV] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_TAB,  KC_ENT,  _______, KC_PGUP, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_BSPC, KC_HOME, KC_END,  KC_DEL,  _______
),

/* FUN
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      | Vol- | BRDN | BRUP | Vol+ |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Reset |  F9  |  F10 |  F11 |  F12 |      |      |      | Play | Next |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Pr Scr|      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUN] = LAYOUT_ortho_4x12(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, KC_VOLD, KC_BRID, KC_BRIU, KC_VOLU, _______, _______,
    RESET  , KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, KC_MPLY, KC_MNXT, _______, _______,
    _______, KC_PSCR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

#ifdef AUDIO_ENABLE
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
      register_code(KC_TAB);
      unregister_code(KC_TAB);
    }
    SEQ_ONE_KEY(KC_G) {
      register_code(KC_ENT);
      unregister_code(KC_ENT);
    }
    SEQ_ONE_KEY(KC_D) {
      register_code(KC_LSFT);
      register_code(KC_TAB);
      unregister_code(KC_TAB);
      unregister_code(KC_LSFT);
    }
    SEQ_ONE_KEY(KC_S) {
      register_code(KC_ESC);
      unregister_code(KC_ESC);
    }
    SEQ_ONE_KEY(KC_LEAD) {
      register_code(KC_COMM);
      unregister_code(KC_COMM);
    }
  }
}

