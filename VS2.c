#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int fatorial(int n);

#define ERRO_ 

int main() {
	system("cls");
	int n;
	
	printf("Digite um Valor: ");
	scanf("%d", &n);
	if(n >= 1) {
		printf("Resultado : %d ", fatorial(n));
	} else {
		printf("Numero invalido");
	}
	
 return 0;
}

int fatorial(int n) {
	int fat;
	for(fat = 1; n > 1; n = n - 1)
	fat = fat * n;
}
