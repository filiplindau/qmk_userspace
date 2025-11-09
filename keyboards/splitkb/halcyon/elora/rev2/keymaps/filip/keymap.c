// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <ledmap.h>

/*
enum layers {
    _BASE = 0,
    _NAV,
    _NUM,
    _SYM,
    _FUNCTION,
    _ALT,
};
*/

// Aliases for readability
#define BASE   DF(_BASE)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define NUM      MO(_NUM)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)
#define CTL_BSPC MT(MOD_LCTL, KC_BSPC)
#define NAV_BSPC LT(_NAV, KC_BSPC)
#define NUM_SPC  LT(_NUM, KC_SPC)
#define SYM_RPT  LT(_SYM, QK_REP)
#define FUN_ENT  LT(_FUNCTION, KC_ENT)
#define SYM_ALT  LT(_SYM, M_SYM_ALT)



//
// Macros
//
enum custom_keycodes {
    M_QU = SAFE_RANGE,
    M_CTLBSPC,
    M_SYM_ALT,
    M_COPY,
    M_PASTE,
    M_CUT,
    M_UNDO,
    M_ESC,
    M_LBRC,
    M_RBRC,
    M_LSQB,
    M_RSQB,
    M_LCBR,
    M_RCBR,
    M_EXCL,
    M_QUES,
    M_AT,
    M_HASH,
    M_DLR,
    M_CLN,
    M_SCLN,
    M_PCNT,
    M_AMP,
    M_USCR,
    M_BSLH,
    M_GT,
    M_PIPE,
    M_MINS,
    M_LT,
    M_EQL,
    M_SLSH,
    M_QT,
    M_CIT,
    M_TLD,
    M_POW,
    M_DDD

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_QU:
            if (record->event.pressed) {
                // when keycode M_QU is pressed
                SEND_STRING("qu");
            } else {
                // when keycode M_QU is released
            }
            break;

        case M_CTLBSPC:
            if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_TAP(X_RGHT)) SS_LCTL("\b")); // 
            }
            break;

        case M_SYM_ALT:
            if (record->event.pressed) {
                // Key pressed → start a hold timer
                record->tap.interrupted = false;
                record->tap.count = 0;
                return true;  // allow QMK to track tap vs hold
            } else {
                if (record->tap.count && !record->tap.interrupted) {
                    // TAP → one-shot layer
                    set_oneshot_layer(_ALT, ONESHOT_START);
                } else {
                    // HOLD → already handled by layer_on/off
                }
            }
            return false;

        case M_COPY:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING_DELAY(SS_LCTL("c"), 50);
            } else {
                // when keycode is released
            }
            break;

        case M_CUT:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING_DELAY(SS_LCTL("x"), 50);
            } else {
                // when keycode is released
            }
            break;

        case M_PASTE:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING_DELAY(SS_LCTL("v"), 50);
            } else {
                // when keycode is released
            }
            break;

        case M_UNDO:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING_DELAY(SS_LCTL("z"), 50);
            } else {
                // when keycode is released
            }
            break;

        case M_ESC:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING(SS_TAP(X_ESC));
            } else {
                // when keycode is released
            }
            break;            
        case M_LBRC:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(LSFT(KC_8));
            } else {
                // when keycode is released
            }
            break; 
        case M_RBRC:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(LSFT(KC_9));
            } else {
                // when keycode is released
            }
            break;                  
        case M_LSQB:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(RALT(KC_8));
            } else {
                // when keycode is released
            }
            break; 
        case M_RSQB:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(RALT(KC_9));
            } else {
                // when keycode is released
            }
            break; 
        case M_LCBR:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(RALT(KC_7));
            } else {
                // when keycode is released
            }
            break; 
        case M_RCBR:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(RALT(KC_0));
            } else {
                // when keycode is released
            }
            break;
        case M_EXCL:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(LSFT(KC_1));
            } else {
                // when keycode is released
            }
            break;
        case M_QUES:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(LSFT(KC_MINS));
            } else {
                // when keycode is released
            }
            break;
        case M_AT:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(RALT(KC_2));
            } else {
                // when keycode is released
            }
            break;
        case M_HASH:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(LSFT(KC_3));
            } else {
                // when keycode is released
            }
            break;
        case M_DLR:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(LSFT(KC_4));
            } else {
                // when keycode is released
            }
            break;
        case M_CLN:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(LSFT(KC_DOT));
            } else {
                // when keycode is released
            }
            break;
        case M_SCLN:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(LSFT(KC_COMMA));
            } else {
                // when keycode is released
            }
            break;
        case M_PCNT:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(LSFT(KC_5));
            } else {
                // when keycode is released
            }
            break;
        case M_AMP:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(LSFT(KC_6));
            } else {
                // when keycode is released
            }
            break;
        case M_USCR:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(LSFT(KC_SLSH));
            } else {
                // when keycode is released
            }
            break;
        case M_BSLH:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(RALT(KC_MINS));
            } else {
                // when keycode is released
            }
            break;
        case M_GT:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(KC_NUBS);
            } else {
                // when keycode is released
            }
            break;
        case M_PIPE:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(RALT(KC_NUBS));
            } else {
                // when keycode is released
            }
            break;
        case M_MINS:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(KC_SLSH);
            } else {
                // when keycode is released
            }
            break;
        case M_LT:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(LSFT(KC_NUBS));
            } else {
                // when keycode is released
            }
            break;
        case M_EQL:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(LSFT(KC_0));
            } else {
                // when keycode is released
            }
            break;
        case M_SLSH:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(LSFT(KC_7));
            } else {
                // when keycode is released
            }
            break;
        case M_QT:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(KC_BSLS);
            } else {
                // when keycode is released
            }
            break;
        case M_CIT:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(LSFT(KC_2));
            } else {
                // when keycode is released
            }
            break;
        case M_TLD:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(RALT(KC_RBRC));
                tap_code16(KC_SPC);
            } else {
                // when keycode is released
            }
            break;
        case M_POW:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(LSFT(KC_RBRC));
                tap_code16(KC_SPC);
            } else {
                // when keycode is released
            }
            break;
        case M_DDD:
            if (record->event.pressed) {
                // when keycode is pressed
                tap_code16(KC_RBRC);
            } else {
                // when keycode is released
            }
            break;
    }
    return true;
};


