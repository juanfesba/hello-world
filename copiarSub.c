/*
 * copiarSub.c
 *
 *  Created on: Feb 26, 2017
 *      Author: juanfesba
 */

#include <stdio.h>
#include <stdlib.h>

void copiarSub(char *cadOrigen, char *cadDestino, int n, int m);

void copiarSub(char *cadOrigen, char *cadDestino, int n, int m){
	int i=n;
	while (i<=m){
		cadDestino[i-n]=cadOrigen[i];
		i++;
	}
}

int main(int argc,char* argv[]){
	char* cad1=argv[1];
	int n=argv[2][0]-'0';
	int m=argv[3][0]-'0';
	char* cad2;
	cad2=(char*)malloc((m-n+1)*sizeof(char));
	copiarSub(cad1,cad2,n,m);
	printf("Copiar %s desde la posición %d hasta %d >>> %s\n",cad1,n,m,cad2);
	return 0;
}
