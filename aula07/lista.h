#ifdef Lista
#define lista

typedef struct
{
    int chave;
}Item;

typedef struct
{
    int capacidade;
    int Tam;
    Item *array;
}Lista;

Lista * criarLista(int Capacidade);
