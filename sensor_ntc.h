/*
**************************
* @file    sensor_ntc.h
* @brief   Estrutura e cálculo para sensor de temperatura NTC.
**************************
* Date:     14/05/2026
* Author:   Caio Vinícius Girardi
* email:    caiogirardi10@gmail.com
* Project:  Leitor de múltiplos sensores
* Version:  1.0
**************************
*/

#ifndef SENSOR_NTC_H
#define SENSOR_NTC_H

#include <Arduino.h>
#include <math.h>

struct SensorNTC 
{
    int pinoAnalogico;
    float R0;       // Resistência nominal a 25°C
    float T0;       // Temperatura nominal em Kelvin
    float Rd;       // Resistor de pull-down/pull-up do divisor
    float Beta;     // Coeficiente Beta do termistor
};

/*
**********************
* @name   adcToTemperature
* @brief  Coleta a temperatura de um sensor NTC e entrega em °C a partir da entrada analógica.
*********************
* @input:  sensor - Ponteiro para a estrutura com as configurações do NTC.
* @return: float  - Temperatura convertida em °C.
*/
float adcToTemperature(struct SensorNTC *sensor);

#endif // SENSOR_NTC_H
