#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"


void comeca(PRODUTO produto[MAX_PROD])
{	// For que percorre todo o vetor produto i = 0 a i = MAX_PROD zerando
	// configurando todos os campos para não dar erros no programa
	// Valor  = 0 - Significa que não existe produto na pocição
	// Quantidade = 11 - quantidade minima em estoque para alertar a funcionários é 10
	// Portanto set todos os produtos qua não existem (valores abaixo de 0.01) com o 
	// estoque acima do mínimo aceitável.
	////////////////////////////////////////////////////////////////////////////////
	
	int i;

	for (i = 0; i < MAX_PROD-10; i++)
	{	if( produto[i].valor < 0.01)
		{
			produto[i].valor = 0;
			produto[i].quantidade = 11;
		}
	}

}

void comecaCarro(PRODUTO carrinho[100])
{	// Funciona da mesma forma da função acima.
	int i;

	for (i = 0; i < MAX_PROD-10; i++)
	{	if( carrinho[i].valor < 0.01)
		{	
			carrinho[i].valor = 0;
			carrinho[i].quantidade = 11;
		}
	}

}




void iniciaEstoque(PRODUTO produto[MAX_PROD], FILE *estoque)
{	
	//irá percorrer o arquivo estoque.txt lendo todas as informações que foram salvas 
	// do vetor produto na última execução do programa.
	////////////////////////////////////////////////////////////////////////////////


	int i;
	for( i = 0; i < MAX_PROD-10; i++)
	{	
		fscanf(estoque, "%[^\n]", produto[i].descricao);
		fscanf(estoque, "%i\n %f %i ", &produto[i].cod, &produto[i].valor, &produto[i].quantidade);
		fscanf(estoque, "%s %s %i %i ",  produto[i].fabricante,	produto[i].categoria, &produto[i].validade.dia, &produto[i].validade.mes); 
		fscanf(estoque, "%i %i %i \n ", &produto[i].validade.ano, &produto[i].local.corredor, &produto[i].local.prateleira );
	}
	fclose(estoque);
}	

void iniciaCarrinho(PRODUTO carrinho[100], FILE *carro)
{	
	//irá percorrer o arquivo carro.txt lendo todas as informações que foram salvas
	// do vetor carrinho na última execução do programa.
	////////////////////////////////////////////////////////////////////////////////


	int i;
	for( i = 0; i < 100; i++)
	{	
		fscanf(carro, "%[^\n]", carrinho[i].descricao);// irá ler toda a linha exceto o \n
		fscanf(carro, "%i\n %f %i ", &carrinho[i].cod, &carrinho[i].valor, &carrinho[i].quantidade);  
		fscanf(carro, "%s %s %i %i",  carrinho[i].fabricante,	carrinho[i].categoria, &carrinho[i].validade.dia, &carrinho[i].validade.mes); 
		fscanf(carro, "%i %i %i \n ", &carrinho[i].validade.ano, &carrinho[i].local.corredor, &carrinho[i].local.prateleira );
	}


}	

void entradaArquivo(PRODUTO produto[MAX_PROD])
{	// irá ler o arquivo entrada.txt que contém as informações para 
	// preencher o vetor produto, caso o usuário deseje.
	//////////////////////////////////////////////////

	FILE *entrada;
	entrada = fopen("entrada.txt","r");
	int i;
	for( i = 0; i < MAX_PROD-10; i++)
	{
		

		while(produto[i].valor > 0.01) 
		{	// tem como objetivo achar um espaço vazio no vetor, tendo em vista que
			// o produto que na posição I tiver o valor 0, não existe.


			i++;
		}

		fscanf(entrada, "%[^\n]", produto[i].descricao);
		fscanf(entrada, "%i\n %f %i ", &produto[i].cod, &produto[i].valor, &produto[i].quantidade);
		fscanf(entrada, "%s %s %i %i ",  produto[i].fabricante,	produto[i].categoria, &produto[i].validade.dia, &produto[i].validade.mes); 
		fscanf(entrada, "%i %i %i \n ", &produto[i].validade.ano, &produto[i].local.corredor, &produto[i].local.prateleira );
	}

	fclose(entrada);
}	




void imprimeEstoque(PRODUTO produto [MAX_PROD])
{	// percorre todo o vetor produto de i=0 até i < MAX_PROD - 10 (989)
	// imprimindo todas as informações do vetor produto no arquivo estoque.txt
	////////////////////////////////////////////////////////////
	int i;
	FILE *estoque;
	estoque = fopen("estoque.txt","w");
	for( i = 0; i < MAX_PROD-10; i++)
	{	if(produto[i].valor >= 0.01) // só irá gravar os produtos existentes, ou seja, produtos com valor acima de 0.01
		{ 
			fprintf(estoque, "%s\n %i %.2f %i ",produto[i].descricao, produto[i].cod, produto[i].valor, produto[i].quantidade);
			fprintf(estoque, "%s %s %i %i ",  produto[i].fabricante, produto[i].categoria, produto[i].validade.dia, produto[i].validade.mes); 
			fprintf(estoque, "%i %i %i \n", produto[i].validade.ano, produto[i].local.corredor, produto[i].local.prateleira );
		}
	}
	fclose(estoque);
}	


void imprimeCarrinho(PRODUTO carrinho [100])
{	// percorre todo o vetor carrinho de i = 0 a i < 100 gravando
	// todas as suas informações no arquivo carro.txt
	////////////////////////////////////////////////////////////


	int i;
	FILE *carro;
	carro = fopen("carro.txt","w");
	for( i = 0; i < 100; i++)
		{	if(carrinho[i].valor >= 0.01)
			{
				fprintf(carro, "%s\n %i %.2f %i ", carrinho[i].descricao, carrinho[i].cod, carrinho[i].valor, carrinho[i].quantidade);
				fprintf(carro, "%s %s %i %i ",  carrinho[i].fabricante,	carrinho[i].categoria, carrinho[i].validade.dia, carrinho[i].validade.mes); 
				fprintf(carro, "%i %i %i \n", carrinho[i].validade.ano, carrinho[i].local.corredor, carrinho[i].local.prateleira );
			}	
		}
	fclose(carro);
}



