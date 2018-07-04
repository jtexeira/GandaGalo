#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "puzzles.h"


ESTADO vazia(int nL, int nC)
{
    ESTADO e;
    e.num_lins = nL;
    e.num_cols = nC;
    int i, j;

    for (i = 0; i < nL; i++)
    {
        for (j = 0; j < nC; j++)
            e.grelha[i][j] = VAZIA;
    }
    return e;
}

char converteVparaC(VALOR v)
{
    switch (v)
    {
    case FIXO_X:
        return 'X';
        break;
    case FIXO_O:
        return 'O';
        break;
    case SOL_X:
        return 'x';
        break;
    case SOL_O:
        return 'o';
        break;
    case VAZIA:
        return '.';
        break;
    default:
        return '#';
        break;
    }
}

void imprime(ESTADO e)
{
    int i, j;

    for (i = 0; i < e.num_lins; i++)
    {
        for (j = 0; j < e.num_cols; j++)
            putchar(converteVparaC(e.grelha[i][j]));
        printf("\n");
    }
}

ESTADO daBloq(ESTADO e, int dif)
{
    srand(time(NULL) + clock() + rand());

    int totalPecas = e.num_lins * e.num_cols;
    int numBloq;

    if (dif == 1)
    {
        numBloq = 0.25 * totalPecas;
    }
    else if (dif == 2)
    {
        numBloq = 0.125 * totalPecas;
    }

    int bC = 0;

    while (bC < numBloq)
    {
        int i = rand() % e.num_lins;
        int j = rand() % e.num_cols;

        if (e.grelha[i][j] == VAZIA)
        {
            e.grelha[i][j] = BLOQUEADA;
            bC++;
        }
    }
    return e;
}

ESTADO daFixos(ESTADO e)
{
    int numFixos = (e.num_lins + e.num_cols) / 2;
    int fC = 0;

    while (fC < numFixos)
    {
        int i = rand() % e.num_lins;
        int j = rand() % e.num_cols;

        if (e.grelha[i][j] == VAZIA)
        {
            e.grelha[i][j] = (rand() % 2 == 0) ? FIXO_X : FIXO_O;
            fC++;
        }
    }

    return e;
}

ESTADO gerarP(int dif, int nL, int nC)
{
    ESTADO x;
    srand(time(NULL) + clock() + rand());
    ESTADO e = vazia(nL, nC);
    e = daBloq(e, dif);
    e = daFixos(e);
    x = autoSolver(e);
    while (!validaJogo(e) || !win(x) || !validaJogo(x))
    {
        e = gerarP(dif, nL, nC);
        x = autoSolver(e);
    }
    return e;
}

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen("/var/www/html/gerar.txt", "w");
    int i;
    int dif = atoi(argv[1]);
    int nL  = atoi(argv[2]);
    int nC  = atoi(argv[3]);
    for (i = 2; i < argc; i++)
    {
        printf("%s ", argv[i]);
    }

    printf("\n");

    ESTADO novo = gerarP(dif, nL, nC);
    imprime(novo);
    estado2file(novo, fp);
    fclose(fp);
    return 0;
}
