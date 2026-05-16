/*
**************************
* @file    sensor_ultrassonico.cpp
* @brief   Implementação dos pulsos de trigger e cálculo do tempo de resposta do eco.
**************************
* Date:     14/05/2026
* Author:   Caio Vinícius Girardi
* email:    caiogirardi10@gmail.com
* Project:  Leitor de múltiplos sensores
* Version:  1.0
**************************
*/

#include "sensor_ultrassonico.h"

void initUltrassonico(struct SensorUltrassonico *sensor)
{
    pinMode(sensor->pinoTrig, OUTPUT);
    pinMode(sensor->pinoEcho, INPUT);
}

float lerDistancia(struct SensorUltrassonico *sensor)
{
    digitalWrite(sensor->pinoTrig, LOW);
    delayMicroseconds(2);

    digitalWrite(sensor->pinoTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(sensor->pinoTrig, LOW);

    long duracao = pulseIn(sensor->pinoEcho, HIGH, 30000);

    if(duracao == 0)
    {
        return 0;
    }

    return duracao * 0.034 / 2.0;
}
