/*
**************************
* @file    sensor_bmp180.h
* @brief   Leitura de pressão e temperatura do sensor BMP180.
**************************
* Date:     14/05/2026
* Author:   Caio Vinícius Girardi
* email:    caiogirardi10@gmail.com
* Project:  Leitor de múltiplos sensores
* Version:  1.0
**************************
*/

#ifndef SENSOR_BMP180_H
#define SENSOR_BMP180_H

#include <Arduino.h>
#include <Adafruit_BMP085.h>

/*
**********************
* @name   lerBMPTemperatura
* @brief  Realiza a leitura da temperatura interna do sensor BMP180.
*********************
* @input:  bmpDevice - Ponteiro para o Adafruit_BMP085.
* @return: float     - Temperatura medida em °C.
*/
float lerBMPTemperatura(Adafruit_BMP085 *bmpDevice);

/*
**********************
* @name   lerBMPPressao
* @brief  Realiza a leitura da pressão atmosférica em hPa.
*********************
* @input:  bmpDevice - Ponteiro para o Adafruit_BMP085.
* @return: float     - Pressão atmosférica em hPa.
*/
float lerBMPPressao(Adafruit_BMP085 *bmpDevice);

#endif // SENSOR_BMP180_H
