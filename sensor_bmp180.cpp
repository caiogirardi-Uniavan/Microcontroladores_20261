/*
**************************
* @file    sensor_bmp180.cpp
* @brief   Funções de leitura BMP180.
**************************
* Date:     14/05/2026
* Author:   Caio Vinícius Girardi
* email:    caiogirardi10@gmail.com
* Project:  Leitor de múltiplos sensores
* Version:  1.0
**************************
*/

#include "sensor_bmp180.h"

float lerBMPTemperatura(Adafruit_BMP085 *bmpDevice)
{
    return bmpDevice->readTemperature();
}

float lerBMPPressao(Adafruit_BMP085 *bmpDevice)
{
    return bmpDevice->readPressure() / 100.0;
}
