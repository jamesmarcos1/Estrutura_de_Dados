#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para representar um ponto
typedef struct {
    float X;
    float Y;
} Ponto;

// Função para calcular a área de um triângulo formado pelos pontos A, B e C
float AreaDoTriangulo(Ponto A, Ponto B, Ponto C) {
    float area = (A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y)) / 2;
    return (area < 0) ? -area : area; // Garante que a área seja sempre positiva
}

int main() {
    FILE *arquivo;
    int numVertices, i;
    Ponto *vertices;
    float areaTotal = 0;

    // Abre o arquivo para leitura
    arquivo = fopen("vertices.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê o número de vértices do polígono
    fscanf(arquivo, "%d", &numVertices);

    // Aloca memória para armazenar os vértices
    vertices = (Ponto *)malloc(numVertices * sizeof(Ponto));
    if (vertices == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    // Lê os vértices do arquivo
    for (i = 0; i < numVertices; i++) {
        fscanf(arquivo, "%f %f", &vertices[i].X, &vertices[i].Y);
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Calcula a área total do polígono dividindo-o em triângulos
    for (i = 1; i < numVertices - 1; i++) {
        areaTotal += AreaDoTriangulo(vertices[0], vertices[i], vertices[i + 1]);
    }

    // Exibe a área total do polígono
    printf("A área do polígono é %.2f\n", areaTotal);

    // Libera a memória alocada
    free(vertices);

    return 0;
}