/*
**************************
* @file    sensor_adxl345.h
* @brief   Estruturas e funções para leitura tridimensional com o acelerômetro ADXL345.
**************************
* Date:     14/05/2026
* Author:   Caio Vinícius Girardi
* email:    caiogirardi10@gmail.com
* Project:  Leitor de múltiplos sensores
* Version:  1.0
**************************
*/

#ifndef SENSOR_ADXL345_H
#define SENSOR_ADXL345_H

#include <Arduino.h>
#include <Adafruit_ADXL345_U.h>

struct DadosAcelerometro
{
    float accX;
    float accY;
    float accZ;
};

/*
**********************
* @name   lerAcelerometro
* @brief  Realiza a leitura dos eixos X, Y e Z do ADXL345 e normaliza dividindo pela gravidade (G).
*********************
* @input:  accelDevice - Ponteiro para o Adafruit_ADXL345_Unified.
* @input:  dados        - Ponteiro para a struct onde os valores resultantes dos eixos serão salvos.
* @return: sem retorno
*/
void lerAcelerometro(Adafruit_ADXL345_Unified *accelDevice, struct DadosAcelerometro *dados);

#endif // SENSOR_ADXL345_H
