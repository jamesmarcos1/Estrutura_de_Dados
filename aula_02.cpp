#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char minusculo();
char maiusculo ();

int main() {
	system("cls");
	char letra = minusculo();
	printf("\nCaractere em minusculo: %c\n", letra);
	char letragrande = maiusculo();
	printf("\nCaractere em maiusculo: %c\n", letragrande);
	return 0;
}

char minusculo () {
	
	char ch = getche(); // ler 1 caracter
	
	if((ch >= 'A') && (ch <= 'Z')) {
		return ch + 32;
	} else {
		return ch;
	}
}

char maiusculo () {
	
	char cd = getche(); // ler 1 caracter
	
	if((cd >= 'a') && (cd <= 'z')) {
		return cd - 32;
	} else {
		return cd;
	}
}
