#include "stdafx.h"
#include <Stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <locale.h>

struct no
{
	int n;
	struct no *p;
};

struct Carro {
	char* placa;
	int velocidade;
};

template <typename T>
struct ItemDaFila {
	T item;

	ItemDaFila<T> * proximo;
};

struct no * prim;
char menu();
void titulo(char *);
void pausa();
void inserir();
void pesquisar();
void listar();
void excluir();
struct no * inserir_veiculo(int);
struct no * pesquisar_no(int);
void excluir_carro(struct no *);



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
	printf("1 - inserir Carro\n");
	printf("2 - Procurar Veiculo\n");
	printf("3 - Listar Carro\n");
	printf("4 - Excluir Veiculo\n");
	printf("5 - Comecar Simulacao\n");
	printf("Escolha a opcao: ");
	op = _getche();
	switch (op)
	{
	case '0': break;
	case '1': inserir(); break;
	case '2': pesquisar(); break;
	case '3': listar(); break;
	case '4': excluir(); break;
	case '5': teste(); break;
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
	aux = inserir_veiculo(n);
	if (aux != NULL)
		printf("Insirerido o veiculo %d na fila!", n);
	else
		printf("Fila cheia!");
	pausa();
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
	pausa();
}

void listar()
{
	struct no * aux;
	titulo("LISTAR");
	for (aux = prim; aux != NULL; aux = aux->p)
		printf("%p - %d\n", aux, aux->n);
	pausa();
}

void excluir()
{
	struct no * aux;
	int n;
	titulo("EXCLUIR");
	printf("\nInforme o carro:");
	scanf_s("%d", &n);
	aux = pesquisar_no(n);
	if(aux != NULL)
	{
		excluir_carro(aux);
		printf("Carro excluido da rodovia!\n");
	}
	else
		printf("O carro não está na Rodovia!\n");
	pausa();
}

template <typename T>
struct Fila {
	int tamanho = 0;
	int limite = 10;

	ItemDaFila<T> item;

	ItemDaFila<T> * primeiro;
	ItemDaFila<T> * ultimo;

	bool filaEstaCheia() {
		return tamanho == limite;
	}

	bool filaEstaVazia() {
		return tamanho == 0;
	}

	void adicionar(T item) {
		if (!filaEstaCheia()) {
			ItemDaFila<T> * itemDaFila = new ItemDaFila<T>;

			itemDaFila->item = item;

			ultimo->proximo = itemDaFila;
			ultimo = itemDaFila;

			if (tamanho == 0) {
				primeiro = itemDaFila;
			}

			tamanho++;
		}
	}

	void removerPrimeiro() {
		if (!filaEstaVazia()) {
			primeiro = primeiro->proximo;

			tamanho--;
		}
	}

	void removerPeloIndice(int indice) {
		if (indice == 0)
			removerPrimeiro();

		if (!filaEstaVazia() && indice < tamanho) {
			ItemDaFila<T> * itemDaFila = primeiro;
			for (int i = 0; i < indice - 1; i++) {
				itemDaFila = itemDaFila->proximo;
			}

			if (indice == tamanho - 1)
				itemDaFila->proximo = NULL;
			else
				itemDaFila->proximo = itemDaFila->proximo->proximo;

		}
	}
};
using namespace std;
int teste()
{
	Fila<Carro> fila;
	Carro * carro = new Carro;
	carro->placa = "abc123";
	carro->velocidade = 70;
	fila.adicionar(*carro);

	carro = new Carro;
	carro->placa = "def456";
	carro->velocidade = 101;
	fila.adicionar(*carro);

	carro = new Carro;
	carro->placa = "ghi789";
	carro->velocidade = 99;
	fila.adicionar(*carro);

	carro = new Carro;
	carro->placa = "jkl101";
	carro->velocidade = 87;
	fila.adicionar(*carro);

	carro = new Carro;
	carro->placa = "lbs130";
	carro->velocidade = 66;
	fila.adicionar(*carro);

	carro = new Carro;
	carro->placa = "ltz161";
	carro->velocidade = 112;
	fila.adicionar(*carro);

	carro = new Carro;
	carro->placa = "rbs151";
	carro->velocidade = 120;
	fila.adicionar(*carro);

	carro = new Carro;
	carro->placa = "qor548";
	carro->velocidade = 56;
	fila.adicionar(*carro);

	carro = new Carro;
	carro->placa = "krl101";
	carro->velocidade = 69;
	fila.adicionar(*carro);

	carro = new Carro;
	carro->placa = "ngh303";
	carro->velocidade = 83;
	fila.adicionar(*carro);

	cout << "Placa do ultimo:" << fila.ultimo->item.placa << endl;
	cout << "Placa do primeiro:" << fila.primeiro->item.placa << endl;
	cout << "Placa do segundo:" << fila.primeiro->proximo->item.placa << endl;
	cout << "Placa do terceiro:" << fila.primeiro->proximo->proximo->item.placa << endl;

	fila.removerPeloIndice(4);
	cout << "Placa do terceiro:" << fila.primeiro->proximo->proximo->item.placa << endl;


	return 0;
	pausa();
}

struct no * inserir_veiculo(int n)
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

void excluir_carro(struct no * exc)
{
	struct no * aux;
	if (exc == prim)
		prim = prim->p;
	else
	{
		aux = prim;
		while (aux->p != exc)
			aux = aux->p;
		aux->p = exc->p;
	}
	free(exc);
}