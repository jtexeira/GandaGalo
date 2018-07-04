#ifndef ___MAPAS_H___
#define ___MAPAS_H___

#include "verifica.h"
/**
@file mapas.h
\brief Funções relativas a inicialização e alteração de estados
*/

/**
\brief Função que inicializa o estado vazio

@param x Numero de linhas do estado
@param y Numero de colunas do estado

@returns Um novo estado
*/
ESTADO inicializar(int x, int y);

/**
\brief Função que cria o estado resultante de clicar 
numa quadricula
@param i Linha da quadricula a alterar
@param j Coluna da quadricula a alterar
@param e Estado atual do jogo
@param x Tipo para controlo do 3 em linha
@returns Estado alterado
*/
ESTADO alteraEstado(int i, int j, ESTADO e, TIPO x);

/**
\brief Função que determina o proximo tipo que a peça em questão terá, 
para a criação de novos links
@param i Linha da peça a calcular o proximo tipo
@param j Coluna da peça a calcular o proximo tipo
@param e Estado atual do jogo
@param x Tipo para controlo do 3 em linha
@returns Char correspondente ao proximo tipo
*/
char alteraEstadoChar(int i, int j, ESTADO e, TIPO x);

/**
\brief Função com estados de jogos pré-definidos

@param i Numero do jogo 

@returns Estado do jogo pretendido
*/
ESTADO mapaDef(int i);

#endif //___MAPAS_H___