//
// Combos
//
enum combos {
  COMBO_BSPC,
  COMBO_CTLBSPC,
  /*
  COMBO_CUT,
  COMBO_COPY,
  COMBO_PASTE,
  COMBO_UNDO,
  COMBO_ESC,
*/
  COMBO_QU,
  COMBO_OE,
  COMBO_AE,
  COMBO_AA,
  COMBO_CAPSWD,
};
const uint16_t PROGMEM combo_esc[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo_ctlbspc[] = {KC_D, KC_BSPC, COMBO_END};
const uint16_t PROGMEM combo_cut[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_copy[] = {KC_C, KC_L, COMBO_END};
const uint16_t PROGMEM combo_paste[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM combo_undo[] = {KC_L, KC_K, COMBO_END};
const uint16_t PROGMEM combo_qu[] = {KC_Q, KC_J, COMBO_END};
const uint16_t PROGMEM combo_oe[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_ae[] = {KC_A, KC_I, COMBO_END};
const uint16_t PROGMEM combo_aa[] = {KC_COMMA, KC_A, COMBO_END};
const uint16_t PROGMEM combo_capswd[] = {KC_G, KC_COMMA, COMBO_END};
combo_t key_combos[] = {
    [COMBO_CTLBSPC] = COMBO(combo_ctlbspc, M_CTLBSPC), 
    /*
    [COMBO_CUT] = COMBO(combo_cut, LCTL(KC_X)),
    [COMBO_COPY] = COMBO(combo_copy, LCTL(KC_C)),
    [COMBO_PASTE] = COMBO(combo_paste, LCTL(KC_V)),
    [COMBO_UNDO] = COMBO(combo_undo, LCTL(KC_Z)), 
    [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
    */
    [COMBO_QU] = COMBO(combo_qu, M_QU),
    [COMBO_OE] = COMBO(combo_oe, KC_SCLN),
    [COMBO_AE] = COMBO(combo_ae, KC_QUOT),
    [COMBO_AA] = COMBO(combo_aa, KC_LBRC), 
    [COMBO_CAPSWD] = COMBO(combo_capswd, QK_CAPS_WORD_TOGGLE), 
};

#ifdef COMBO_TERM_PER_COMBO
uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {

    // Decide with combo index, i.e. its name from enum.
    switch (combo_index) {
        case COMBO_CTLBSPC:
            return 50;
/*            
        case COMBO_ESC:
            return 30;
        case COMBO_CUT:
            return 30;
        case COMBO_COPY:
            return 30;
        case COMBO_PASTE:
            return 30;
        case COMBO_UNDO:
            return 30;
*/            
        case COMBO_QU:
            return 35;
        case COMBO_OE:
            return 35;
        case COMBO_AE:
            return 35;
        case COMBO_AA:
            return 50;
        case COMBO_CAPSWD:
            return 50;            
    }

    return COMBO_TERM;
}
#endif

//
// Caps word callback
//
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_SLSH:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}


//
// Per-key auto shift
//
uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
    uint16_t t0 = get_generic_autoshift_timeout();
    switch(keycode) {
        case KC_H:
        case KC_R:
            return t0 + 50;
        case KC_N:
        case KC_E:
        case KC_O:
            return t0 + 50;
    }
    switch(keycode) {
        case AUTO_SHIFT_NUMERIC:
            return 2 * t0;
        case AUTO_SHIFT_SPECIAL:
            return t0 + 50;
        case AUTO_SHIFT_ALPHA:
        default:
            return t0;
    }
}

/*
//
//
// RGB Matrix processing
//
//
bool rgb_matrix_indicators_user(void) {
    uint8_t layer = get_highest_layer(layer_state);
    if (layer >= ARRAY_SIZE(layer_colors)) {
        layer = 0;
    }

    for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        rgb_matrix_set_color(
            i,
            layer_colors[layer][i][0],
            layer_colors[layer][i][1],
            layer_colors[layer][i][2]
        );
    }
    return false; // override animations
}
*/

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: HANDS_DOWN
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  |  Esc   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
* |  Tab   |   W  |   F  |   M  |   P  |   V  |                               | Tab  |   .  |   Q  |   J  |   Z  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   R  |   S  |   N  |   T  |   G  |                              |   ,  |   A  |   E  |   I  |   H  |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   X  |   C  |   L  |   D  |   K  | [ {  |CapsLk|  |F-keys|  ¨   |   -  |   U  |   O  |   Y  |   B  | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | Fun/ | Nav/ | Nav  |  | Sym  | Num/ | Sym/ | RGUI | Menu |
 *                        |      |      | Enter| BSPC |      |  |      | Space| Rept |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_BASE] = LAYOUT_elora_hlc(
     KC_ESC  , KC_1 ,  KC_2   ,  KC_3  ,   KC_4 ,   KC_5 ,                                          KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,  KC_0 , KC_ESC ,
     KC_TAB  , KC_W ,  KC_F   ,  KC_M  ,   KC_P ,   KC_V ,                                          KC_TAB,  KC_DOT,  KC_Q ,   KC_J ,  KC_Z , KC_BSPC,
     M_CTLBSPC,KC_R ,  KC_S   ,  KC_N  ,   KC_T ,   KC_G ,                                          KC_COMM, KC_A ,   KC_E ,   KC_I ,  KC_H , CTL_QUOT,
     KC_LSFT , KC_X ,  KC_C   ,  KC_L  ,   KC_D ,   KC_K ,   KC_LBRC,  KC_CAPS,    FKEYS , KC_RBRC, KC_SLSH, KC_U ,   KC_O ,   KC_Y ,  KC_B , KC_RSFT,
                                FKEYS  ,   KC_LGUI, FUN_ENT, NAV_BSPC, NAV   ,     SYM ,   NUM_SPC, SYM_ALT, KC_RGUI, KC_APP,
     KC_MUTE, KC_NO,  KC_NO, KC_NO, KC_NO,                                                                KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO
    ),


/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              | Tab  | Home |   ↑  | End  | PgUp | Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              | Del  |  ←   |   ↓  |   →  | PgDn | Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Bspc | Ent  | Esc  | Ent  | Ins  | PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_NAV] = LAYOUT_elora_hlc(
      _______, M_ESC     ,    _______   ,    _______     ,  _______     ,  _______,                                          _______, _______, _______, _______, _______, _______,
      _______, M_ESC     ,    OSM(MOD_RALT),  _______     ,  _______     ,  _______,                                          KC_TAB, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_DEL,
      _______, OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), _______,                                          KC_DEL, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_INS,
      _______, M_UNDO    ,    M_CUT      ,   M_COPY      ,  M_PASTE     ,  _______, _______, KC_SCRL,       _______, _______,KC_BSPC, KC_ENT , KC_ESC , KC_ENT, KC_INS , KC_PSCR,
                                             _______,       _______,       _______, _______, _______,       _______, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    
/*
 * Num Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_NUM] = LAYOUT_elora_hlc(
      _______, _______     , _______   , _______   , _______   , _______ ,                                       _______,       _______,       _______,       _______,       _______,       _______,
      _______, KC_PSLS     , KC_P7     , KC_P8     , KC_P9     , KC_SLSH,                                        KC_TAB,        KC_DOT,        KC_COMMA,      KC_END,        KC_VOLU,       KC_DEL,
      _______, KC_PAST     , KC_P4     , KC_P5     , KC_P6     , KC_MINUS,                                       KC_DEL ,       OSM(MOD_RSFT), OSM(MOD_RCTL), OSM(MOD_RALT), OSM(MOD_RGUI), KC_INS,
      _______, LSFT(KC_0)  , KC_P1     , KC_P2     , KC_P3     , KC_P0  , _______, KC_SCRL,     _______, _______,KC_SPACE,      KC_E,          KC_X,          KC_MNXT,       KC_MUTE,       KC_PSCR,
                                               _______, _______, _______, _______, _______,     _______, _______, _______,      _______,       _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),
/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_SYM] = LAYOUT_elora_hlc(
      _______, _______,    _______,    _______,    _______,      _______,                                                 _______,    _______,    _______,    _______,       _______,       _______,
      _______, M_EXCL,     M_LCBR,    M_RCBR,      M_CLN,       M_SCLN,                                                   M_AT,       M_HASH,    M_DLR,       M_USCR,        M_BSLH,        _______,
      _______, M_LSQB,     M_LBRC,    M_RBRC,      M_RSQB,      M_QUES,                                                   M_PCNT,     M_GT,      M_PIPE,      M_MINS,        M_LT,          _______,
      _______, M_AMP,      M_POW,     M_TLD,       M_QT,        M_CIT,         _______,  _______,       _______, _______, M_EQL,      KC_MINS,   KC_SLSH,     M_DDD,         M_SLSH,    _______,
                                      _______,     _______,     _______,       _______,  _______,       _______, _______, _______,    _______,   _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_FUNCTION] = LAYOUT_elora_hlc(
      _______, _______   ,    _______   ,    _______     ,  _______     ,  _______,                                          _______, _______, _______, _______, _______, _______,
      _______, M_ESC     ,    _______   ,    _______     ,  _______     ,  _______,                                          _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,
      _______, OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), _______,                                          _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,
      _______, _______ ,      OSM(MOD_RALT), _______     ,  _______     ,  _______, _______, KC_SCRL,       _______, _______,_______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______,
                                             _______,       _______,       _______, _______, _______,       _______, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                                                    _______, _______, _______, _______, _______
),

/*
 * Alt Layer: Alt keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_ALT] = LAYOUT_elora_hlc(
      _______, _______   ,    _______   ,    _______     ,  _______     ,  _______,                                          _______, _______, _______, _______, _______, _______,
      _______, _______   ,    _______   ,    _______     ,  _______     ,  _______,                                          _______, _______, _______, _______, _______, _______,
      _______, OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), _______,                                          _______, KC_LBRC, KC_QUOT, _______, _______, _______,
      _______, _______ ,      OSM(MOD_RALT), _______     ,  _______     ,  _______, _______, KC_SCRL,       _______, _______,_______, _______, KC_SCLN, _______, _______, _______,
                                             _______,       _______,       _______, _______, _______,       _______, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                                                    _______, _______, _______, _______, _______
),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  * ,-----------------------------------.                                              ,-----------------------------------.
//  * |      |      |       |      |      |                                              |      |      |       |      |      |
//  * `-----------------------------------'                                              `-----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT_elora_hlc(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//      _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
//     ),
//
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
    [1] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [2] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [3] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [4] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [5] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
};
#endif
