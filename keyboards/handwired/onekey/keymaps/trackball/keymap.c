#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {LAYOUT_ortho_1x1(KC_A)};

// void pointing_device_init_kb(void) {
//     pmw33xx_init(0);
//     pmw33xx_set_cpi(0, 3000);
//     pointing_device_init_user();
// }
