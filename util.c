#include "util.h"
#include "rgb_matrix.h"

void store_rgb_state_to_eeprom() {
    uint8_t mode  = rgb_matrix_get_mode();
    HSV     color = rgb_matrix_get_hsv();

    rgb_matrix_mode(mode);
    rgb_matrix_sethsv(color.h, color.s, color.v);
}
