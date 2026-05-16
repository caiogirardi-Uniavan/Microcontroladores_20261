/*
**************************
* @file    sensor_ultrassonico.h
* @brief   Estrutura de controle do sensor ultrassônico HC-SR04.
**************************
* Date:     14/05/2026
* Author:   Caio Vinícius Girardi
* email:    caiogirardi10@gmail.com
* Project:  Leitor de múltiplos sensores
* Version:  1.0
**************************
*/

#ifndef SENSOR_ULTRASSONICO_H
#define SENSOR_ULTRASSONICO_H

#include <Arduino.h>

struct SensorUltrassonico
{
    int pinoTrig;
    int pinoEcho;
};

/*
**********************
* @name   initUltrassonico
* @brief  Configura os pinos de Trigger e Echo do sensor ultrassônico.
*********************
* @input:  sensor - Ponteiro para a estrutura com as definições dos pinos.
* @return: sem retorno
*/
void initUltrassonico(struct SensorUltrassonico *sensor);

/*
**********************
* @name   lerDistancia
* @brief  Realiza a leitura da distância utilizando o pulso sonoro.
*********************
* @input:  sensor - Ponteiro para a estrutura com as definições dos pinos.
* @return: float  - Distância calculada em centímetros.
*/
float lerDistancia(struct SensorUltrassonico *sensor);

#endif // SENSOR_ULTRASSONICO_H
