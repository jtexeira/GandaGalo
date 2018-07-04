#include "verifica.h"

TIPO converte(VALOR a)
{
    if (a == SOL_X)
        return X;
    if (a == FIXO_X)
        return X;
    if (a == SOL_O)
        return O;
    if (a == FIXO_O)
        return O;
    if (a == BLOQUEADA)
        return B;
    return V;
}

int compara(VALOR a, VALOR b)
{
    if (a == VAZIA || b == VAZIA)
        return 0;
    if (a == BLOQUEADA || b == BLOQUEADA)
        return 0;
    if (converte(a) == converte(b))
        return 1;
    return 0;
}

TIPO local(TIPO ctl, TIPO cmp)
{
    if (ctl == cmp && cmp == B)
        return V;

    if (cmp == B)
        return ctl;

    if (ctl == V || ctl == B || ctl == cmp)
        return cmp;

    return A;
}

void linha(int i, int j, ESTADO e, TIPO *ctl)
{
    //Verifica nas linha da esquerda para a direita
    if (i < e.num_lins - 1)
    {
        if (i < e.num_lins - 2 && compara(e.grelha[i + 1][j], e.grelha[i + 2][j]))
            *ctl = local(*ctl, converte(e.grelha[i + 1][j]));

        if (i != 0 && compara(e.grelha[i - 1][j], e.grelha[i + 1][j]) && *ctl == V)
            *ctl = local(*ctl, converte(e.grelha[i + 1][j]));
    }
    //Verifica nas linhas da direita para a esquerda
    if (i > 1 && compara(e.grelha[i - 1][j], e.grelha[i - 2][j]))
        *ctl = local(*ctl, converte(e.grelha[i - 1][j]));
}

void colunas(int i, int j, ESTADO e, TIPO *ctl)
{
    //Verifica nas colunas de cima para baixo
    if (j < e.num_cols - 1 && *ctl != A)
    {
        if (j < e.num_cols - 2 && compara(e.grelha[i][j + 1], e.grelha[i][j + 2]))
            *ctl = local(*ctl, converte(e.grelha[i][j + 1]));

        if (j != 0 && compara(e.grelha[i][j - 1], e.grelha[i][j + 1]) && *ctl != A)
            *ctl = local(*ctl, converte(e.grelha[i][j + 1]));
    }
    //Verifica nas colunas de baixo para a cima
    if (j > 1 && compara(e.grelha[i][j - 1], e.grelha[i][j - 2]) && *ctl != A)
        *ctl = local(*ctl, converte(e.grelha[i][j - 1]));
}

void diagonal(int i, int j, ESTADO e, TIPO *ctl)
{
    //Verifica a diagonal x = y de cima para baixo
    if (j < e.num_cols - 1 && i < e.num_lins - 1 && *ctl != A)
    {
        if (j < e.num_cols - 2 && i < e.num_lins - 2)
            if (compara(e.grelha[i + 1][j + 1], e.grelha[i + 2][j + 2]))
                *ctl = local(*ctl, converte(e.grelha[i + 1][j + 1]));

        if (i != 0 && j != 0 && compara(e.grelha[i - 1][j - 1], e.grelha[i + 1][j + 1]) && *ctl != A)
            *ctl = local(*ctl, converte(e.grelha[i + 1][j + 1]));
    }

    //Verifica a diagonal x = y de baixo para cima
    if (j > 1 && i > 1 && compara(e.grelha[i - 1][j - 1], e.grelha[i - 2][j - 2]) && *ctl != A)
        *ctl = local(*ctl, converte(e.grelha[i - 1][j - 1]));
}

