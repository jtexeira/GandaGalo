#ifndef ___PUZZLES_H___
#define ___PUZZLES_H___

#include "verifica.h"
#include "estado.h"
#include "helps.h"

/**
@file puzzles.h
\brief Funções relativas à geração de mapas com várias dificuldades
*/

/**
\brief Função que percorre as linhas e as colunas de uma grelha

@param nL Número de linhas 
@param nC Número de colunas

@returns Estado vazio
*/
ESTADO vazia(int nL, int nC);

/**
\brief Função que converte um valor num char

@param v Valor

@returns Um char
*/
char converteVparaC(VALOR v);

/**
\brief Função que percorre um estado

@param e Estado a percorrer
*/
void imprime(ESTADO e);

/**
\brief Função que percorre um estado vazio e vai colocando um certo número de peças bloqueadas consoante a dificuldade

@param e    Estado a percorrer
@param dif  o grau de dificuldade(1-fácil || 2-difícil)

@returns Um estado atualizado com peças bloqueadas
 */
ESTADO daBloq(ESTADO e, int dif);

/**
\brief Função que percorre um estado e coloca um determinado número de peças fixas consoante a dimensão do mapa

@param e Estado a percorrer

@returns Estado atualizado com peças fixas
*/
ESTADO daFixos(ESTADO e);

/**
\brief Função gera puzzles/mapas com uma dimensão escolhida e com uma também escolhida dificuldade (fácil ou difícil) 

@param dif Grau de dificuldade(1-fácil || 2-difícil)
@param nL  Número de linhas
@param nC  Número de colunas

@returns Estado atualizado preenchido com peças bloqueadas, fixas e vazias e com o acréscimo da dificuldade
 */
ESTADO gerarP(int dif, int nL, int nC);

#endif
