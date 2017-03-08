#include <stdio.h>
#include <stdlib.h>

void swap2(int *a, int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

int main(int argc, char *argv[]){
	int x=atoi(argv[1]);
	int y=atoi(argv[2]);
	swap2(&x,&y);
	printf("Swap: %d %d\n",x,y);
	return 0;
}
