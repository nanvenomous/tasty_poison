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
[_QWERTY] = LAYOUT_planck_grid(
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
[_SYM] = LAYOUT_planck_grid(
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
[_NUM] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_ASTR, KC_PLUS, _______, KC_PERC, _______,
    _______, _______, _______, _______, _______, _______, KC_CIRC, KC_7,    KC_8,    KC_9,    KC_DLR,  _______,
    _______, _______, _______, _______, _______, _______, KC_MINS, KC_4,    KC_5,    KC_6,    KC_EQL,  KC_COLN,
    _______, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_SLSH, KC_PIPE
),

/* MOV
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Tab  |Enter |      |  PU  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  LT  |  DN  |  UP  |  RT  |  PD  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  BK  | HOME | END  |  DL  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOV] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_TAB,  KC_ENT,  _______, KC_PGUP, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_BSPC, KC_HOME, KC_END,  KC_DEL,  _______
),

/* FUN
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Reset |  F9  |  F10 |  F11 |  F12 |      | Vol- | BRDN | BRUP | Vol+ |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Pr Scr|      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUN] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, _______, _______, _______,
    RESET  , KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_VOLD, KC_BRID, KC_BRIU, KC_VOLU, _______, _______,
    _______, KC_PSCR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
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

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (clockwise) {
      muse_tempo+=1;
    } else {
      muse_tempo-=1;
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

/* LEAD
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |Escape|SftTab| Tab  |Enter |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |Comma |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

LEADER_EXTERNS();

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
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
// KC_COMM ,
    /* SEQ_TWO_KEYS(KC_D, KC_D) { */
    /*   SEND_STRING(SS_LCTL("a") SS_LCTL("c")); */
    /* } */
    /* SEQ_THREE_KEYS(KC_D, KC_D, KC_S) { */
    /*   SEND_STRING("https://start.duckduckgo.com\n"); */
    /* } */
  }
}
