#include<stdio.h>

int main(){
	int wys; int gwia; int spac; 
  int i; int j; int k;
	printf("Podaj wielkosc choinki: ");
	scanf("%d", &wys);
	spac = wys - 1;
	gwia=1;

	for(i=0; i < wys; i++){
		for(j=0; j<spac; j++){
			printf(" ");	
		}
	for(k=0; k < gwia; k++){
		printf("*");
	}
		spac--;
		gwia+=2;
		printf("\n");
	}
	return 0;
}

