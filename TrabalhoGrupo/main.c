#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar os dados de um aluno
typedef struct Aluno {
    char nome[50];
    float n1, n2;
} Aluno;

// Função para calcular a média das notas de um aluno
float Media(Aluno aluno) {
    return (aluno.n1 + aluno.n2) / 2.0;
}

// Função para determinar a situação do aluno (APROVADO ou REPROVADO)
const char* Situacao_Final(float media) {
    if (media >= 7.0) {
        return "APROVADO";
    } else {
        return "REPROVADO";
    }
}

int main() {
    FILE *Arquivo_entrada = fopen("DadosEntrada.csv", "r");
    FILE *Arquivo_saida = fopen("SituacaoFinal.csv", "w");

    if (Arquivo_entrada == NULL || Arquivo_saida == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    Aluno aluno;
    while (fscanf(Arquivo_entrada, " %[^;];%*[^;];%*[^;];%f;%f\n", aluno.nome, &aluno.n1, &aluno.n2) == 3) {
            // Converter caracteres especiais
            for (int i = 0; i < strlen(aluno.nome); i++) {
                if (aluno.nome[i] == '�') {
                    aluno.nome[i] = 'ã';
                }
            }
            float media = Media(aluno);
            const char *situacao = Situacao_Final(media);
            fprintf(Arquivo_saida, "%s;%.2f;%s\n", aluno.nome, media, situacao);
        }

    fclose(Arquivo_entrada);
    fclose(Arquivo_saida);

    printf("Arquivo SituacaoFinal.csv gerado com sucesso!\n");

    return 0;
}
