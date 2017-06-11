#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"	

int main()
{
	int opc, prodCont;
	PRODUTO produtos[1000];
	PRODUTO carrinho[100];
	printf("Digite: 1- para Cliente. 2- para Funcionário \n");
	scanf("%i", &opc);	

	if(opc == 1)
	{
		while (opc != 4)
		{
			printf("1 - Busca por produtos\n ");
			printf("2 - Carrinho de compras\n");	
			printf("4 - Sair  \n");
			scanf("%i", &opc);

			switch(opc)
			{
				case 1:
				//funcaoBuscaProduto
				break;
				case 2:
				//funcaoCarrinhoCompra
				break;
				case 4:
				printf("Fechando programa");
				break;
				default:
				printf("Comando desconhecido\n");
			}
		}
	}	

	else if(opc == 2)
	{	// alertar estoque baixo
		
		while (opc != 4)
		{
			
			printf("1- Novo produto\n");
			printf("Repor estoque\n");
			printf("Busa\n");
			scanf("%i", &opc);
		}
	}
}