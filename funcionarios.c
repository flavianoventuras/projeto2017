#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"


void listaMenor(PRODUTO produto[MAX_PROD]);
void listaTudo(PRODUTO produto[MAX_PROD]);
void ordemAlfabetica(PRODUTO produto[MAX_PROD]);
void ordemEstoque(PRODUTO produto[MAX_PROD]);
void imprimeTudoCat(PRODUTO produto[MAX_PROD]);

int cmpNum(const void *a, const void *b)
{
	//comparação para a função qsort 
  PRODUTO *x = (PRODUTO *)a;
  PRODUTO *y = (PRODUTO *)b;
  if( x->valor > y->valor )
    return 1;
  if( x->valor < y->valor)
    return -1;
  return 0;  
}

int cmpEstoque(const void *a, const void *b)
{
	//comparação para a função qsort	
  PRODUTO *x = (PRODUTO *)a;
  PRODUTO *y = (PRODUTO *)b;
  if( x->quantidade > y->quantidade)
    return -1;
  if( x->quantidade < y->quantidade)
    return 1;
  return 0;
  
}

int cmpAlfabeto(const void *a, const void *b)
{
	//comparação para a função qsort
  PRODUTO *x = (PRODUTO *)a;
  PRODUTO *y = (PRODUTO *)b;
  return strcmp(x->descricao, y->descricao);
  
}



void registra (PRODUTO produto[MAX_PROD])
{	
	// sempre que chamada, a função registra irá procurar um lugar vazio no vetor (produto[i].valor < 0.01)
	// ao encontrar a primeira posição i com valor 0 será feita a leitura de todos os campos do vetor produto
	///////////////////////////////////////////////////////////////////////////////////////////////////////// 	


	int i;
	for(i = 0; produto[i].valor > 0.1; i++ ) // procura um lugar vazio no vetor para colocar
	{ 
		if(i >= 999)
		{
			printf("Estoque cheio\n");
			return;
		}
	}
	system("clear");
	printf("Insira a descrição\n");
	scanf(" %[^\n]s",produto[i].descricao);
	system("clear");

	printf("Insira o codigo\n");
	scanf(" %d", &produto[i].cod);
	system("clear");

	printf("Insira o valor\n");
	scanf(" %f", &produto[i].valor);
	system("clear");

	printf("Insira o fabricante\n");
	scanf(" %[^\n]s", produto[i].fabricante);
	system("clear");

	printf("Insira a quantidade\n");
	scanf(" %d", &produto[i].quantidade);
	system("clear");

	printf("Insira a categoria\nDigitar: ELETRÔNICO - LIMPEZA - ALNP (para alimentos não pereciveis) - ALP (para alimentos pereciveis)\n");
	scanf(" %[^\n]s", produto[i].categoria);
	system("clear");

	printf("Insira a data de validade - Separar dia, mês e ano por espaços -  DD MM AAAA\n");
	scanf(" %i %i %i", &produto[i].validade.dia, &produto[i].validade.mes, &produto[i].validade.ano);
	system("clear");

	printf("Insira o local - Separar corredor e prateleira por espaços\n");
	scanf(" %i %i", &produto[i].local.corredor, &produto[i].local.prateleira);
	system("clear");


}

void remover(PRODUTO produto[MAX_PROD])
{	// remover pede um código de prduto (cod) e procura qual a posição do vetor produto
	// existe um código igual al código lido, se achar esse código a função iguala 
	// o campo valor de produto[i] a 0. Abrindo espaço para futuras gravações
	///////////////////////////////////////////////////////////////////////////


	int cod, i;
	system("clear");
	printf("Digite o código do produto que deseja retirar: \n");
	scanf("%d", &cod);
	for(i = 0; i < MAX_PROD-10; i++)
	{
		if(produto[i].cod == cod)
		{
			produto[i].valor = 0;
			printf("Excluido: %s \n", produto[i].descricao);
		}


	} 


}



void repor_estoque(PRODUTO produto[MAX_PROD])
{	// recebe um código (cod) e uma quantidade (qtd), e a partir desse codigo procura o produto[i]
	// que tenha o campo codigo igual a cod
	// ao encontrar acrescenta qtd ao campo quantidade de produto[i]
	////////////////////////////////////////////////////////////////////////////////////////////

	int i, 	cod, qtd;
	printf("Digite o código do produto que deseja repor\n");
	scanf("%i", &cod);
	system("clear");	
	printf("Digite a quantidade desejada para se repor\n");
	scanf("%i", &qtd);
	for(i = 0; i < MAX_PROD-10; i++)
	{
		if(produto[i].cod == cod)
			{
				produto[i].quantidade += qtd;
				printf("Acrescentado %i itens a %s \n",qtd, produto[i].descricao);
			}
	}		

}

