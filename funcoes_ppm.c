#include <stdio.h>
#include <stdlib.h>
#include "funcoes_ppm.h"


void ler(char imagem[20]){
PPM ppm[MAX][MAX];
int i, j;

FILE *arquivo_ppm;

arquivo_ppm = fopen(imagem,"rb");

if(arquivo_ppm==NULL) { 
	printf("ERRO\n"); 
	} 
else{ 
	printf("OK!!\n");
	}


char tipo[2];
int col,lin;
int max;


fscanf(arquivo_ppm,"%s",ppm[0][0].tipo);
fscanf(arquivo_ppm,"%d %d",&ppm[0][0].col,&ppm[0][0].lin);
fscanf(arquivo_ppm,"%d",&ppm[0][0].max);

	for(i=0;i<512; i++){
		for (j=0;j<512;j++){
			fscanf(arquivo_ppm,"%d %d %d",&ppm[i][j].r,&ppm[i][j].g,&ppm[i][j].b);

		}
	
	}
fclose(arquivo_ppm);
}
