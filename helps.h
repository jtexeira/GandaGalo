#ifndef ___HELPS_H___
#define ___HELPS_H___

#include "undos.h"
#include "tabuleiro.h"

/**
@file helps.h
\brief Funções relativas à ajuda e solução de puzzles
*/

/**
\brief Função que preenche uma quadricula do jogo para ajudar à resolução do jogo

@param e Estado atual 
@param z Parametro de controlo
@param a Lista ligada com os movimentos anteriores para atualizar

@returns Estado atualizado com a quadricula alterada
*/
ESTADO hint(ESTADO e, TIPO z, STACKUNDOS *a);

/**
 * \brief Função que percorre um estado e para quando encontra uma peça tipo VAZIA
 * 
 * @param e Estado a percorrer
 * @param i Numero da linha onde começar a percorrer, e após percorrer o estado
 * o numero de linha onde está a peça vazia
 * @param j Numero da coluna onde começar a percorrer, e após percorrer o estado
 * o numero de coluna onde está a peça vazia
 */
void percorreEstado(ESTADO e, int *i, int *j);

/**
 * \brief Função que determina sucessivamente a jogada otima até o tabuleiro 
 * estar resolvido
 * 
 * @param e Estado a ser resolvido
 */
void bestPlay(ESTADO *e);

/**
 * \brief Função que limpa o tabuleiro de qualquer peça modificada pelo utilizador
 * para calcular a sua solução sem erros
 * 
 * @param e Estado atual a ser resolvido
 * 
 * @returns Jogo resolvido
 */
ESTADO autoSolver(ESTADO e);

/**
 * \brief Função que corre as todas ajudas possiveis
 * 
 * @param e Estado no qual vão correr as ajudas
 * @param jogadas Número de casas preenchidas ao correr a função
 * 
 * @returns Estado atualizado com todas as ajudas possiveis no momento
 */
ESTADO solve(ESTADO e, int *jogadas);
#endif