void alerta_estoque(PRODUTO produto[MAX_PROD])
{	
	//procura entre todos os produtos[max_prod-10] quais desses estejam com o campo estoque
	// menores ou iguais a dez, e mostra na tela todos os que estejam nessa situação
	//////////////////////////////////////////////////////////////////////////////////////



	int i;

	for(i = 0; i < MAX_PROD-10; i++ ) 
	{ 	
		if(produto[i].quantidade <= 10)
		{ // mostranod todos os produtos com estoques abaixo de 11, para alertar os funcionários

			printf("Estoque baixo de: %s - restam %i em estoque\n", produto[i].descricao, produto[i].quantidade);
	
		}
	}
}




void listando(PRODUTO produto[MAX_PROD])
{	// mostra as opções de listagem do programa
	// e lê qual a opção (opc) que o usuário deseja usar
	////////////////////////////////////////////

	int opc;
	system("clear");
	printf("Opções de listagem \n\n");
	printf("1- Listar todos\n2- Menor para o maior\n3- Ordem Alfabetica\n4- quantidade em estoque\n");
	scanf("%d", &opc);
	
	system("clear");	
	switch (opc)
	{
		case 1:
		listaTudo(produto);
		break;
		case 2:
		listaMenor(produto);
		break;
		case 3:
		ordemAlfabetica(produto);
		break;
		case 4:
		ordemEstoque(produto);
		break;
		default:
		printf("Comando desconhecido\n");
	}


}

void listaTudo(PRODUTO produto[MAX_PROD])
{
	//percorre o vetor de 0 a MAX_PROD - 10 (até a posição 989)
	// imprimindo todos os produtos que tenham 
	/////////////
	int i;
	

	for(i = 0; i < MAX_PROD-10; i++)
	{
		if(produto[i].valor > 0.01)
		{	
			// mostrando todos os produtos com o valor maior que 0.1 -
			printf("Descrição: %s \n", produto[i].descricao);
			printf("\tCódigo: %i\t Preço: %.2f", produto[i].cod, produto[i].valor);
			printf("\tQuantidade em estoque: %i\n", produto[i].quantidade);
			printf("\tFabricante: %s\n", produto[i].fabricante);
			printf("\tCategoria: %s", produto[i].categoria);
			printf("\tValidade: %i/%i/%i \n", produto[i].validade.dia, produto[i].validade.mes, produto[i].validade.ano);
			printf("\tLocal - Corredor: %i Prateleira: %i\n\n", produto[i].local.corredor, produto[i].local.prateleira);
			
				
		}
	
	}
	printf("\n\n");

}





void listaMenor(PRODUTO produto[MAX_PROD])
{
	int i;


	qsort(produto, MAX_PROD-10, sizeof(PRODUTO), cmpNum);


for(i = 0; i < MAX_PROD-10; i++)
	{		
					
			
			if(produto[i].valor > 0.01)
			{// mostrando todos os produtos com o valor maior que 0.1 -
				printf("Descrição: %s \n", produto[i].descricao);
				printf("\tCódigo: %i\t Preço: %.2f", produto[i].cod, produto[i].valor);
				printf("\tQuantidade em estoque: %i\n", produto[i].quantidade);
				printf("\tFabricante: %s\n", produto[i].fabricante);
				printf("\tCategoria: %s", produto[i].categoria);
				printf("\tValidade: %i/%i/%i \n", produto[i].validade.dia, produto[i].validade.mes, produto[i].validade.ano);
				printf("\tLocal - Corredor:%i Prateleira:%i\n\n", produto[i].local.corredor, produto[i].local.prateleira);		
			}
	}
	printf("\n\n");	

}

void ordemAlfabetica(PRODUTO produto[MAX_PROD])
{
	int i;
	qsort(produto, MAX_PROD-10, sizeof(PRODUTO), cmpAlfabeto);


for(i = 0; i < MAX_PROD-10; i++)
	{		
					
			
			if(produto[i].valor > 0.01)
			{// mostrando todos os produtos com o valor maior que 0.1 -
				printf("Descrição: %s \n", produto[i].descricao);
				printf("\tCódigo: %i\t Preço: %.2f", produto[i].cod, produto[i].valor);
				printf("\tQuantidade em estoque: %i\n", produto[i].quantidade);
				printf("\tFabricante: %s\n", produto[i].fabricante);
				printf("\tCategoria: %s", produto[i].categoria);
				printf("\tValidade: %i/%i/%i \n", produto[i].validade.dia, produto[i].validade.mes, produto[i].validade.ano);
				printf("\tLocal - Corredor:%i Prateleira:%i\n\n", produto[i].local.corredor, produto[i].local.prateleira);		
			}
	}
	printf("\n\n");	

}

