#pragma once

#include "quantum.h"

#ifdef RGB_MATRIX_LEDMAPS_ENABLED
extern const uint8_t ledmaps[][MATRIX_ROWS][MATRIX_COLS][3];

void set_layer_rgb(int layer);

#define RED {HSV_RED}
#define CORAL {HSV_CORAL}
#define ORANGE {HSV_ORANGE}
#define GOLDEN {HSV_GOLDENROD}
#define GOLD {HSV_GOLD}
#define YELLOW {HSV_YELLOW}
#define CHART {HSV_CHARTREUSE}
#define GREEN {HSV_GREEN}
#define SPRING {HSV_SPRINGGREEN}
#define TURQ {HSV_TURQUOISE}
#define TEAL {HSV_TEAL}
#define CYAN {HSV_CYAN}
#define AZURE {HSV_AZURE}
#define BLUE {HSV_BLUE}
#define PURPLE {HSV_PURPLE}
#define MAGENT {HSV_MAGENTA}
#define PINK {HSV_PINK}
#define BLACK {HSV_BLACK}

#endif  // RGB_MATRIX_LEDMAPS_ENABLED

void rgb_matrix_indicators_keymap(void);
