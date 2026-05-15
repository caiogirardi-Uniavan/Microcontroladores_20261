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

#include <Arduino.h>

struct sensortemp
{
    int valorsensor;

    float vsensor;
    float temp;
};
/*
**********************
* @name  lerTemperatura
* @brief Esta função deve ser chamada cada vez que for necessário ler o sensor TMP36
*
*********************
* @input:   *sensor         - ponteiro para variável da struct sensorTemp
*           
* @return:  temp            - Temperatura em graus celsius 
*/
float lerTemperatura(struct sensortemp *sensor);
