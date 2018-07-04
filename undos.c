#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "undos.h"

void struct2file(STACKUNDOS a, char *user)
{
	char fname[200];
	sprintf(fname, "/var/www/html/%sstack.txt", user);
	STACKUNDOS ant = a;
	FILE *fp;
	fp = fopen(fname, "w");
	while (ant != NULL)
	{
		fprintf(fp, "%d %d %d %d\n", ant->isSave, ant->x, ant->y, ant->valor);
		ant = ant->prox;
	}
	fclose(fp);
}

STACKUNDOS file2struct(char *user)
{
	char fname[200];
	sprintf(fname, "/var/www/html/%sstack.txt", user);
	char str[10];
	STACKUNDOS first;
	FILE *fp;
	fp = fopen(fname, "r");
	if (fgets(str, 10, fp) != NULL)
	{

		first = malloc(sizeof(struct stackUndos));
		sscanf(str, "%d %d %d %d", &first->isSave, &first->x, &first->y, &first->valor);
	}
	else
		return NULL;
	STACKUNDOS pt = first;
	STACKUNDOS new;
	while (fgets(str, 10, fp) != NULL)
	{
		new = malloc(sizeof(struct stackUndos));
		sscanf(str, "%d %d %d %d", &new->isSave, &new->x, &new->y, &new->valor);
		pt->prox = new;
		pt = pt->prox;
	}
	pt = NULL;
	return first;
}

void undoS(STACKUNDOS *a, ESTADO *e)
{
	STACKUNDOS pt = *a;
	if (*a)
	{
		e->grelha[pt->x][pt->y] = pt->valor; //nao testado
		STACKUNDOS dps = pt->prox;
		free(pt);
		*a = dps;
	}
}

void addUndo(STACKUNDOS *a, int x, int y, VALOR c)
{
	STACKUNDOS new = malloc(sizeof(struct stackUndos));
	new->isSave = 0;
	new->x = x;
	new->y = y;
	new->valor = c;
	new->prox = *a;
	*a = new;
}

void loadS(STACKUNDOS *a, ESTADO *e)
{
	STACKUNDOS pt = *a;
	STACKUNDOS dps = NULL;
	while (pt != NULL && pt->isSave != 1)
	{
		e->grelha[pt->x][pt->y] = pt->valor; //nao testado
		dps = pt;
		pt = pt->prox;
		free(dps);
	}
	*a = pt;
	if (*a)
		(*a)->isSave = 0;
}

void toggleSave(STACKUNDOS *a, char *user)
{
	if (*a)
	{
		(*a)->isSave = 1;
		struct2file(*a, user);
	}
}
