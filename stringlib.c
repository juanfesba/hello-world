/*
 * stringlib.c
 *
 *  Created on: Feb 20, 2017
 *      Author: juanfesba
 */

#include <stdio.h>
#include <stdlib.h>

int longCadena(char*cad);
void copiarCadenas(char *origen,char *destino);
void haciaMayusculas(char *cad);
void copiarN(char *cadOrigen,char *cadDestino,int n);
void copiarSub(char *cadOrigen, char *cadDestino, int n, int m);
int compararCadenas(char *cad1, char *cad2);
void concatenarCadenas(char *cad1,char *cad2,char* cad3);
void asignarCadena(char *cad1,char car);
int existeCaracter (char *cad1, char car);
int posIniCaracter (char *cad1, char car);
int posFinCaracter (char *cad1, char car);

int main(){
	//Creacion de cadenas para probar las funciones
	//char cad1[]={'h','o','l','a','\0'};
	char *cad1="Juan";
	char *cad2, *cad3, *cad4;

	//uso de LongCadena
	int size;
	size=longCadena(cad1);
	printf("El tamaño de la cadena %s es: %d\n",cad1,size);

	//copia de cadena y hacia mayusculas
	cad2=(char*)malloc(longCadena(cad1)+1);
	copiarCadenas(cad1,cad2);
	haciaMayusculas(cad2);
	printf("Copiar %s y pasarla a mayúsculas >>> %s\n",cad1,cad2);

	//copiarN
	int n=2;
	cad3=(char*)malloc(sizeof(char)*n);
	copiarN(cad2,cad3,n);
	printf("Copiar los primeros %d elementos de %s >>> %s\n",n,cad2,cad3);

	//copiar sub cadena
	n=1;
	int m=2;
	cad4=(char*)malloc(sizeof(char)*(m-n+1));
	copiarSub(cad1,cad4,n,m);
	printf("Copiar %s desde la posición %d hasta %d >>> %s\n",cad1,n,m,cad4);

	//comparar cadenas
	char *cad5="xy";
	char *cad6="abc";
	char *cad7="ABC";
	n=3;
	n=compararCadenas(cad5, cad6);
	printf("Al comparar %s con %s, n tomo el valor de: %d\n",cad5,cad6,n);
	n=compararCadenas(cad2, cad2);
	printf("Al comparar %s con %s, n tomo el valor de: %d\n",cad2,cad2,n);
	n=compararCadenas(cad7, cad6);
	printf("Al comparar %s con %s, n tomo el valor de: %d\n",cad7,cad6,n);

	//concatenar
	char *cadConc;
	cadConc=(char*)malloc(sizeof(char)*(longCadena(cad2)+longCadena(cad3)+1));
	concatenarCadenas(cad2,cad3,cadConc);
	printf("Concatenar %s y %s >>> %s\n",cad2,cad3,cadConc);

	//asignar caracter a la cadena
	printf("Asignemos a la cadena %s el caracter X. ",cad2);
	asignarCadena(cad2,'X');
	printf("Obtuvimos %s\n",cad2);

	//existe caracter
	n=existeCaracter(cad7,'X');
	printf("La cadena %s contiene a X?: %d\n",cad7,n);
	n=existeCaracter(cad7,'B');
	printf("La cadena %s contiene a B?: %d\n",cad7,n);

	//posicion del caracter desde la izquierda
	printf("De izquierda a derecha\n");
	n=posIniCaracter(cad7,'C');
	printf("El caracter C para la cadena %s se encuentra en la pos: %d\n",cad7,n);
	n=posIniCaracter(cad7,'X');
	printf("El caracter X para la cadena %s se encuentra en la pos: %d\n",cad7,n);

	//posicion del caracter desde la derecha
	printf("De derecha a izquierda\n");
	n=posFinCaracter(cad7,'C');
	printf("El caracter C para la cadena %s se encuentra en la pos: %d\n",cad7,n);
	n=posFinCaracter(cad7,'X');
	printf("El caracter X para la cadena %s se encuentra en la pos: %d\n",cad7,n);

	return 0;
}

int longCadena(char *cad){
	int n=0;
	while(cad[n]!='\0'){
		n++;
	}
	return n;
}

//char* copiarCadenas(char *origen,char *destino){
//hacer malloc por dentro no es recomendable por ahora (tiene que ver con las variables locales)
void copiarCadenas(char *origen,char *destino){
	int i;
	for(i=0;i<=longCadena(origen);i++){
		destino[i]=origen[i];
	}
}

void haciaMayusculas(char *cad){
	int i=0;
	while (i<longCadena(cad)){
		if ((cad[i]>96) && (cad[i]<123)){
			cad[i]=cad[i]-32;
		}
		i++;
	}
}

void copiarN(char *cadOrigen,char *cadDestino,int n){
	int i=0;
	while(i<n){
		cadDestino[i]=cadOrigen[i];
		i++;
	}
}

void copiarSub(char *cadOrigen, char *cadDestino, int n, int m){
	int i=n;
	while (i<=m){
		cadDestino[i-n]=cadOrigen[i];
		i++;
	}
}

int compararCadenas(char *cad1, char *cad2){
	int n;
	if (cad1>cad2){
		n=1;
	}
	else{
		if (cad2>cad1){
			n=-1;
		}
		else{
			n=0;
		}
	}
	return n;
}

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
	cadDestino[longCadena(cadOrig1)+longCadena(cadOrig2)]='\0';
}

void asignarCadena(char *cad1,char car){
	int i=0;
	while (i<longCadena(cad1)){
		cad1[i]=car;
		i++;
	}
}

int existeCaracter (char *cad1, char car){
	int i=0;
	while (i<longCadena(cad1)){
		if (cad1[i]==car){
			return 1;
		}
		i++;
	}
	return 0;
}

int posIniCaracter (char *cad1, char car){
	int i=0;
	while (i<longCadena(cad1)){
		if (car==cad1[i]){
			i++;
			return i;
		}
		i++;
	}
	return -1;
}

int posFinCaracter (char *cad1, char car){
	int i=longCadena(cad1)-1;
	while(i>=0){
		if (car==cad1[i]){
			i++;
			return longCadena(cad1)+1-i;
		}
		i--;
	}
	return -1;
}
