#ifndef ___ESTADO_H___
#define ___ESTADO_H___

#include <stdio.h>

/**
@file estado.h
\brief Definição do estado e das funções que convertem estados em strings, ficheiros 
e vice-versa
*/

/** \brief O tamanho máximo da grelha */
#define MAX_GRID 20

/**
 * \brief Valores que as peças do jogo podem tomar
*/
typedef enum { BLOQUEADA,
			   FIXO_X,
			   FIXO_O,
			   VAZIA,
			   SOL_X,
			   SOL_O } VALOR;

/**
\brief Estrutura que armazena o estado do jogo
*/
typedef struct estado
{
	/** Numero de linhas */
	char num_lins;
	/** Numero de colunas */
	char num_cols;
	/** Grelha do jogo */
	char grelha[MAX_GRID][MAX_GRID];
} ESTADO;

/**
\brief Função que escreve um estado num ficheiro
@param e Estado a escrever no ficheiro
@param f Ficheiro no qual se quer escrever o estado
*/
void estado2file(ESTADO e, FILE *f);

/**
\brief Função que converte a informação de um ficheiro de texto
num estado utilizavel pelo programa
@param arq Ficheiro com o jogo a ler
@returns Estado lido do ficheiro
*/
ESTADO file2estado(FILE *arq);

#endif