void ordemEstoque(PRODUTO produto[MAX_PROD])
{
	int i;
	qsort(produto, MAX_PROD-10, sizeof(PRODUTO), cmpEstoque);


for(i = 0; i < MAX_PROD-10; i++)
	{		
					
			
			if(produto[i].valor > 0.01)
			{// mostrando todos os produtos com o valor maior que 0.1 -
				printf("Descrição: %s \n", produto[i].descricao);
				printf("\tCódigo: %i\t Preço: %.2f", produto[i].cod, produto[i].valor);
				printf("\tQuantidade em estoque: %i\n", produto[i].quantidade);
				printf("\tFabricante: %s\n", produto[i].fabricante);
				printf("\tCategoria: %s", produto[i].categoria);
				printf("\tValidade: %i/%i/%i \n", produto[i].validade.dia, produto[i].validade.mes, produto[i].validade.ano);
				printf("\tLocal - Corredor:%i Prateleira:%i\n\n", produto[i].local.corredor, produto[i].local.prateleira);		
			}
	}
	printf("\n\n");	

}


void imprimeCategoria (PRODUTO produto[MAX_PROD])
{	
	int i, opc;
	system("clear");
	printf("1- Mostrar dividido por categoria\n2- Mostrar categoria\n");
	scanf("%i", &opc);
	if(opc == 1)
	{
		imprimeTudoCat(produto);
	}
	else if (opc == 2)
	{
		system("clear");
		printf("1- Alimentos pereciveis\n2- Alimentos não pereciveis\n3- Eletrônicos\n4- Limpeza\n");
		printf("categoria desejada:\n");
		scanf("%i", &opc);

		switch(opc){
		
			case 1:

				printf("ALIMENTOS PERECÍVEIS\n====================================================================\n");
				for(i = 0; i < MAX_PROD - 10; i++)
				{	

					if( strcmp(produto[i].categoria, "ALP") == 0)
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
				printf("====================================================================\n");
			break;
			
			case 2:
			
				printf("ALIMENTOS NÃO PERECÍVEIS\n====================================================================\n");

				for(i = 0; i < MAX_PROD - 10; i++)
				{	

					if( strcmp(produto[i].categoria, "ALNP") == 0)
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
			break;	

			case 3:

				printf("ELETRÔNICOS\n====================================================================\n");
				for(i = 0; i < MAX_PROD - 10; i++)
				{	

					if( strcmp(produto[i].categoria, "ELETRÔNICO") == 0)
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
				printf("====================================================================\n");
			
			break;

			case 4:
				printf("LIMPEZA\n====================================================================\n");	
				for(i = 0; i < MAX_PROD - 10; i++)
				{	

					if( strcmp(produto[i].categoria, "LIMPEZA") == 0)
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
				printf("====================================================================\n");
			break;
			default:
			printf("Comando desconhecido\n");	
		}	
	}	
}




void imprimeTudoCat(PRODUTO produto[MAX_PROD])
{

	int i;


	printf("\nALIMENTOS PERECÍVEIS\n====================================================================\n");
	for(i = 0; i < MAX_PROD - 10; i++)
	{	

		if( strcmp(produto[i].categoria, "ALP") == 0)
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
	
	printf("====================================================================\n");
	printf("ALIMENTOS NÃO PERECÍVEIS\n====================================================================\n");

	for(i = 0; i < MAX_PROD - 10; i++)
	{	

		if( strcmp(produto[i].categoria, "ALNP") == 0)
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

	printf("ELETRÔNICOS\n====================================================================\n");
	for(i = 0; i < MAX_PROD - 10; i++)
	{	

		if( strcmp(produto[i].categoria, "ELETRÔNICO") == 0)
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
	printf("====================================================================\n");
	printf("LIMPEZA\n====================================================================\n");
		

	for(i = 0; i < MAX_PROD - 10; i++)
	{	

		if( strcmp(produto[i].categoria, "LIMPEZA") == 0)
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
	printf("====================================================================\n");

}