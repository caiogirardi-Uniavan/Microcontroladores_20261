/*
**************************
* @file    sensortemp.h
* @brief   Structure of TMP36 sensor.
**************************
* 
*
*
*
* Date: 14/05/2026
* Author: Caio Vinícius Girardi
* email : caiogirardi10@gmail.com
* Project: TMP36 sensor reader
* Version: 1.0
**************************
*/

#include "sensor.h"
  
float lerTemperatura(struct sensortemp *sensor)
{
    int leitura;

    leitura = analogRead(sensor->valorsensor);

    sensor->vsensor = leitura * (5.0 / 1023.0);

    sensor->temp = (sensor->vsensor - 0.5) * 100.0;

    return sensor->temp;
}
