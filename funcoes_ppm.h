#include <stdio.h>
#include <stdlib.h>
//#include "funcoes_ppm.h"
//#include "funcoes_bmp.h"
#define MAX 512


typedef struct{
	int r,rx;
	int g,gx;
	int b,bx;
	char tipo[2];
	int col,lin;
	int max;
	


}PPM;


void ler_ppm(char imagem[20]);
void codifica_ppm();
void decodifica_ppm();
void verifica_ppm();
