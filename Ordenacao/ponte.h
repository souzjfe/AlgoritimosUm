typedef struct OBJETO
{
    int key;
}OBJETO;

void swap(OBJETO *a, OBJETO *b);

void bubble(OBJETO *vetorASerOrdenado, int tamanhoVetor);

void printVetor(OBJETO *vetor, int tamanho);

void inserirAleatoriosNoVetor(OBJETO *vetor,int tamanho);

void selection(OBJETO *vetorASerOrdenado, int tamanhoVetor);

void insertion(OBJETO *vetorASerOrdenado, int tamanhoVetor);