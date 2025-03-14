/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_POINTER,
};

enum custom_keycodes {
     PRNTSCR_MACRO = SAFE_RANGE,
     IDE_B_MACRO,
     IDE_F_MACRO,
     IDE_GO_EDIT_MACRO
 };


 bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     switch (keycode) {
         case PRNTSCR_MACRO:
             if (record->event.pressed) {
                 register_code(KC_LSFT);
                 register_code(KC_LCMD);
                 tap_code(KC_4);
                 unregister_code(KC_LSFT);
                 unregister_code(KC_LCMD);
             }
             return false;
 
         case IDE_B_MACRO:
             if (record->event.pressed) {
                 register_code(KC_LALT);
                 register_code(KC_LCMD);
                 tap_code(KC_LEFT);
                 unregister_code(KC_LALT);
                 unregister_code(KC_LCMD);
             }
             return false;
 
         case IDE_F_MACRO:
             if (record->event.pressed) {
                 register_code(KC_LALT);
                 register_code(KC_LCMD);
                 tap_code(KC_RIGHT);
                 unregister_code(KC_LALT);
                 unregister_code(KC_LCMD);
             }
             return false;
 
         case IDE_GO_EDIT_MACRO:
             if (record->event.pressed) {
                 register_code(KC_LSFT);
                 register_code(KC_LCMD);
                 tap_code(KC_BSPC);
                 unregister_code(KC_LSFT);
                 unregister_code(KC_LCMD);
             }
             return false;
     }
     return true;
}


/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_LCMD LT(LAYER_LOWER, KC_LGUI)
#define PT_RCMD MT(MOD_RGUI, KC_ENT)
#define PT_BCSPC LT(LAYER_LOWER, KC_BSPC)
#define PT_SPC LT(LAYER_LOWER, KC_SPC)
#define PT_TAB LT(LAYER_RAISE, KC_TAB)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)

#define HM_LGUI MT(MOD_LGUI, KC_D)  // Left GUI when held, 'D' when tapped
#define HM_LALT MT(MOD_LALT, KC_S)  // Left Alt when held, 'S' when tapped
#define HM_LCTL MT(MOD_LCTL, KC_A)  // Left Ctrl when held, 'A' when tapped
#define HM_LSFT MT(MOD_LSFT, KC_F)  // Left Shift when held, 'F' when tapped

#define HM_RSFT MT(MOD_RSFT, KC_J)  // Right Shift when held, 'J' when tapped
#define HM_RCTL MT(MOD_RCTL, KC_SCLN)  // Right Ctrl when held, ';' when tapped
#define HM_RALT MT(MOD_RALT, KC_L)  // Right Alt when held, 'L' when tapped
#define HM_RGUI MT(MOD_RGUI, KC_K)  // Right GUI when held, 'K' when tapped

// #define HM_LGUI HOLD_TAP(KC_D, MOD_LGUI, TAPPING_TERM)
// #define HM_LALT HOLD_TAP(KC_S, MOD_LALT, TAPPING_TERM)
// #define HM_LCTL HOLD_TAP(KC_A, MOD_LCTL, TAPPING_TERM)
// #define HM_LSFT HOLD_TAP(KC_F, MOD_LSFT, TAPPING_TERM)

// #define HM_RSFT HOLD_TAP(KC_J, MOD_RSFT, TAPPING_TERM)
// #define HM_RCTL HOLD_TAP(KC_SCLN, MOD_RCTL, TAPPING_TERM)
// #define HM_RALT HOLD_TAP(KC_L, MOD_RALT, TAPPING_TERM)
// #define HM_RGUI HOLD_TAP(KC_K, MOD_RGUI, TAPPING_TERM)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       RGB_TOG,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_MNXT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_VOLU,    HM_LCTL, HM_LALT, HM_LGUI, HM_LSFT, KC_G,       KC_H,    HM_RSFT, HM_RGUI, HM_RALT, HM_RCTL, KC_MPLY,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_VOLD,    PT_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, PT_SLSH, KC_MPRV,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  PT_TAB,  PT_SPC,  KC_LGUI,   PT_RCMD,  PT_BCSPC
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭────────────────────────────────────────-──────────────╮
       XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,       KC_7,    KC_8,    KC_9,   KC_0, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, HM_LCTL, HM_LALT, HM_LGUI, HM_LSFT, XXXXXXX,    KC_LEFT,    KC_DOWN,  KC_UP,   KC_RGHT, KC_PMNS, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  EE_CLR, QK_BOOT,    KC_HOME,    KC_PGDN,  KC_PGUP, KC_END, CW_TOGG, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, _______,    XXXXXXX, _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, KC_EXCLAIM, KC_AT, KC_HASH, KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_PAST, KC_LBRC, KC_RBRC, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_F1,      KC_F2,  KC_F3,   KC_F4, KC_F5,      KC_MINUS, KC_EQUAL, KC_LT, KC_GT, KC_TILDE, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_F6,      KC_F7,   KC_F8,  KC_F9, KC_F10,    KC_UNDS,  KC_PLUS, KC_PIPE, KC_LCBR, KC_RCBR, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, XXXXXXX,    _______, XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       QK_BOOT,  EE_CLR, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX,  EE_CLR, QK_BOOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, HM_LCTL, HM_LALT, HM_LGUI, HM_LSFT, XXXXXXX,    XXXXXXX, HM_RSFT, HM_RGUI, HM_RALT, HM_RCTL, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, DRGSCRL, SNIPING, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, SNIPING, DRGSCRL, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_BTN3, KC_BTN1
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif

const uint16_t PROGMEM esc_combo[] = {KC_Q, HM_LCTL, COMBO_END};
const uint16_t PROGMEM lpar_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM rpar_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM lbkt_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM rbkt_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM lbrc_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM rbrc_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM grave_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM tilda_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM quot_combo[] = {KC_P, HM_RCTL, COMBO_END};
const uint16_t PROGMEM lower_combo[] = {PT_RCMD,  PT_BCSPC, COMBO_END};

const uint16_t PROGMEM prntscr_combo[] = {KC_R, KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM ide_b_combo[] = {KC_Q, HM_LCTL, KC_Z, COMBO_END};
const uint16_t PROGMEM ide_f_combo[] = {KC_SCLN, KC_P, KC_SLSH, COMBO_END};
const uint16_t PROGMEM ide_go_edit_combo[] = {KC_P, KC_O, KC_I, COMBO_END};

combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(lower_combo, LOWER),
    COMBO(lpar_combo, KC_LPRN),
    COMBO(rpar_combo, KC_RPRN),
    COMBO(lbkt_combo, KC_LBRC),
    COMBO(rbkt_combo, KC_RBRC),
    COMBO(lbrc_combo, KC_LCBR),
    COMBO(rbrc_combo, KC_RCBR),
    COMBO(grave_combo, KC_GRV),
    COMBO(tilda_combo, KC_TILD),
    COMBO(quot_combo, KC_QUOT),
    COMBO(prntscr_combo, PRNTSCR_MACRO),
    COMBO(ide_b_combo, IDE_B_MACRO),
    COMBO(ide_f_combo, IDE_F_MACRO),
    COMBO(ide_go_edit_combo, IDE_GO_EDIT_MACRO)
};