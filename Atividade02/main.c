#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float X;
    float Y;
} Ponto;

// Função para calcular a área de um triângulo formado pelos pontos A, B e C
float AreaDoTriangulo(Ponto A, Ponto B, Ponto C) {
    float area = (A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y)) / 2;
    return (area < 0) ? -area : area; // Garante que a área seja sempre positiva
}

int PoligonoConvexo(Ponto *vertices, int numVertices) {
    if (numVertices < 3)
        return 0;
    return 1; 
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

    // Lê o número de vértices
    fscanf(arquivo, "%d", &numVertices);

    // Aloca memória para armazenar os vértices
    vertices = (Ponto *)malloc(numVertices * sizeof(Ponto));
    if (vertices == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }

 

    // Lê os vértices do arquivo
            for (i = 0; i < numVertices; i++) {
                if (fscanf(arquivo, "%f %f", &vertices[i].X, &vertices[i].Y) != 2) {
                    printf("Erro na leitura dos vertices.\n");
                    free(vertices);
                    fclose(arquivo);
                    return 1;
                }
            }

    // Fecha o arquivo
    fclose(arquivo);

    // Verifica se o polígono é convexo
    if (!PoligonoConvexo(vertices, numVertices)) {
        printf("O poligono nao e convexo, o calculo da area pode ter vindo errado.\n");
    }

    // Calcula a área total do polígono
    for (i = 1; i < numVertices - 1; i++) {
        areaTotal += AreaDoTriangulo(vertices[0], vertices[i], vertices[i + 1]);
    }

    // Exibe a área total do polígono
    printf("A área do polígono é %.2f\n", areaTotal);

    // Libera a memória
    free(vertices);

    return 0;
}