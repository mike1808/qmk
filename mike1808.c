#include "mike1808.h"

#if (__has_include("secrets.h") && !defined(NO_SECRETS))
#    include "secrets.h"
#else
// `PROGMEM const char secret[][x]` may work better, but it takes up more space in the firmware
// And I'm not familiar enough to know which is better or why...
static const char *const secret[] = {"test1", "test2", "test3", "test4", "test5"};
#endif

// userspace_config_t userspace_config;

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [JK_ESC] = COMBO(jk_combo, KC_ESC),
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SECRET_1 ... KC_SECRET_5:  // Secrets!  Externally defined strings, not stored in repo
            if (!record->event.pressed) {
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                send_string_with_delay(secrets[keycode - KC_SECRET_1], MACRO_TIMER);
            }
            return false;
            break;
    }
    return true;
}

void suspend_power_down_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_suspend_state(true);
#endif  // RGB_MATRIX_ENABLE
}

void suspend_wakeup_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_suspend_state(false);
#endif  // RGB_MATRIX_ENABLE
}

// void keyboard_pre_init_user(void) {
//     userspace_config.raw = eeconfig_read_user();
// }

// void eeconfig_init_user(void) {
//     userspace_config.raw              = 0;
//     userspace_config.os_target = _OS_LINUX;
//     eeconfig_update_user(userspace_config.raw);
// }
