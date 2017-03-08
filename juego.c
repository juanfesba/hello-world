#include <stdio.h>
#include <stdlib.h>

void inicializarJuego(int nfilas,int ncolumnas,int** nmatrix){
	int i,j;
	printf("Bienvenido\n");
	for(i=0;i<nfilas;i++){
		nmatrix[i]=(int*)malloc(ncolumnas*sizeof(int));
		for(j=0;j<ncolumnas;j++){
			nmatrix[i][j]=i+j;
		}
	}
}

void dibujarJuego(int nfilas,int ncolumnas,int** nmatrix){
	int i,j;
	for(i=0;i<nfilas;i++){
		for(j=0;j<ncolumnas;j++){
			printf("%d\t",nmatrix[i][j]);
		}
	printf("\n");
	}
}

//**argv
int main(int argc,char* argv[]){
	int filas=atoi(argv[1]);
	int columnas=atoi(argv[2]);
	int** matrix;
	matrix=(int**)malloc(filas*sizeof(int*));
	inicializarJuego(filas,columnas,matrix);
	dibujarJuego(filas,columnas,matrix);
	dibujarJuego(filas,columnas,matrix);
	return 0;
}
