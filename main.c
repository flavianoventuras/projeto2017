#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"	

// arquivo principal
int main(){
	
	int opc;
	PRODUTO produto[MAX_PROD];
	PRODUTO carrinho[100];
	FILE *estoque = NULL;
	FILE *carro = NULL;
	estoque = fopen("estoque.txt","r");
	carro = fopen("carro.txt", "r");

	iniciaEstoque(produto, estoque);
	comeca (produto);
	comecaCarro(carrinho);
	iniciaCarrinho(carrinho, carro);


	system("clear");
	printf("Digite: 1- para Cliente. 2- para Funcionário \n");
	scanf("%i", &opc);	
	system("clear");

	if(opc == 1)
	{
		while (opc != 3)
		{
			printf("1 - Busca por produtos\n");
			printf("2 - Carrinho de compras\n");	
			printf("3 - Sair  \n");
			scanf("%i", &opc);
			system("clear");
			switch(opc)
			{
				case 1:
				busca(produto);
				break;
				case 2:
				carrinhoCompra(produto, carrinho);
				break;
				case 3:
				printf("Fechando programa\n");
				break;
				default:
				printf("Comando desconhecido\n");
			}
		}
	}	

	else if(opc == 2)
	{	alerta_estoque(produto);
		printf("\n");
	
		while (opc != 8)
		{
			
			printf("1- Novo produto\n");
			printf("2- Remover produto\n");
			printf("3- Repor estoque\n");
			printf("4- Busca\n");
			printf("5- Listar\n");
			printf("6- Entrada de produtos com arquivo\n");
			printf("7- Dividir por categorias\n");
			printf("8- Sair\n");
			
			scanf("%i", &opc);
			system("clear");
			switch(opc)
			{
				case 1:
				registra(produto);
				break;
				case 2:
				remover(produto);
				break;
				case 3:
				repor_estoque(produto);
				break;
				case 4:
				busca(produto);
				printf("\n\n");
				break;
				case 5:
				listando(produto);
				printf("\n\n");
				break;
				case 6:
				entradaArquivo(produto);
				printf("Arquivo lido!\n\n");
				break;
				case 7:		
				imprimeCategoria(produto);
				printf("\n\n");
				break;
				case 8:		
				printf("Fechando programa\n");
				break;
				default:
				printf("Comando desconhecido\n");
			}
		}
	}
	fclose(carro);
	imprimeEstoque(produto);
	imprimeCarrinho(carrinho);

}     