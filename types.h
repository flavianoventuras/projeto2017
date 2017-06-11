
#ifndef __TYPES__
#define __TYPES__

#define MAX_PROD 1000
typedef struct 
{	
	int dia;
	int mes;
	int ano;
}DATA;

typedef struct 
{
	int corredor;
	int prateleira;
}LOCALIZACAO;

typedef struct 
{
	char categoria[30];
	int cod;
	float valor;
	char descricao [200];
	char fabricante[50];
	int quantidade;
	DATA validade;
	LOCALIZACAO local;
}PRODUTO;




void entradaArquivo(PRODUTO produto[MAX_PROD]);
void comeca (PRODUTO produto[MAX_PROD]);
void comecaCarro(PRODUTO carrinho[100]);

void iniciaEstoque(PRODUTO produto[MAX_PROD], FILE *estoque);
void iniciaCarrinho(PRODUTO carrinho[100], FILE *carro);

void busca(PRODUTO produto[MAX_PROD]);
void carrinhoCompra(PRODUTO produtos[MAX_PROD], PRODUTO carrinho[100]);
void remover(PRODUTO produto[MAX_PROD]);

void listando(PRODUTO produto[MAX_PROD]);
void registra (PRODUTO produto[MAX_PROD]);
void repor_estoque(PRODUTO produto[MAX_PROD]);
void alerta_estoque(PRODUTO produto[MAX_PROD]);
void imprimeCategoria (PRODUTO produto[MAX_PROD]);


void imprimeEstoque(PRODUTO produto [MAX_PROD]);
void imprimeCarrinho(PRODUTO carrinho [100]);

#endif