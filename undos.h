#ifndef ___UNDOS_H___
#define ___UNDOS_H___

#include "estado.h"

/**
@file undos.h
\brief Funções relativas aos undos, loads e saves
*/

/**
\brief Estrutura com a informação dos undos e loads a fazer por ordem
*/
typedef struct stackUndos
{
    /** Numero que controla se é uma ancora ou um undo */
    int isSave;
    /** Coordenada x da posição da peça */
    int x;
    /** Coordenada y da posição da peça */
    int y;
    /** Valor da peça */
    int valor;
    /** Apontador para ligar a estrutura em forma de lista ligada */
    struct stackUndos *prox;
} * STACKUNDOS;

/**
\brief Função que converte uma estrutura de uma stack com a informação de undos em formato de ficheiro
@param a Estrutura de stack com a informação sobre undos e saves
@param user Utilizador da stack em questão
*/
void struct2file(STACKUNDOS a, char *user);

/**
\brief Função que atualiza a informação relativa a ser save e chama a struct2file
@param a Estrutura de stack com a informação sobre undos e saves
@param user Utilizador da stack em questão
*/
void toggleSave(STACKUNDOS *a, char *user);

/**
\brief Função que adiciona uma posicao e peça com save a 0 (ou seja undo) à stack de undos
@param a Estrutura de stack com a informação sobre undos e saves
@param x coordenada da peça referente a x
@param y coordenada da peça referente a y
@param c Valor da peça em questão
*/
void addUndo(STACKUNDOS *a, int x, int y, VALOR c);

/**
\brief Função que carrega e elimina toda a stack até encontrar um save
@param a Estrutura de stack com a informação sobre undos e saves
@param e Estado ao qual vai alterar a(s) peça(s) que remover e utilizar
*/
void loadS(STACKUNDOS *a, ESTADO *e);

/**
\brief Função que carrega e elimina a stack um membro de cada vez
@param a Estrutura de stack com a informação sobre undos e saves
@param e Estado ao qual vai alterar a(s) peça(s) que remover e utilizar
*/
void undoS(STACKUNDOS *a, ESTADO *e);

/**
\brief Função que lê uma estrutura a partir de um formato em ficheiro e converte numa stack
@param user Utilizador da stack em questão
@returns Stack com os undos e loads
*/
STACKUNDOS file2struct(char *user);


#endif
