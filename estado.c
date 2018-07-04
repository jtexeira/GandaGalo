#include "estado.h"

#define MAX_BUFFER 10240

void estado2file(ESTADO e, FILE *f)
{
	int i, j;
	fprintf(f, "%d %d\n", e.num_lins, e.num_cols);
	for (i = 0; i < e.num_lins; i++)
	{
		for (j = 0; j < e.num_cols; j++)
			if (e.grelha[i][j] == SOL_X)
				fputc('x', f);
			else if (e.grelha[i][j] == SOL_O)
				fputc('o', f);
			else if (e.grelha[i][j] == FIXO_X)
				fputc('X', f);
			else if (e.grelha[i][j] == FIXO_O)
				fputc('O', f);
			else if (e.grelha[i][j] == BLOQUEADA)
				fputc('#', f);
			else if (e.grelha[i][j] == VAZIA)
				fputc('.', f);
		fputc('\n', f);
	}
	return;
}

ESTADO file2estado(FILE *arq)
{
	char str[1000];
	int lins, cols, z, i;
	lins = cols = 0;
	z = 0;
	ESTADO e;
	if (fgets(str, 10, arq))
		sscanf(str, "%d %d", &lins, &cols);
	e.num_lins = lins;
	e.num_cols = cols;
	while (fgets(str, cols + 2, arq) != NULL)
	{
		for (i = 0; str[i + 1]; i++)
			if (str[i] == '#')
				e.grelha[z][i] = BLOQUEADA;
			else if (str[i] == 'X')
				e.grelha[z][i] = FIXO_X;
			else if (str[i] == 'O')
				e.grelha[z][i] = FIXO_O;
			else if (str[i] == '.')
				e.grelha[z][i] = VAZIA;
			else if (str[i] == 'x')
				e.grelha[z][i] = SOL_X;
			else
				e.grelha[z][i] = SOL_O;
		z++;
	}
	return e;
}
