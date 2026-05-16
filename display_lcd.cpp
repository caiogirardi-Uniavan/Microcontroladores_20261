/*
**************************
* @file    display_lcd.cpp
* @brief   LCD - Incializa o LCD
**************************
* Date:     14/05/2026
* Author:   Caio Vinícius Girardi
* email:    caiogirardi10@gmail.com
* Project:  Leitor de múltiplos sensores
* Version:  1.0
**************************
*/

#include "display_lcd.h"

void initLCD(LiquidCrystal_I2C *lcd)
{
    if (lcd != NULL)
    {
        lcd->init();
        lcd->backlight();
    }
}
