#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "string.h"

void buscaPreco( PRODUTO produto[MAX_PROD]);
void buscaQuantidade(PRODUTO produto[MAX_PROD]);
void buscaNome(PRODUTO produto[MAX_PROD]);
void buscaFabricante(PRODUTO produto[MAX_PROD]);
void achaProd(PRODUTO produto[MAX_PROD], int *cod);


void busca(PRODUTO produto[MAX_PROD])
{	// gerencia as opções de busca. Recebe a opção (opc) e de acordo com o número
	// e direciona para a função de busca desejada
	//////////////////////////////////////////////////////////////////////////////
	

	int opc;
	system("clear");
	printf("\nBuscar por:\n\n1- Preço\n2- Quantidade em estoque\n3- Nome do produto\n");
	printf("4- Fabricante\n");
	printf("\nDigite qual filtro desejado: ");
	scanf("%i", &opc);
	system("clear");
	
	switch (opc)
	{
		case 1:
		buscaPreco(produto);
		break;
		case 2:
		buscaQuantidade(produto); 
		break;
		case 3:
		buscaNome(produto);
		break;
		case 4:
		buscaFabricante(produto);
		break;
		default:
		printf("Comando desconhecido\n");
	}
	
}

void carrinhoCompra(PRODUTO produtos[MAX_PROD], PRODUTO carrinho[100])
{	
	int opc, i, cod, qtd;
	FILE *carro;
	carro = fopen("carro.txt", "r");

	iniciaCarrinho(carrinho, carro);

	float valor =0;
	do{
		printf("Digite sua opção\n");
		printf("1- Exibir itens do carrinho\n2- Inserir itens no carrinho\n3- Retirar itens do carrinho\n4- Sair\n");
		scanf("%d", &opc);

		switch(opc)
		{
			case 1:
				system("clear");
				valor = 0;
				for(i = 0; i < 100; i++)
				{
					if(carrinho[i].valor > 0.01)
					{	// imprimindo todos os produtos existentes 
						printf("Descrição: %s \n", carrinho[i].descricao);
						printf("\tCódigo: %i\t Preço: %.2f\tQuantidade: %i\n", carrinho[i].cod, carrinho[i].valor, carrinho[i].quantidade);
						valor+=(carrinho[i].valor*carrinho[i].quantidade);
					}
				
				}
				printf("\n\nSubtotal: %.2f \n\n", valor);

			break;

			case 2:
				system("clear");
				printf("Digite o código do produto que deseja inserir: \n");
				scanf("%d", &cod);	
				printf("Digite a quantidade desejada: ");
				scanf("%d", &qtd);
				achaProd(produtos, &cod);
				for(i = 0; carrinho[i].valor > 0; i++) 
				{	// perorrendo o vetor para achar o algum produto com valor igual a 0
					// produtos com valores iguais a zero são produtos que foram excluidos;
					if(i >= 99)
					{
						printf("Carrinho está cheio\n");
						break;
					}
				}
				if(produtos[cod].quantidade >= qtd && produtos[cod].valor >= 0.01)
				{
					strcpy(carrinho[i].descricao, produtos[cod].descricao);
					strcpy(carrinho[i].categoria, produtos[cod].categoria); 
						
					carrinho[i].cod = i;
					carrinho[i].valor = produtos[cod].valor;
					carrinho[i].quantidade = qtd;
					produtos[i].quantidade -=qtd;
					printf("Produto: %s adicionado\n", carrinho[i].descricao);
					printf("Produto: %i adicionado\n",cod);

				}
				else	
				{	
					printf("Não possuíos a quantidade desejada\n");
					printf("Produto: %i adicionado\n",cod);
				}	
				
			break;
			case 3:
			system("clear");
			printf("Digite o código do produto que deseja retirar: \n");
			scanf("%d", &cod);
			for(i = 0; i < MAX_PROD-10; i++)
			{
				if(carrinho[i].cod == cod && carrinho[i].valor >= 0.01)
				{
					carrinho[i].valor = 0;
					printf("Excluido: %s \n", carrinho[i].descricao);
				}
			}	 
							
			break;	
			case 4:
			system("clear");
			break;
			default:
			printf("Comando desconhecido\n");
		}

	} while(opc !=4);	

	fclose(carro);
}





void buscaPreco(PRODUTO produto[MAX_PROD])
{
	// recebe um valor (valor) e mostra todas os produtos com o produtos[i].valor 
	// abaixo do valor recebido e maiores do que 0.01
	//////////////////////////////////////////////////////////////////////////////

	int i;
	float valor;
	system("clear");
	printf("Digite o preço máximo desejado\n");
			scanf("%f", &valor);
			for(i = 0; i < MAX_PROD; i++)
			{	if(produto[i].valor <= valor && produto[i].valor >= 0.01 )
				// mostrando todos os produtos abaixo do valor escolhido
				{	
				
					printf("Descrição: %s \n", produto[i].descricao);
					printf("\tCódigo: %i\t Preço: %.2f", produto[i].cod, produto[i].valor);
					printf("\t Quantidade em estoque: %i\n", produto[i].quantidade);
					printf("\tFabricante: %s\n", produto[i].fabricante);
					printf("\tCategoria: %s", produto[i].categoria);
					printf("\tValidade: %i/%i/%i \n", produto[i].validade.dia, produto[i].validade.mes, produto[i].validade.ano);
					printf("\tLocal - Corredor: %i Prateleira: %i\n", produto[i].local.corredor, produto[i].local.prateleira);

				}

			}

}	

