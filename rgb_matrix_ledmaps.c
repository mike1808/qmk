#include "rgb_matrix_ledmaps.h"

__attribute__((weak)) void rgb_matrix_indicators_keymap(void) { return; }

void rgb_matrix_indicators_user(void) {
#ifdef RGB_MATRIX_LEDMAPS_ENABLED

    if (rgb_matrix_is_enabled()) {
        set_layer_rgb(get_highest_layer(layer_state | default_layer_state));
    }

    rgb_matrix_indicators_keymap();
#endif  // RGB_MATRIX_LEDMAPS_ENABLED
}
#ifdef RGB_MATRIX_LEDMAPS_ENABLED

void set_layer_rgb(int layer) {
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
                rgb_matrix_set_color(led_index, f * rgb.r, f * rgb.g, f * rgb.b);
            }
        }
    }
}
#endif  // RGB_MATRIX_LEDMAPS_ENABLED
