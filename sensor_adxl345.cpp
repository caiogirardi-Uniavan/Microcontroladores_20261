/*
**************************
* @file    sensor_adxl345.cpp
* @brief   Coleta dos dados de aceleração.
**************************
* Date:     14/05/2026
* Author:   Caio Vinícius Girardi
* email:    caiogirardi10@gmail.com
* Project:  Leitor de múltiplos sensores
* Version:  1.0
**************************
*/

#include "sensor_adxl345.h"

void lerAcelerometro(Adafruit_ADXL345_Unified *accelDevice, struct DadosAcelerometro *dados)
{
    sensors_event_t event;
    accelDevice->getEvent(&event);

    dados->accX = event.acceleration.x / 9.80665;
    dados->accY = event.acceleration.y / 9.80665;
    dados->accZ = event.acceleration.z / 9.80665;
}
