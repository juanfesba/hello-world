#include <stdio.h>
#include <stdlib.h>

void haciaMayusculas(char *cad);
int longCadena(char *cad);
void copiarCadenas(char *origen,char *destino);

void haciaMayusculas(char *cad){
	int i=0;
	while (i<longCadena(cad)){
		if ((cad[i]>96) && (cad[i]<123)){
			cad[i]=cad[i]-32;
		}
		i++;
	}
}

int longCadena(char *cad){
	int n=0;
	while(cad[n]!='\0'){
		n++;
	}
	return n;
}

void copiarCadenas(char *origen,char *destino){
	int i;
	for(i=0;i<=longCadena(origen);i++){
		destino[i]=origen[i];
	}
}

void main(int argc, char *argv[]){
	char *cad2;
	char *cad1=argv[1];
	cad2=(char*)malloc(longCadena(cad1)+1);
	copiarCadenas(cad1,cad2);
	haciaMayusculas(cad2);
	printf("La cadena %s pasarla a mayúsculas >>> %s\n",cad1,cad2);
}
