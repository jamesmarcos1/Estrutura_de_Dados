#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main() {
    FILE * fp;
    fp = fopen("pagina.html", "w");

    if(fp == NULL) {
        printf("ARQUIVO NÂO FOI ABERTO");
        exit(1);
    }

    printf("ARQUIVO ABERTO COM SUCESSO!!!");
    fclose(fp);
    return 0;
}