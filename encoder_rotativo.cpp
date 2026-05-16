/*
**************************
* @file    encoder_rotativo.cpp
* @brief   Algoritmo de decodificação de sinais do encoder
**************************
* Date:     14/05/2026
* Author:   Caio Vinícius Girardi
* email:    caiogirardi10@gmail.com
* Project:  Leitor de múltiplos sensores
* Version:  1.0
**************************
*/

#include "encoder_rotativo.h"

void initEncoder(struct EncoderConfig *enc)
{
    pinMode(enc->pinoA, INPUT);
    pinMode(enc->pinoB, INPUT);

    int MSB = digitalRead(enc->pinoA);
    int LSB = digitalRead(enc->pinoB);

    enc->lastEncoded = (MSB << 1) | LSB;
}

long lerEncoder(struct EncoderConfig *enc)
{
    int MSB = digitalRead(enc->pinoA);
    int LSB = digitalRead(enc->pinoB);

    int encoded = (MSB << 1) | LSB;
    int sum = (enc->lastEncoded << 2) | encoded;

    if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011)
    {
        enc->encoderPos++;
    }
    if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000)
    {
        enc->encoderPos--;
    }

    enc->lastEncoded = encoded;

    return enc->encoderPos;
}
