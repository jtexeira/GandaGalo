#ifndef ___VERIFICA_H___
#define ___VERIFICA_H___

#include "estado.h"
/**
@file verifica.h
\brief Funções relativas à verificação e validação de jogos
*/

/**
 * \brief Simplificação dos valores para comparações mais simples
*/
typedef enum { X,
               O,
               V,
               B,
               A } TIPO;

/**
\brief Função que converte Valores em tipos, para facilitar a comparação destes

@param a Valor a ser convertido

@returns Tipo correspondente ao valor passado
*/
TIPO converte(VALOR a);

/**
\brief Função que compara valores.

A função considera que se dois valores tiverem o mesmo tipo são iguais.
Se um dos valores dados for VAZIA ou BLOQUEADA a função considera que são diferentes,
para melhor integração com outras funções

@param a Primeiro parametro a comparar
@param b Segundo parametro a comparar

@returns 1 ou 0 conforme os tipos dos valores dados
*/
int compara(VALOR a, VALOR b);

/**
\brief Função de controlo para a verificação da ocorrencia de 3 em
linha com dois tipos diferentes e para evitar que na verificação da solução 
sejam desconsiderados os casos que envolvem Valores do tipo BLOQUEADA.

@param ctl Parametro de controlo
@param cmp Tipo das peças que causem um possivel 3 em linha

@returns V se não existir 3 em linha, o Tipo das peças do 3 em linha
ou A caso aconteça um 3 em linha de dois tipos.
*/
TIPO local(TIPO ctl, TIPO cmp);

/**
\brief Função que verifica a ocorrencia de um possivel 3 em linha
à volta da posição i j.

@param i Linha onde se encontra a posição da peça onde se pretende
procurar o 3 em linha
@param j Coluna onde se encontra a posição da peça onde se pretende
procurar o 3 em linha
@param e Estado onde se pretende verificar o 3 em linha 

@returns V quando não ocorre 3 em linha, o tipo do 3 em linha ou
A quando ocorre 3 em linha de dois tipos diferentes
*/
TIPO verifica(int i, int j, ESTADO e);

/**
\brief Função que cria um estado futuro com base na existencia ou não de 3 em
linha.

@param i Linha onde se encontra a posição da peça onde se pretende alterar o
estado
@param j Coluna onde se encontra a posição da peça onde se pretende alterar o
estado
@param e Estado a alterar
@param z Tipo do 3 em linha existente

@returns Estado alterado na peça em questão
*/
VALOR nextV(int i, int j, ESTADO e, TIPO z);

/**
\brief Função auxiliar para validar o jogo, compara 3 três peças da maneira 
desejada

@param a Primeiro valor a comparar
@param b Segungo valor a comparar
@param c Terceiro valor a comparar
@param i Modo de comparação desejado

@returns 1 caso os três valores sejam iguais e sejam ou FIXO_X ou FIXO_O, 0 em todos os outros casos
*/
int compara3(VALOR a, VALOR b, VALOR c, int i);

/**
\brief Função que verifica se um estado é valido

@param e Estado a ser validado

@returns 1 ou 0 se o jogo é valido ou não
*/
int validaJogo(ESTADO e);

/**
\brief Verifica se o jogo acabou, ou seja, que todas as posições são diferentes
de VAZIA

@param e Estado a verificar

@returns 1 se o jogo acabou, 0 se ainda não está concluido;
*/
int win(ESTADO e);

#endif
