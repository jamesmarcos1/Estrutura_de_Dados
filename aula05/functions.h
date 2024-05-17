// Função para trocar dois elementos de um vetor
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição para o Quicksort
int particao(int Vetor[], int inf, int sup)
{
    int pivot = Vetor[(inf + sup) / 2]; // Escolha do pivô como elemento central
    int i = inf - 1;
    int j = sup + 1;
    while (1)
    {
        do
        {
            i++;
        } while (Vetor[i] < pivot);
        do
        {
            j--;
        } while (Vetor[j] > pivot);
        if (i >= j)
            return j; // Os índices se cruzaram
        swap(&Vetor[i], &Vetor[j]);
    }
}

// Função Quicksort principal
void quicksort(int Vetor[], int inf, int sup)
{
    if (inf < sup)
    {
        // Encontre a posição do pivô
        int p = particao(Vetor, inf, sup);
        // Ordena os elementos antes e depois da partição
        quicksort(Vetor, inf, p);     // Chama recursiva para a parte esquerda
        quicksort(Vetor, p + 1, sup); // Chama recursiva para a parte direita
    }
}