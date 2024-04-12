#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void exibirArray(int array[], int tamanho);
void modificarArray(int *array, int tamanho);
int *criarArray(int tamanho);

int  main() {
    int T;
    int *Vetor = criarArray(T);
    printf("DIGITE UM INTEIRO: ");
    scanf("%d", &T);
    
    
    exibirArray(Vetor, T);
    modificarArray(Vetor, T);
    exibirArray(Vetor, T);
    return 0;
}

void exibirArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Valor[%d]: %d\n", i, array[i]);
    }
    printf("\n");
}

void modificarArray(int *array, int tamanho) {
    printf("Endereco: %p\n", (void *)array); // Exibe o endereço corretamente
    for (int i = 0; i < tamanho; i++) {
        array[i] = array[i] * 2;
    }
}


int *criarArray(int tamanho) {
    int *array = malloc(tamanho * sizeof(int)); // Alocação
    for(int i = 0; i < tamanho; i++) array[i] = 2 * i - 1;
    return array; // indica o endereço do vetor
}