#include "tabuleiro.h"
#include <string.h>
#include "cgi.h"

#define TAM 40

void desenhaJogo(ESTADO e, char *user)
{
    ABRIR_SVG(800, 600);
    int ctl;
    char buffer[10200];
    TIPO z;
    ctl = win(e);
    z = desenhaTabuleiro(e, user);
    if (z == A)
        IMAGEM(8, 3, 55, "error.png");

    sprintf(buffer, "http://localhost/cgi-bin/GandaGalo?%s", user);
    ABRIR_LINK(buffer);
    IMAGEM(6, 0, 80, "novo.png");
    FECHAR_LINK;

    if (ctl)
    {
        IMAGEM(2, 1, 200, "win.png");
        return;
    }

    sprintf(buffer, "http://localhost/cgi-bin/GandaGalo?%s/h%d", user, z);
    ABRIR_LINK(buffer);
    IMAGEM(7, 0, 80, "hint.png");
    FECHAR_LINK;

    sprintf(buffer, "http://localhost/cgi-bin/GandaGalo?%s/aresolve", user);
    ABRIR_LINK(buffer);
    IMAGEM(6, 2, 80, "solve.png");
    FECHAR_LINK;

    sprintf(buffer, "http://localhost/cgi-bin/GandaGalo?%s/save", user);
    ABRIR_LINK(buffer);
    IMAGEM(6, 1, 80, "saveN.png");
    FECHAR_LINK;

    sprintf(buffer, "http://localhost/cgi-bin/GandaGalo?%s/load", user);
    ABRIR_LINK(buffer);
    IMAGEM(7, 1, 80, "loadN.png");
    FECHAR_LINK;

    sprintf(buffer, "http://localhost/cgi-bin/GandaGalo?%s/undo", user);
    ABRIR_LINK(buffer);
    IMAGEM(7, 2, 80, "undoN.png");
    FECHAR_LINK;
}

TIPO desenhaTabuleiro(ESTADO e, char *user)
{
    int i, j;
    char nv;
    TIPO z, erro;
    z = V;
    for (i = 0; i < e.num_lins; i++)
        for (j = 0; j < e.num_cols; j++)
        {
            erro = verifica(i, j, e);
            nv = alteraEstadoChar(i, j, e, erro);
            if (erro == A && e.grelha[i][j] == VAZIA)
                z = erro;
            desenhaQuadricula(i, j, user, nv, e.grelha[i][j]);
        }
    return z;
}

void desenhaQuadricula(int i, int j, char *user, char tipo, VALOR atual)
{
    char *images[] = {"bloq.png", "XBN.png", "OBN.png", "vazio.png", "X.png", "O.png"};
    if (atual == SOL_X || atual == SOL_O || atual == VAZIA)
    {
        char buffer[10240];
        sprintf(buffer, "http://localhost/cgi-bin/GandaGalo?%s/c_%d_%d_%c", user, i, j, tipo);
        ABRIR_LINK(buffer);
        IMAGEM(j, i, TAM, images[atual]);
        FECHAR_LINK;
    }
    else
        IMAGEM(j, i, TAM, images[atual]);
}

void desenhaMenu(char *user)
{
    FILE *fp;
    fp = fopen("/var/www/html/gerar.txt", "r");
    ABRIR_SVG(600, 600);
    char link0[120], link1[120], link2[120], link3[120], link4[120], link5[120], random[120];
    char path[50];
    strcpy(path, "http://localhost/cgi-bin/GandaGalo?");
    sprintf(link0, "%s%s/m0", path, user);
    sprintf(link1, "%s%s/m1", path, user);
    sprintf(link2, "%s%s/m2", path, user);
    sprintf(link3, "%s%s/m3", path, user);
    sprintf(link4, "%s%s/m4", path, user);
    sprintf(link5, "%s%s/m5", path, user);
    sprintf(random, "%s%s/_gerar.txt", path, user);
    IMAGEMTAMFREE(55, 0, 200, 100, "gandagalo.png");
    ABRIR_LINK(link0);
    IMAGEM(0, 1, 100, "MapaVazio.png");
    FECHAR_LINK;

    ABRIR_LINK(link1);
    IMAGEM(1, 1, 100, "Mapa1.png");
    FECHAR_LINK;

    ABRIR_LINK(link2);
    IMAGEM(2, 1, 100, "Mapa3.png");
    FECHAR_LINK;

    ABRIR_LINK(link3);
    IMAGEM(0, 2, 100, "Mapa2.png");
    FECHAR_LINK;

    ABRIR_LINK(link4);
    IMAGEM(1, 2, 100, "Mapa4.png");
    FECHAR_LINK;

    ABRIR_LINK(link5);
    IMAGEM(2, 2, 100, "Mapa5.png");
    FECHAR_LINK;

    if (fp)
    {
        ABRIR_LINK(random);
        IMAGEM(1, 3, 100, "random.png");
        FECHAR_LINK;
    }
    FECHAR_SVG;
}

void menuEntrada(char *user)
{
    char name[100];
    ABRIR_SVG(600, 600);
    sprintf(name, "http://localhost/cgi-bin/GandaGalo?%s/n", user);
    ABRIR_LINK(name);
    IMAGEMTAMFREE(20, 0, 200, 200, "newgame.png");
    FECHAR_LINK;
    sprintf(name, "http://localhost/cgi-bin/GandaGalo?%s/r", user);
    ABRIR_LINK(name);

    IMAGEMTAMFREE(20, 200, 200, 200, "continue.png");
    FECHAR_LINK;
    FECHAR_SVG;
}

void login()
{
    ABRIR_SVG(600, 100);
    TEXTO(40, 50, 50, "Choose User");
    FECHAR_SVG;
    START_FORM;
    FORM_TEXT("User", "user", 7);
    FORM_BUTTON("Login");
    CLOSE_FORM;
}