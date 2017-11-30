#include "stdafx.h"
#include <Stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#define TAM 10

struct no
{
	int n;
	struct no *p;
};

struct no * prim;
char menu();
void titulo(char *);
void pausa();
void inserir();
void pesquisar();
struct no * inserir_no(int);
struct no * pesquisar_no(int);



void main()
{
	char op;
	prim = NULL;
	do {
		op = menu();
	} while (op != '0');
}

char menu()
{
	char op;
	titulo("MENU");
	printf("0 - Encerrar\n");
	printf("1 - inserir\n");
	printf("2 - Pesquisar\n");
	printf("Escolha a opcao: ");
	op = _getche();
	switch (op)
	{
	case '0': break;
	case '1': inserir(); break;
	case '2': pesquisar(); break;
	default: printf("\nOpcao invalida!"); pausa(); break;
	}
	return op;
}

void titulo(char *texto)
{
	system("cls");
	printf("---------------------\n");
	printf("%s\n", texto);
	printf("---------------------\n");
}

void pausa()
{
	printf("\nTecle algo...");
	_getch();
}

void inserir()
{
	struct no * aux;
	int n;
	char op;
	titulo("INSERIR");
	printf("\nDigite um valor: ");
	scanf_s("%d", &n);
	aux = inserir_no(n);
	if (aux != NULL)
		printf("Insirerido o veiculo %d na fila!", n);
	else
		printf("Fila cheia!");
}

void pesquisar()
{
	struct no * aux;
	int n;
	char op;
	titulo("PESQUISAR");
	printf("\nDigite um valor: ");
	scanf_s("%d", &n);
	aux = pesquisar_no(n);
	if (aux != NULL)
		printf("\nCarro Encontrado no endereço: %p", aux);
	else
		printf("\nCarro não localizado!");


}

struct no * inserir_no(int n)
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

struct no * pesquisar_no(int n)
{
	struct no * aux;
	aux = prim;
	while (aux != NULL && aux->n != n)
		aux = aux-> p;
	return aux;
}