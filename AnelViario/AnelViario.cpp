#include "stdafx.h"
#include <Stdio.h>
#include <stdlib.h>
#include <conio.h>


struct insere_veiculo 
{
	int e[10];
	int ini, fim;
};

struct fila f;
void enfileirar();
void enqueue(int);
void remove_veiculo();
int denqueue();

void main()
{
	_getch;
}

void enfileirar()
{
	int n = 10;
	enqueue(n);
}

void enqueue(int n)
{
	if (f.fim < TAM - 1)
	{
		f.fim++;
		f.c[f.fim] = n;
	}
	else
	{
		printf("Fila cheia!!!");
	}
}

void remove_veiculo()
{
	int n;
	n = denqueue();
}

int denqueue()
{
	int n;
	n = f.c[f.ini];
	f.ini++;
	return n;
}