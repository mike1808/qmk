
#define PMW33XX_CS_PIN GP9
#define PMW33XX_LIFTOFF_DISTANCE 0x03
#define POINTING_DEVICE_INVERT_Y

// #define PMW3360_CS_PIN F7

#ifdef RGB_DI_PIN
#    undef RGB_DI_PIN
#endif

#define RGB_DI_PIN GP27
// #define NOP_FUDGE 0.4

#define RGBLED_NUM 1
#define RGBLIGHT_ANIMATIONS
