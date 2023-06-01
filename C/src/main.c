#include "bucketsort.h"

int main (){
    int vet[tam_vet];
        for(int i=0; i< tam_vet; i++){
            vet[i]=rand()%100 +1;
        }
    printf("Vetor que será ordenado:\n");
    print(vet, tam_vet);
    clock_t start = clock();
    bucket_sort(vet,tam_vet);
    clock_t end = clock();
    printf("\n\nResultado - Vetor Ordenado:\n");
    print(vet,tam_vet);
    double cpu_time_used = ((double)(end - start)) / (CLOCKS_PER_SEC / 1000.0);

    printf("Tempo de execução: %.2f milissegundos\n", cpu_time_used);
    
    return 0;
}