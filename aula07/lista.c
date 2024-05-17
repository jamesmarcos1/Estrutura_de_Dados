#include <stdlib.h>
#include <stdio.h>

#include "lista.h"

Lista * criarLista(int capacidade) {

    Lista *L = (Lista *) malloc (sizeof(Lista));
    if (L == NULL) {
        printf("Erro ao alocar memoria para Lista\n");
    }
}