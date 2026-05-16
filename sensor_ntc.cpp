/*
**************************
* @file    sensor_ntc.cpp
* @brief   Estrutura e cálculo para sensor de temperatura NTC.
**************************
* Date:     14/05/2026
* Author:   Caio Vinícius Girardi
* email:    caiogirardi10@gmail.com
* Project:  Leitor de múltiplos sensores
* Version:  1.0
**************************
*/

#include "sensor_ntc.h"

float adcToTemperature(struct SensorNTC *sensor)
{
    int adc = analogRead(sensor->pinoAnalogico);

    // ADC -> tensão
    float V = adc * 5.0 / 1023.0;

    // Evita divisão por zero
    if(V <= 0.0 || V >= 5.0)
    {
        return -999.0;
    }

    // Calcula resistência do NTC
    float R = (V * sensor->Rd) / (5.0 - V);

    // Equação Beta
    float Tk = 1.0 / ( (1.0 / sensor->T0) + (1.0 / sensor->Beta) * log(R / sensor->R0) );

    // Kelvin -> Celsius
    float Tc = Tk - 273.15;

    return Tc;
}
