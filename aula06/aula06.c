#include <stdio.h>
#include <stdlib.h>

#define VERDADEIRO 1
#define FALSO 0

// defindo o TAD Fração

typedef struct {
    int Num;
    int Den;
} Fracao;

int mdc(int A, int B);
void mostrarFracao(Fracao F);
Fracao criarFracao(int A, int B);
Fracao simplificarFracao(Fracao F);
Fracao somarFracao(Fracao F, Fracao G);
Fracao subtrairFracao(Fracao F, Fracao G);
Fracao multiplicarFracao(Fracao F, Fracao G);
Fracao dividirFracao(Fracao F, Fracao G);
Fracao inverterFracao(Fracao F, Fracao G);

int main() {

    Fracao Resultado;

    printf("Teste n. 1: Simplicando fracao: ");
    Fracao F = criarFracao(20, 30);
    Resultado = simplificarFracao(F);
    mostrarFracao(Resultado);
    printf("\n");

    printf("Teste n. 2: Somando as fracoes 5/6 e 4/9: ");
    Fracao F1 = criarFracao(5, 6);
    Fracao F2 = criarFracao(4, 9);
    Resultado = somarFracao(F1, F2);
    mostrarFracao(Resultado);
    printf("\n");

    printf("Teste n. 3: Subtraindo as fracoes 5/6 e 4/9: ");
    Fracao F3 = criarFracao(5, 6);
    Fracao F4 = criarFracao(4, 9);
    Resultado = subtrairFracao(F3, F4);
    mostrarFracao(Resultado);
    printf("\n");

    printf("Teste n. 4: Multiplicando as fracoes 5/7 e 21/20: ");
    Fracao F5 = criarFracao(5, 7);
    Fracao F6 = criarFracao(21, 20);
    Resultado = multiplicarFracao(F5, F6);
    mostrarFracao(Resultado);
    printf("\n");

    return 0;
}

Fracao criarFracao(int A, int B){
    Fracao X;
    X.Num = A;
    X.Den = B;
    return X;
}

int mdc(int A, int B){
    int Menor;
    int M = 1;
    A = abs(A);
    B = abs(B);
    if  (A > B) Menor = B;
    else Menor = A;
    for (int i = 1; i <= Menor; i++) {
        if ((A % i == 0) && (B % i == 0)) M = i;
    }
    return M;
}

Fracao simplificarFracao(Fracao F){
    int temp = mdc(F.Num, F.Den);
    F.Num = F.Num / temp;
    F.Den = F.Den / temp;
    return F;
}

void mostrarFracao(Fracao F){
    printf("%d/%d", F.Num, F.Den);
}

Fracao somarFracao(Fracao F, Fracao G){
    Fracao Resultado;
    Resultado.Num = F.Num * G.Den + G.Num * F.Den;
    Resultado.Den = F.Den * G.Den;
    Resultado = simplificarFracao(Resultado);
    return Resultado;
}

Fracao subtrairFracao(Fracao F, Fracao G){
    Fracao Resultado;
    Resultado.Num = F.Num * G.Den - G.Num * F.Den;
    Resultado.Den = F.Den * G.Den;
    Resultado = simplificarFracao(Resultado);
    return Resultado;
}

Fracao subtrairFracao_V02(Fracao F, Fracao G){
    Fracao Resultado;
    G.Num = -G.Num;
    Resultado = somarFracao(F, G);
    return Resultado;
}

Fracao multiplicarFracao (Fracao F, Fracao G) {
    Fracao Resultado;
    Resultado.Num = F.Num * G.Num;
    Resultado.Den = F.Den * G.Den;
    Resultado = simplificarFracao(Resultado);
    return(Resultado);
}

