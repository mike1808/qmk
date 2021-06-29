#include "rgb_matrix_ledmaps.h"

__attribute__((weak)) void rgb_matrix_indicators_keymap(void) { return; }
__attribute__((weak)) void rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) { return; }

void rgb_matrix_indicators_user(void) { rgb_matrix_indicators_keymap(); }
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
#ifdef RGB_MATRIX_LEDMAPS_ENABLED

    if (rgb_matrix_is_enabled()) {
        set_layer_rgb(led_min, led_max, get_highest_layer(layer_state | default_layer_state));
    }

#endif  // RGB_MATRIX_LEDMAPS_ENABLED
    rgb_matrix_indicators_advanced_keymap(led_min, led_max);
}

#ifdef RGB_MATRIX_LEDMAPS_ENABLED

void set_layer_rgb(uint8_t led_min, uint8_t led_max, int layer) {
    for (int r = 0; r < MATRIX_ROWS; r++) {
        for (int c = 0; c < MATRIX_COLS; c++) {
            HSV hsv = {
                .h = pgm_read_byte(&ledmaps[layer][r][c][0]),
                .s = pgm_read_byte(&ledmaps[layer][r][c][1]),
                .v = pgm_read_byte(&ledmaps[layer][r][c][2]),
            };

            if (hsv.h || hsv.s || hsv.v) {
                RGB     rgb       = hsv_to_rgb(hsv);
                float   f         = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
                uint8_t led_index = g_led_config.matrix_co[r][c];
                RGB_MATRIX_INDICATOR_SET_COLOR(led_index, f * rgb.r, f * rgb.g, f * rgb.b);
            }
        }
    }
}
#endif  // RGB_MATRIX_LEDMAPS_ENABLED
