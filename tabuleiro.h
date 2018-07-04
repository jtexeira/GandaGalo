#ifndef ___TABULEIRO_H___
#define ___TABULEIRO_H___

#include "cgi.h"
#include "mapas.h"

/**
@file tabuleiro.h
\brief Funções relativas ao desenho do tabuleiro
*/

/**
\brief Função que desenha o jogo no ecrã
@param e Estado a desenhar no ecrã
@param user Informação sobre o jogador atual
*/
void desenhaJogo(ESTADO e, char *user);

/**
\brief Função que desenha o tabuleiro no ecrã
@param e Estado a desenhar no ecrã
@param user Informação sobre o jogador atual
*/
TIPO desenhaTabuleiro(ESTADO e, char *user);

/**
\brief Função que imprime uma quadricula no ecrã
@param i Linha da quadricula a imprimir
@param j Coluna da quadricula a imprimir
@param user Informação sobre o jogador atual
@param tipo Char corrrespondente ao tipo da proxima peça a colocar na quadricula
@param atual Valor atual da quadricula
*/
void desenhaQuadricula(int i, int j, char *user, char tipo, VALOR atual);

/**
\brief Função que imprime o menu inicial
@param user Informação sobre o jogador atual
*/
void menuEntrada(char *user);

/**
\brief Função que desenha o menu
@param user Utilizador ao qual vai ser mostrado o menu
*/
void desenhaMenu(char *user);

/**
\brief Função que desenha o Login screen para escolha de user
*/
void login();

#endif