void diagonal1(int i, int j, ESTADO e, TIPO *ctl)
{
    if (j > 0 && j < e.num_cols && i < e.num_lins - 1 && *ctl != A)
    {
        if (j > 1 && i < e.num_lins - 2 && compara(e.grelha[i + 1][j - 1], e.grelha[i + 2][j - 2]))
            *ctl = local(*ctl, converte(e.grelha[i + 1][j - 1]));

        if (i > 0 && compara(e.grelha[i + 1][j - 1], e.grelha[i - 1][j + 1]) && *ctl != A)
            *ctl = local(*ctl, converte(e.grelha[i + 1][j - 1]));
    }

    if (i > 1 && j < e.num_cols - 1 && compara(e.grelha[i - 1][j + 1], e.grelha[i - 2][j + 2]) && *ctl != A)
        *ctl = local(*ctl, converte(e.grelha[i - 1][j + 1]));
}

TIPO verifica(int i, int j, ESTADO e)
{
    TIPO ctl;
    ctl = V;
    //Verifica nas linha
    linha(i, j, e, &ctl);
    //Verifica nas colunas
    colunas(i, j, e, &ctl);
    //Verifica a diagonal x = y
    diagonal(i, j, e, &ctl);
    diagonal1(i, j, e, &ctl);
    return ctl;
}

VALOR nextV(int i, int j, ESTADO e, TIPO z)
{
    if (z == A)
        return VAZIA;

    if (z == X && e.grelha[i][j] == VAZIA)
        return SOL_O;

    if (z == O && e.grelha[i][j] == SOL_X)
        return VAZIA;

    if (e.grelha[i][j] == VAZIA)
        return SOL_X;

    if (e.grelha[i][j] == SOL_X)
        return SOL_O;

    return VAZIA;
}

int compara3(VALOR a, VALOR b, VALOR c, int i)
{
    if (!(a == FIXO_X || a == FIXO_O) && !i)
        return 0;
    if (a == b && b == c && !i)
        return 1;
    if (converte(a) == converte(b) && converte(b) == converte(c) && a != VAZIA && a != BLOQUEADA)
        return 1;
    return 0;
}

int validaJogo(ESTADO e)
{
    int i, j;
    j = 0;
    for (i = 0; i < e.num_lins; i++)
        for (j = 0; j < e.num_cols; j++)
        {
            if (verifica(i, j, e) == A && e.grelha[i][j] == VAZIA)
                return 0;
            if (j < e.num_cols - 2 && compara3(e.grelha[i][j], e.grelha[i][j + 1], e.grelha[i][j + 2], 1))
                return 0;
            if (i < e.num_lins - 2 && compara3(e.grelha[i][j], e.grelha[i + 1][j], e.grelha[i + 2][j], 1))
                return 0;
            if (i < e.num_lins - 2 && j < e.num_cols - 2 && compara3(e.grelha[i][j], e.grelha[i + 1][j + 1], e.grelha[i + 2][j + 2], 1))
                return 0;
            if (j > 1 && i < e.num_lins - 2 && compara3(e.grelha[i][j], e.grelha[i + 1][j - 1], e.grelha[i + 2][j - 2], 1))
                return 0;
        }
    if (i != e.num_lins || j != e.num_cols)
        return 0;
    return 1;
}

int win(ESTADO e)
{
    int ctl, i, j;
    ctl = 1;
    for (i = 0; i < e.num_lins && ctl; i++)
        for (j = 0; j < e.num_cols && ctl; j++)
            if (e.grelha[i][j] == VAZIA)
                return 0;
            else
            {
                if (j < e.num_cols - 2 && compara3(e.grelha[i][j], e.grelha[i][j + 1], e.grelha[i][j + 2], 1))
                    return 0;
                if (i < e.num_lins - 2 && compara3(e.grelha[i][j], e.grelha[i + 1][j], e.grelha[i + 2][j], 1))
                    return 0;
                if (i < e.num_lins - 2 && j < e.num_cols - 2 && compara3(e.grelha[i][j], e.grelha[i + 1][j + 1], e.grelha[i + 2][j + 2], 1))
                    return 0;
                if (j > 1 && i < e.num_lins - 2 && compara3(e.grelha[i][j], e.grelha[i + 1][j - 1], e.grelha[i + 2][j - 2], 1))
                    return 0;
            }
    return ctl;
}
