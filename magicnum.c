/*
 * magicnum.c
 *
 *  Created on: Feb 20, 2017
 *      Author: juanfesba
 */

/*Juan Fernando Escobar - Laboratorio de Programación*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define RAND_MAX 100
//#define intentos 8

int numMag(int intentos,int *history){
	int x=99999;
	int i=0;
	int tries=intentos;
	//int history[intentos];
	srand(time(NULL));
	int key=rand()%101;
	int key2=rand()%101;
	//printf("la llaves son %d y %d\n",key,key2);
	printf("Ingresa un número entre el 1 y el 100. Tienes %d intentos: ",tries);
	do{
		scanf("%d",&x);
		history[i++]=x;
		tries-=1;
		if ((x==key+key2) || (x==(key*key2)) || (x==(key-key2)) || (x==(key2-key))){
			break;
		}
		if(x<key && x<key2){
			printf("Es menor que las dos llaves. Te quedan %d intentos: ",tries);
		}
		if(x>key && x<key2){
			printf("Esta entre los dos numeros. Te quedan %d intentos: ",tries);
		}
		if(x<key && x>key2){
			printf("Esta entre los dos numeros. Te quedan %d intentos: ",tries);
		}
		if(x>key && x>key2){
			printf("Es mayor que las dos llaves. Te quedan %d intentos: ",tries);
		}
	}while(x!=key && x!=key2 && tries!=0);
	if(tries==0 && x!=key){
		printf("Por lo tanto has fallado!! Tus intentos fueron: \n");
	}
	else{
		printf("Enhorabuena!!!! Tus intentos fueron: \n");
	}
	for(x=0;x<i;x++){
		printf("%d  ",history[x]);
	}
	printf("\n");
	return i;
}

int main () {
	int *story;
	int x,n;
	printf("Ingresa la cantidad de intentos: ");
	scanf("%d",&n);
	story=(int*)malloc(sizeof(int)*n);
	x= numMag(n,story);
	printf("En total fueron %d intentos\n",x);
	return 0;
}
