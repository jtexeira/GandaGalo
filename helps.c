#include "helps.h"

ESTADO hint(ESTADO e, TIPO z, STACKUNDOS *x)
{
    int i, j, ctl;
    TIPO emLinha;
    ctl = 1;
    if (z == A)
        ctl = 0;
    ESTADO a;
    a = e;
    for (i = 0; i < e.num_lins && ctl; i++)
        for (j = 0; j < e.num_cols && ctl; j++)
        {
            emLinha = verifica(i, j, e);
            if (emLinha != V && emLinha != A && nextV(i, j, e, emLinha) != VAZIA)
            {
                ctl = 0;
                addUndo(x, i, j, e.grelha[i][j]);
                a = alteraEstado(i, j, e, emLinha);
            }
        }
    return a;
}

void percorreEstado(ESTADO e, int *i, int *j)
{
    if (*j == e.num_cols)
    {
        *j = 0;
        (*i)++;
    }
    for (; *i < e.num_lins; (*i)++)
    {
        for (; *j < e.num_cols; (*j)++)
            if (e.grelha[*i][*j] == VAZIA)
                return;
        *j = 0;
    }
}

void bestPlay(ESTADO *e)
{
    ESTADO tempX, tempO, temp;
    int maior, tempXI, tempOI, i, j;
    maior = -1;
    *e = solve(*e, &tempXI);
    if (win(*e))
        return;
    for (i = 0; i < e->num_lins; i++)
    {
        for (j = 0; j < e->num_cols; j++)
        {
            percorreEstado(*e, &i, &j);
            tempX = tempO = *e;
            tempX.grelha[i][j] = SOL_X;
            tempO.grelha[i][j] = SOL_O;
            tempX = solve(tempX, &tempXI);
            tempO = solve(tempO, &tempOI);
            if (!validaJogo(tempX))
                tempXI = -1;
            if (!validaJogo(tempO))
                tempOI = -1;
            if (tempXI == -1 && tempOI == -1)
                ;
            else if (tempXI > tempOI)
            {
                if (tempXI > maior)
                {
                    temp = tempX;
                    maior = tempXI;
                }
            }
            else if (tempOI > maior)
            {
                temp = tempO;
                maior = tempOI;
            }
        }
    }
    if (maior)
    {
        *e = temp;
        if (!win(*e))
            bestPlay(e);
    }
}

ESTADO autoSolver(ESTADO e)
{
    int i, j, vazio;
    vazio = 1;
    for (i = 0; i < e.num_lins; i++)
        for (j = 0; j < e.num_cols; j++)
        {
            if (e.grelha[i][j] == SOL_O || e.grelha[i][j] == SOL_X)
                e.grelha[i][j] = VAZIA;
            if (e.grelha[i][j] != VAZIA)
                vazio = 0;
        }
    if (vazio)
    {
        e.grelha[0][0] = SOL_X;
    }
    bestPlay(&e);
    return e;
}

ESTADO solve(ESTADO e, int *jogadas)
{
    int i, j, ctl; //ctl para garantir que jogada e feita ou para o loop
    TIPO emLinha;
    ctl = 1;
    *jogadas = 0;
    while (!win(e) && ctl)
    {
        ctl = 0;
        for (i = 0; i < e.num_lins; i++)
            for (j = 0; j < e.num_cols; j++)
            {
                emLinha = verifica(i, j, e);
                if (emLinha != V && emLinha != A && nextV(i, j, e, emLinha) != VAZIA)
                {
                    e = alteraEstado(i, j, e, emLinha);
                    (*jogadas)++;
                    ctl++;
                }
            }
    }
    return e;
}
