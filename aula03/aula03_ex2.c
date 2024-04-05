#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define Erro 1

struct Pessoa
{
    char Nome[100];
    int Idade;
    float Altura;
    float Peso;
};


int main() {

    system("cls");

    struct Pessoa X;
    printf("%d", sizeof(X)); //Calcula e exibe a quantidade de bytes de X;
    printf("Nome: ");
    scanf("%s", &X.Nome);
    printf("Idade: ");
    scanf("%d", &X.Idade);
    printf("Altura: ");
    scanf("%f", &X.Altura);
    printf("Peso: ");
    scanf("%f", &X.Peso);

    printf("%s %d %.2f %.2f \n", X.Nome, X.Idade, X.Altura, X.Peso);



}