void buscaQuantidade(PRODUTO produto[MAX_PROD])
{
	// Recebe uma quantidade (qtdEstoque) para utilizar como quantidade mínima
 	//no for, todo vetor é percorrido procurando todos os produtos que tenham o campo
	//produtos[i].quantidade for maior que qtdEstoque e imprimindo
	////////////////////////////////////////////////////////////////////////////////
	int i, qtdEstoque ;

	printf("Digite a quantidade mínima em estoque desejada\n");
		scanf("%i", &qtdEstoque);
		for(i = 0; i < MAX_PROD; i++)
		{	
			if(produto[i].quantidade >= qtdEstoque && produto[i].valor > 0.01)
				// mostrando todos os produtos com o estoque maior que a quantidade escolhida
			{
				printf("Descrição: %s \n", produto[i].descricao);
				printf("\tCódigo: %i\t Preço: %.2f", produto[i].cod, produto[i].valor);
				printf("\t Quantidade em estoque: %i\n", produto[i].quantidade);
				printf("\tFabricante: %s\n", produto[i].fabricante);
				printf("\tCategoria: %s", produto[i].categoria);
				printf("\tValidade: %i/%i/%i \n", produto[i].validade.dia, produto[i].validade.mes, produto[i].validade.ano);
				printf("Local - Corredor: %i Prateleira: %i\n\n", produto[i].local.corredor, produto[i].local.prateleira);
			}
		}
}	

void buscaNome(PRODUTO produto[MAX_PROD])
{
	// recebe uma string (nome) de no máximo 200 caracteres
	// e procura todo vetor produto por um campo produto[i].descricao
	// que seja igual a nome[200], se achar, imprime na tela
	///////////////////////////////////////////////////////////////

	int i;
	char nome[200];
	printf("Digite o nome/descrição do produto desejado: \n");
	scanf("  %[^\n]s", nome); // lê tudo que for digitado até o exceto o /n
	for(i = 0; i < MAX_PROD - 10; i++)
	{	
		
		
		if( strcmp(produto[i].descricao, nome ) == 0)
		{
			printf("Descrição: %s \n", produto[i].descricao);
			printf("\tCódigo: %i\t Preço: %.2f", produto[i].cod, produto[i].valor);
			printf("\t Quantidade em estoque: %i\n", produto[i].quantidade);
			printf("\tFabricante: %s\n", produto[i].fabricante);
			printf("\tCategoria: %s", produto[i].categoria);
			printf("\tValidade: %i/%i/%i \n", produto[i].validade.dia, produto[i].validade.mes, produto[i].validade.ano);
			printf("Local - Corredor: %i Prateleira: %i\n\n", produto[i].local.corredor, produto[i].local.prateleira);
		}
		
	}
}

void buscaFabricante(PRODUTO produto[MAX_PROD])
{
	// recebe uma string (nome) de no máximo 50 caracteres
	// e procura todo vetor produto por um campo produto[i].fabricante
	// que seja igual a nome[50], se achar, imprime na tela
	///////////////////////////////////////////////////////////////
	

	int i;
	char nome[50];
	printf("Digite o fabricante do produto desejado: ");
	scanf("  %[^\n]s", nome); // lê tudo que for digitado até o exceto o /n
	for(i = 0; i < MAX_PROD - 10; i++)
	{	

		if( strcmp(produto[i].fabricante, nome) == 0)
		{
			printf("Descrição: %s \n", produto[i].descricao);
			printf("\tCódigo: %i\t Preço: %.2f", produto[i].cod, produto[i].valor);
			printf("\t Quantidade em estoque: %i\n", produto[i].quantidade);
			printf("\tFabricante: %s\n", produto[i].fabricante);
			printf("\tCategoria: %s", produto[i].categoria);
			printf("\tValidade: %i/%i/%i \n", produto[i].validade.dia, produto[i].validade.mes, produto[i].validade.ano);
			printf("Local - Corredor: %i Prateleira: %i\n\n", produto[i].local.corredor, produto[i].local.prateleira);
		}
	
	}
}


void achaProd(PRODUTO produto[MAX_PROD], int *cod) 
{	
	//  acha o produto com o código dado na função de inserir carrinhoCompra - opção de inserir produtos
	int i;
	for (i = 0; i < MAX_PROD-10; i++)
	{
		if(*cod == produto[i].cod)
		{
			*cod = i; 
		}
	}
}