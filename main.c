#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes_ppm.h"
#include "funcoes_bmp.h"
// Testando o github 

int main(int argc, char *argv[]){
char imagem[20];
strcpy(imagem,argv[6]);


if(!(strcmp(argv[5],"ppm"))){
ler_ppm(imagem);
}

if(!(strcmp(argv[5],"bmp"))){
ler_bmp();
}
//alterado

return 0;
}

