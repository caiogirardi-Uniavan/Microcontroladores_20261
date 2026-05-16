/*
**************************
* @file    encoder_rotativo.h
* @brief   Estruturam da máquina de estados para leitura do encoder.
**************************
* Date:     14/05/2026
* Author:   Caio Vinícius Girardi
* email:    caiogirardi10@gmail.com
* Project:  Leitor de múltiplos sensores
* Version:  1.0
**************************
*/

#ifndef ENCODER_ROTATIVO_H
#define ENCODER_ROTATIVO_H

#include <Arduino.h>

struct EncoderConfig
{
    int pinoA;
    int pinoB;
    long encoderPos;
    int lastEncoded;
};

/*
**********************
* @name   initEncoder
* @brief  Inicializa e configura os pinos como entrada, lendo o estado inicial do encoder.
*********************
* @input:  enc - Ponteiro para a estrutura com as configurações e estados do encoder.
* @return: sem retorno
*/
void initEncoder(struct EncoderConfig *enc);

/*
**********************
* @name   lerEncoder
* @brief  Varre o estado atual dos pinos do encoder decodificando o sentido de rotação.
*********************
* @input:  enc - Ponteiro para a estrutura com as configurações e estados do encoder.
* @return: long - Posição acumulada atual do encoder.
*/
long lerEncoder(struct EncoderConfig *enc);

#endif // ENCODER_ROTATIVO_H
