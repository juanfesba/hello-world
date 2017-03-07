/*
 * existeCar.c
 *
 *  Created on: Feb 26, 2017
 *      Author: juanfesba
 */

#include <stdio.h>
#include <stdlib.h>

int existeCaracter (char *cad1, char car);
int longCadena(char*cad);

int longCadena(char *cad){
	int n=0;
	while(cad[n]!='\0'){
		n++;
	}
	return n;
}

int existeCaracter (char *cad, char car){
	int i;
	for(i=0;i<longCadena(cad);i++){
		if (cad[i]==car){
			return 1;
		}
	}
	return 0;
}

int main(int argc, char *argv[]){
	int n;
	char* cad1=argv[1];
	char *cad2=argv[2];
	char car=cad2[0];
	n=existeCaracter(cad1,car);
	printf("La cadena %s contiene a %c?: >>> %d\n",cad1,car,n);
	return 0;
}
