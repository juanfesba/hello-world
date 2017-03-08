#include <stdio.h>
#include <stdlib.h>

int main(){
	int* p;
	p=(int*)malloc(sizeof(int)*3);
	*p=2;
	*(p+1)=3;
	*(p+2)=7;
	int i;
	for(i=0;i<3;i++){
		printf("Valor de la posición %d del array: %d\n",i,p[i]);
	}

	int *q[2];
	q[0]=(int*)malloc(3*sizeof(int));
	q[1]=(int*)malloc(5*sizeof(int));
	q[0][0]=3;
	q[1][4]=7;
	printf("%d %d\n",q[0][0],q[1][4]);
	return 0;

	int **z;
	z=(int**)malloc(5*sizeof(int*));
	z[0]=(int*)malloc(3*sizeof(int));
}
