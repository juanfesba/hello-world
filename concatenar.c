#include <stdio.h>
#include <stdlib.h>

void concatenarCadenas(char *cad1,char *cad2,char* cad3);
int longCadena(char *cad);

void concatenarCadenas(char *cadOrig1,char *cadOrig2,char *cadDestino){
	int i=0,j=0;
	while (i<(longCadena(cadOrig1)+longCadena(cadOrig2))){
		if (i<longCadena(cadOrig1)){
			cadDestino[i]=cadOrig1[i];
		}
		else{
			cadDestino[i]=cadOrig2[j];
			j++;
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

int main(int argc, char *argv[]){
	char *cad2=argv[1];
	char *cad3=argv[2];
	char *cadConc;
	cadConc=(char*)malloc(sizeof(char)*(longCadena(cad2)+longCadena(cad3)+1));
	concatenarCadenas(cad2,cad3,cadConc);
	printf("Concatenar %s y %s >>> %s\n",cad2,cad3,cadConc);
	return 0;
}
