/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

void doubletap_ug_toggle(tap_dance_state_t *state, void *user_data);
void doubletap_qk_boot(tap_dance_state_t *state, void *user_data);

enum {
  TD_UG_TOGG,
  TD_QK_BOOT,
};

tap_dance_action_t tap_dance_actions[] = {
  [TD_UG_TOGG] = ACTION_TAP_DANCE_FN(doubletap_ug_toggle),
  [TD_QK_BOOT] = ACTION_TAP_DANCE_FN(doubletap_qk_boot),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // base
  [0] = LAYOUT_split_3x6_3_ex2
  (
   // Row 1, left
   KC_NO, KC_Q, KC_W, KC_F, KC_P, KC_B, QK_BOOT,
   // Row 1, right
   UG_NEXT, KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_NO,

   // Row 2, left
   KC_NO, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G, KC_NO,
   // Row 2, right
   UG_TOGG, KC_M, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), KC_NO,

   // Row 3, left
   KC_NO, KC_Z, KC_X, KC_C, KC_D, KC_V,
   // Row 3, right
   KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_NO,

   // Thumb left
   KC_ESC, LT(2, KC_TAB), KC_SPC,
   // Thumb right
   KC_ENT, LT(1, KC_BSPC), KC_DEL
  ),

  // Num
  [1] = LAYOUT_split_3x6_3_ex2
  (
   // Row 1, left
   KC_NO, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, KC_NO,
   // Row 1, right
   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TD(TD_QK_BOOT), KC_NO,

   // Row 2, left
   KC_NO, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL, KC_NO,
   // Row 2, right
   KC_NO, KC_NO, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO,

   // Row 3, left
   KC_NO, KC_GRV, KC_1, KC_2, KC_3, KC_BSLS,
   // Row 3, right
   KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_ESC,

   // Thumb left
   KC_DOT, KC_0, KC_MINUS,
   // Thumb right
   KC_TRNS, KC_TRNS, KC_TRNS
   ),

  // Nav
  [2] = LAYOUT_split_3x6_3_ex2
  (
   // Row 1, left
   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
   // Row 1, right
   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

   // Row 2, left
   KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, KC_NO,
   // Row 2, right
   KC_NO, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,

   // Row 3, left
   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
   // Row 3, right
   KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO,

   // Thumb left
   KC_TRNS, KC_TRNS, KC_TRNS,
   // Thumb right
   KC_TRNS, KC_TRNS, KC_TRNS
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif

void doubletap_ug_toggle(tap_dance_state_t *state, void *user_data) {
  if (state->count >= 2) {
    rgblight_toggle();
    reset_tap_dance(state);
  }
}

void doubletap_qk_boot(tap_dance_state_t *state, void *user_data) {
  if (state->count >= 2) {
    reset_keyboard();
    reset_tap_dance(state);
  }
}
