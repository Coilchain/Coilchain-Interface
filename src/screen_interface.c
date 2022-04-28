#include "screen_interface.h"

#include "drv_ssd1351.h"
#include "ssd1351.h"
#include "fonts.h"
#include "testimg.h"


static struct Ui_data data;

struct Ui_data * screen_interface_init()
{
    drv_SSD1351_init();
    SSD1351_Unselect();
    SSD1351_Init();

    SSD1351_FillScreen(SSD1351_BLACK);
    data.assistance_level = 3;
    data.bike_speed = 12;
    return(&data);
}

void update_ui_data()
{
    char str[20];
    sprintf(str, "%d km/h", data.bike_speed);
    SSD1351_WriteString(0, 5, str, Font_16x26, SSD1351_BLUE, SSD1351_BLACK);

    sprintf(str, "POWER %d w", data.generated_power);
    SSD1351_WriteString(0, 5*10, str, Font_11x18, SSD1351_CYAN, SSD1351_BLACK);

    sprintf(str, "%d rpm", data.cadence);
    SSD1351_WriteString(0, 8*10, str, Font_11x18, SSD1351_CYAN, SSD1351_BLACK);

    sprintf(str, "ASSI %d/4", data.assistance_level);
    SSD1351_WriteString(0, 11*10, str, Font_7x10, SSD1351_CYAN, SSD1351_BLACK);
    
    return;
}

/*// Check border
    SSD1351_FillScreen(SSD1351_BLACK);

    for(int x = 0; x < SSD1351_WIDTH; x++) {
        SSD1351_DrawPixel(x, 0, SSD1351_RED);
        SSD1351_DrawPixel(x, SSD1351_HEIGHT-1, SSD1351_RED);
    }

    for(int y = 0; y < SSD1351_HEIGHT; y++) {
        SSD1351_DrawPixel(0, y, SSD1351_RED);
        SSD1351_DrawPixel(SSD1351_WIDTH-1, y, SSD1351_RED);
    }

    HAL_Delay(500);

    // Check fonts
    SSD1351_FillScreen(SSD1351_BLACK);
    SSD1351_WriteString(0, 0, "Font_7x10, red on black, lorem ipsum dolor sit amet", Font_7x10, SSD1351_RED, SSD1351_BLACK);
    SSD1351_WriteString(0, 3*10, "Font_11x18, green, lorem ipsum", Font_11x18, SSD1351_GREEN, SSD1351_BLACK);
    SSD1351_WriteString(0, 3*10+3*18, "Font_16x26, blue, lorem ipsum dolor sit amet", Font_16x26, SSD1351_BLUE, SSD1351_BLACK);

    HAL_Delay(1000);
    SSD1351_InvertColors(true);
    HAL_Delay(1000);
    SSD1351_InvertColors(false);

    HAL_Delay(1000);

    // Check colors
    SSD1351_FillScreen(SSD1351_WHITE);
    SSD1351_WriteString(0, 0, "WHITE", Font_11x18, SSD1351_BLACK, SSD1351_WHITE);
    HAL_Delay(500);

    SSD1351_FillScreen(SSD1351_BLUE);
    SSD1351_WriteString(0, 0, "BLUE", Font_11x18, SSD1351_BLACK, SSD1351_BLUE);
    HAL_Delay(500);

    SSD1351_FillScreen(SSD1351_RED);
    SSD1351_WriteString(0, 0, "RED", Font_11x18, SSD1351_BLACK, SSD1351_RED);
    HAL_Delay(500);

    SSD1351_FillScreen(SSD1351_GREEN);
    SSD1351_WriteString(0, 0, "GREEN", Font_11x18, SSD1351_BLACK, SSD1351_GREEN);
    HAL_Delay(500);

    SSD1351_FillScreen(SSD1351_CYAN);
    SSD1351_WriteString(0, 0, "CYAN", Font_11x18, SSD1351_BLACK, SSD1351_CYAN);
    HAL_Delay(500);

    SSD1351_FillScreen(SSD1351_MAGENTA);
    SSD1351_WriteString(0, 0, "MAGENTA", Font_11x18, SSD1351_BLACK, SSD1351_MAGENTA);
    HAL_Delay(500);

    SSD1351_FillScreen(SSD1351_YELLOW);
    SSD1351_WriteString(0, 0, "YELLOW", Font_11x18, SSD1351_BLACK, SSD1351_YELLOW);
    HAL_Delay(500);

    SSD1351_FillScreen(SSD1351_BLACK);
    SSD1351_WriteString(0, 0, "BLACK", Font_11x18, SSD1351_WHITE, SSD1351_BLACK);
    HAL_Delay(500);

    SSD1351_DrawImage(0, 0, 128, 128, (const uint16_t*)test_img_128x128);

    HAL_Delay(500);*/