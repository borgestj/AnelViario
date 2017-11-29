#include "stdafx.h"
#include <Stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#define TAM 10

struct transito
{
	int carro[TAM];
	int ini, fim;
	struct no *p;
};

struct no * prim;

struct transito f;
void inserir();
struct no * insere_carro(int);

void main()
{
	prim = NULL;
	inserir();
	_getch;
}



void inserir()
{
	struct no * aux;
	int n;
	aux = insere_carro(n);
	if (aux != NULL)
		printf("gerando os veiculos a entrarem na fila: /n/n %d", rand() %100);
	else
		printf("Fila cheia!");
}

struct no * insere_carro(int n)
{
	struct no * novo, * aux;
	novo = (struct no *)malloc(sizeof(struct no));
	if (novo != NULL)
	{
		novo->n = n;
		novo->p = NULL; 
		if (prim == NULL)
			prim = novo;
		else
		{
			aux = prim;
			while (aux->p != NULL)
				aux = aux->p;
			aux->p = novo;

		}
	}
	return novo;
}

