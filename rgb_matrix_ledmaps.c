#include "rgb_matrix_ledmaps.h"

__attribute__((weak)) void rgb_matrix_indicators_keymap(void) { return; }
__attribute__((weak)) void rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) { return; }

#ifdef RGB_MATRIX_LEDMAPS_ENABLED

static bool enabled = true;

#endif  // RGB_MATRIX_LEDMAPS_ENABLED

void rgb_matrix_indicators_user(void) { rgb_matrix_indicators_keymap(); }
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
#ifdef RGB_MATRIX_LEDMAPS_ENABLED

    if (rgb_matrix_is_enabled() && enabled) {
        set_layer_rgb(led_min, led_max, get_highest_layer(layer_state | default_layer_state));
    }

#endif  // RGB_MATRIX_LEDMAPS_ENABLED
    rgb_matrix_indicators_advanced_keymap(led_min, led_max);
}

#ifdef RGB_MATRIX_LEDMAPS_ENABLED

void set_layer_rgb(uint8_t led_min, uint8_t led_max, int layer) {
    const rgb_matrix_layer *l = &ledmaps[layer];

    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = (l->layout[i][0]),
            .s = (l->layout[i][1]),
            .v = (l->layout[i][2]),
        };

        if (hsv.h || hsv.s || hsv.v) {
            RGB     rgb       = hsv_to_rgb(hsv);
            float   f         = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            RGB_MATRIX_INDICATOR_SET_COLOR(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

void rgb_matrix_layers_enable() {
    enabled = true;
}

void rgb_matrix_layers_disable() {
    enabled = false;
}

#endif  // RGB_MATRIX_LEDMAPS_ENABLED
