/*
**************************
* @file    sensor_hx711.h
* @brief   Estrutura para balança eletrônica com HX711.
**************************
* Date:     14/05/2026
* Author:   Caio Vinícius Girardi
* email:    caiogirardi10@gmail.com
* Project:  Leitor de múltiplos sensores
* Version:  1.0
**************************
*/

#ifndef SENSOR_HX711_H
#define SENSOR_HX711_H

#include <Arduino.h>
#include "HX711.h"

struct ConfigHX711
{
    long rawZero;    // Valor de tara/zero bruto obtido na calibração
    float ganhoHX;   // Fator de escala/conversão para kg
};

/*
**********************
* @name   lerPeso
* @brief  Realiza a leitura da célula de carga aplicando a média de 10 amostras e aplicando o fator de escala.
*********************
* @input:  scaleDevice - Ponteiro para a biblioteca HX711.
* @input:  config       - Ponteiro para a estrutura com os parâmetros de calibração do sensor.
* @return: float        - Peso calculado em quilogramas (kg).
*/
float lerPeso(HX711 *scaleDevice, struct ConfigHX711 *config);

#endif // SENSOR_HX711_H
