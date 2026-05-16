/*
**************************
* @file    display_lcd.h
* @brief   LCD - Incializa o LCD
**************************
* Date:     14/05/2026
* Author:   Caio Vinícius Girardi
* email:    caiogirardi10@gmail.com
* Project:  Leitor de múltiplos sensores
* Version:  1.0
**************************
*/

#ifndef DISPLAY_LCD_H
#define DISPLAY_LCD_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*
**********************
* @name   initLCD
* @brief  Inicializa um display LCD I2C específico.
*********************
* @input:  lcd - Ponteiro para o LiquidCrystal_I2C.
* @return: sem retorno
*/
void initLCD(LiquidCrystal_I2C *lcd);

#endif // DISPLAY_LCD_H
