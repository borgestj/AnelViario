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
};

struct no
{
	int n;
	struct no *p;
};

struct no * prim;

struct transito f;
void inserir();
void pesquisar();
struct no pesquisar_rua(int);
struct no insere_veiculo(int);


void main()
{
	prim = NULL;
	inserir();
	inserir();
	inserir();
	inserir();
	inserir();
	inserir();
	_getch;
}



void inserir()
{
	struct no * aux;
	int n;
	printf("\nDigite um valor: ");
	scanf_s("%d", &n);
	aux = insere_veiculo(n);
	if (aux != NULL)
		printf("Insirerido o veiculo %d na fila!", n);
	else
		printf("Fila cheia!");
}

void pesquisar()
{
	struct no * aux;
	int n;
	printf("\nDigite um valor: ");
	scanf_s("%d", &n);
	aux = pesquisar_rua(n);
	if (aux != NULL)
		printf("\nCarro Encontrado no endereço: %p", aux);
	else
		printf("\nCarro não localizado!");


}

struct no * insere_veiculo(int n)
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

void loop(int n)
{
	if (f.fim < TAM - 1)
	{
		f.fim++;
		f.carro[f.fim] = n;
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
	n = f.carro[f.ini];
	f.ini++;
	return n;
}

struct no pesquisar_rua(int n)
{
	struct no * aux;
	aux = prim;
	while (aux != NULL && aux->n != n)
		aux = aux-> p;
	return aux;
}