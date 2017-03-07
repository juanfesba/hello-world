/*
 * lenCadena.c
 *
 *  Created on: Feb 26, 2017
 *      Author: juanfesba
 */

#include <stdio.h>
#include <stdlib.h>

int longCadena(char *cad){
	int n=0;
	while(cad[n]!='\0'){
		n++;
	}
	return n;
}

int main (int argc,char *argv[]) {
  char *cad1=argv [1];

  int size;
  size=longCadena(cad1);
  printf("El tamaño de la cadena %s es: %d\n",cad1,size);

  return 0;
}
