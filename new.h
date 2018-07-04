#ifndef ___NEW_H___
#define ___NEW_H___

#include "helps.h"

/**
@file new.h
\brief Funções relativas ao correr jogos em ficheiros e utilizadores
*/

/**
\brief Função que descodifica as ações passadas na QUERY_STRING e as realiza
@param args Ação a descodificar
@param user Utilizador que realizou a ação
*/
void instruct(char *args, char *user);

/**
\brief Função que inicializa o jogo para um determinado utilizador
*/
void startG();

#endif
