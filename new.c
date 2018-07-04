#include <stdlib.h>
#include <string.h>
#include "new.h"

void instruct(char *args, char *user)
{
    STACKUNDOS a;
    a = file2struct(user);
    char x; // useless char, apenas para o sscanf
    int i, j;
    FILE *fr;
    char name[100];
    ESTADO e, z;
    char p;
    sprintf(name, "/var/www/html/%s.txt", user);
    if (args[0] == 'm')
    {
        fr = fopen(name, "w");
        char a;
        int i;
        sscanf(args, "%c%d", &a, &i);
        e = mapaDef(i);
        estado2file(e, fr);
        fclose(fr);
        char fname[200];
        sprintf(fname, "/var/www/html/%sstack.txt", user);
        fr = fopen(fname, "w");
        fclose(fr);
    }
    else if (args[0] == 'c')
    {
        fr = fopen(name, "r");
        e = file2estado(fr);
        fclose(fr);
        z = e;
        fr = fopen(name, "w");
        sscanf(args, "%c_%d_%d_%c", &x, &i, &j, &p);
        if (p == 'x')
            e.grelha[i][j] = SOL_X;
        else if (p == 'o')
            e.grelha[i][j] = SOL_O;
        else if (p == 'v')
            e.grelha[i][j] = VAZIA;
        estado2file(e, fr);
        fclose(fr);
        addUndo(&a, i, j, z.grelha[i][j]);
        struct2file(a, user);
        // save(estado2str(z), 0, user);
    }
    else if (args[0] == 'h')
    {
        fr = fopen(name, "r");
        z = e = file2estado(fr);
        e = hint(e, args[2], &a);
        fclose(fr);
        fr = fopen(name, "w");
        estado2file(e, fr);
        fclose(fr);
        struct2file(a, user);
        // save(estado2str(z), 0, user);
    }
    else if (args[0] == 'l')
    {
        fr = fopen(name, "r");
        e = file2estado(fr);
        fclose(fr);
        loadS(&a, &e);
        struct2file(a, user);
        // e = str2estado(load(estado2str(e), e, user));
        fr = fopen(name, "w");
        estado2file(e, fr);
        fclose(fr);
    }
    else if (args[0] == 's')
    {
        fr = fopen(name, "r");
        e = file2estado(fr);
        fclose(fr);
        toggleSave(&a, user);
        // save(estado2str(e), 1, user);
    }
    else if (args[0] == 'n')
    {
        desenhaMenu(user);
        return;
    }
    else if (args[0] == 'r')
    {
        fr = fopen(name, "r");
        e = file2estado(fr);
        fclose(fr);
    }

    else if (args[0] == 'u')
    {
        fr = fopen(name, "r");
        e = file2estado(fr);
        fclose(fr);
        undoS(&a, &e);
        struct2file(a, user);
        // e = str2estado(undo(estado2str(e), user));
        fr = fopen(name, "w");
        estado2file(e, fr);
        fclose(fr);
    }
    else if (args[0] == '_')
    {
        char file[200];
        sprintf(file, "/var/www/html/%s", args + 1);
        fr = fopen(file, "r");
        if (fr == NULL)
        {
            ABRIR_SVG(600, 600);
            TEXTO(45, 40, 40, "Puzzle Inexistente");
            char link[100];
            sprintf(link, "http://localhost/cgi-bin/GandaGalo?%s", user);
            ABRIR_LINK(link);
            IMAGEM(0, 5, 80, "novo.png");
            FECHAR_LINK;
            FECHAR_SVG;
            return;
        }
        e = file2estado(fr);
        fclose(fr);
        fr = fopen(name, "w");
        estado2file(e, fr);
        fclose(fr);
        if (!validaJogo(e))
        {
            ABRIR_SVG(600, 600);
            TEXTO(45, 40, 40, "Mapa Invalido");
            char link[100];
            sprintf(link, "http://localhost/cgi-bin/GandaGalo?%s", user);
            ABRIR_LINK(link);
            IMAGEM(0, 5, 80, "novo.png");
            FECHAR_LINK;
            FECHAR_SVG;
            return;
        }
    }
    else if (args[0] == 'a')
    {
        fr = fopen(name, "r");
        e = file2estado(fr);
        fclose(fr);
        e = autoSolver(e);
        fr = fopen(name, "w");
        estado2file(e, fr);
        fclose(fr);
    }

    desenhaJogo(e, user);
    return;
}

void startG()
{
    char *user, *action;
    FILE *fr;
    char name[100];
    char *args;
    args = getenv("QUERY_STRING");
    if (strlen(args) == 0)
    {
        login();
        return;
    }
    user = malloc(60);
    action = malloc(60);
    user = strtok(args, "/");
    action = strtok(NULL, "\0");
    sprintf(name, "/var/www/html/%s.txt", user);
    fr = fopen(name, "r");
    if (!action)
    {
        if (fr != NULL)
        {
            fclose(fr);
            menuEntrada(user);
            return;
        }
        fr = fopen(name, "w");
        fclose(fr);
        sprintf(name, "/var/www/html/%sstack.txt", user);
        fr = fopen(name, "w");
        fclose(fr);
        desenhaMenu(user);
        return;
    }
    fclose(fr);
    instruct(action, user);
    return;
}
