#include "mapas.h"

ESTADO inicializar(int x, int y)
{
    int i, j;
    ESTADO e;
    e.num_cols = y;
    e.num_lins = x;
    for (i = 0; i < e.num_lins; i++)
    {
        for (j = 0; j < e.num_cols; j++)
        {
            e.grelha[i][j] = VAZIA;
        }
    }
    return e;
}

char alteraEstadoChar(int i, int j, ESTADO e, TIPO x)
{
    VALOR z = nextV(i, j, e, x);
    if (z == VAZIA)
        return 'v';
    if (z == SOL_X)
        return 'x';
    return 'o';
}

ESTADO alteraEstado(int i, int j, ESTADO e, TIPO x)
{
    VALOR next = nextV(i, j, e, x);
    VALOR atual = e.grelha[i][j];
    if (atual == VAZIA || atual == SOL_X || atual == SOL_O)
        e.grelha[i][j] = next;
    return e;
}

ESTADO mapaDef(int i)
{
    ESTADO a;
    switch (i)
    {
    case 1:
    {
        a = inicializar(4, 4);
        a.grelha[0][1] = BLOQUEADA;
        a.grelha[0][3] = FIXO_X;
        a.grelha[1][1] = FIXO_O;
        a.grelha[2][0] = FIXO_X;
        a.grelha[3][3] = FIXO_O;
        break;
    }
    case 22:
    {
        a = inicializar(4, 8);
        a.grelha[0][1] = BLOQUEADA;
        a.grelha[0][3] = FIXO_X;
        a.grelha[1][1] = FIXO_O;
        a.grelha[2][0] = FIXO_X;
        a.grelha[3][3] = FIXO_O;
        a.grelha[0][5] = BLOQUEADA;
        a.grelha[0][7] = FIXO_X;
        a.grelha[1][5] = FIXO_O;
        a.grelha[2][4] = FIXO_X;
        a.grelha[3][7] = FIXO_O;
        break;
    }
    case 2:
    {
        a = inicializar(6, 6);
        a.grelha[0][1] = FIXO_X;
        a.grelha[1][3] = BLOQUEADA;
        a.grelha[1][5] = FIXO_X;
        a.grelha[2][0] = FIXO_O;
        a.grelha[2][5] = FIXO_O;
        a.grelha[3][2] = BLOQUEADA;
        a.grelha[4][0] = BLOQUEADA;
        a.grelha[4][2] = FIXO_O;
        a.grelha[4][5] = FIXO_O;
        a.grelha[5][0] = FIXO_X;
        a.grelha[5][3] = FIXO_X;
        break;
    }
    case 3:
    {
        a = inicializar(7, 7);
        a.grelha[0][2] = FIXO_X;
        a.grelha[0][4] = FIXO_O;
        a.grelha[1][4] = BLOQUEADA;
        a.grelha[2][2] = FIXO_O;
        a.grelha[2][3] = BLOQUEADA;
        a.grelha[2][6] = FIXO_X;
        a.grelha[3][6] = FIXO_X;
        a.grelha[4][1] = BLOQUEADA;
        a.grelha[4][3] = FIXO_O;
        a.grelha[4][4] = BLOQUEADA;
        a.grelha[4][5] = BLOQUEADA;
        a.grelha[5][1] = BLOQUEADA;
        a.grelha[6][0] = FIXO_X;
        a.grelha[6][1] = FIXO_X;
        a.grelha[6][4] = FIXO_O;
        a.grelha[6][6] = FIXO_O;
        break;
    }
    case 4:
    {
        a = inicializar(9, 9);
        a.grelha[0][7] = FIXO_X;
        a.grelha[1][0] = FIXO_O;
        a.grelha[1][6] = FIXO_O;
        a.grelha[1][7] = BLOQUEADA;
        a.grelha[2][3] = BLOQUEADA;
        a.grelha[2][4] = FIXO_O;
        a.grelha[3][1] = BLOQUEADA;
        a.grelha[3][2] = FIXO_O;
        a.grelha[3][3] = BLOQUEADA;
        a.grelha[3][5] = BLOQUEADA;
        a.grelha[3][6] = BLOQUEADA;
        a.grelha[3][8] = FIXO_X;
        a.grelha[4][0] = FIXO_X;
        a.grelha[5][1] = BLOQUEADA;
        a.grelha[5][2] = BLOQUEADA;
        a.grelha[5][6] = BLOQUEADA;
        a.grelha[5][7] = BLOQUEADA;
        a.grelha[5][8] = BLOQUEADA;
        a.grelha[6][0] = BLOQUEADA;
        a.grelha[6][5] = BLOQUEADA;
        a.grelha[7][0] = FIXO_X;
        a.grelha[7][2] = BLOQUEADA;
        a.grelha[7][3] = FIXO_O;
        a.grelha[7][6] = BLOQUEADA;
        a.grelha[7][7] = FIXO_X;
        a.grelha[7][8] = BLOQUEADA;
        a.grelha[8][4] = FIXO_O;
        a.grelha[8][8] = FIXO_X;
        break;
    }
    case 5:
    {
        a = inicializar(10, 10);
        a.grelha[0][4] = FIXO_X;
        a.grelha[0][5] = BLOQUEADA;
        a.grelha[1][2] = FIXO_X;
        a.grelha[1][3] = BLOQUEADA;
        a.grelha[1][4] = FIXO_O;
        a.grelha[1][6] = BLOQUEADA;
        a.grelha[1][7] = FIXO_O;
        a.grelha[2][4] = BLOQUEADA;
        a.grelha[2][7] = BLOQUEADA;
        a.grelha[2][9] = FIXO_O;
        a.grelha[3][2] = BLOQUEADA;
        a.grelha[3][6] = BLOQUEADA;
        a.grelha[3][8] = BLOQUEADA;
        a.grelha[3][9] = FIXO_O;
        a.grelha[4][0] = FIXO_O;
        a.grelha[4][1] = FIXO_X;
        a.grelha[4][2] = BLOQUEADA;
        a.grelha[4][7] = BLOQUEADA;
        a.grelha[5][0] = FIXO_O;
        a.grelha[5][2] = BLOQUEADA;
        a.grelha[5][3] = BLOQUEADA;
        a.grelha[5][4] = FIXO_O;
        a.grelha[5][9] = BLOQUEADA;
        a.grelha[6][2] = FIXO_O;
        a.grelha[6][3] = BLOQUEADA;
        a.grelha[6][6] = FIXO_O;
        a.grelha[6][9] = FIXO_X;
        a.grelha[7][1] = BLOQUEADA;
        a.grelha[7][5] = BLOQUEADA;
        a.grelha[7][6] = BLOQUEADA;
        a.grelha[8][1] = FIXO_O;
        a.grelha[9][1] = FIXO_X;
        a.grelha[9][4] = BLOQUEADA;
        a.grelha[9][5] = FIXO_O;
        a.grelha[9][8] = FIXO_X;
        break;
    }
    default:
    {
        a = inicializar(4, 4);
        break;
    }
    }
    return a;
}
