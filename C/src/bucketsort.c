#include "bucketsort.h"

void countingSort(int array[], int size) {
// Encontre o maior elemento do array
    int maximo = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > maximo)
            maximo = array[i];
    }

// Crie um array de contagem com tamanho (max+1)
    int count[maximo + 1];

// Inicialize o array de contagem com zeros
    for (int i = 0; i <= maximo; ++i) {
        count[i] = 0;
    }

// Conte a ocorrência de cada elemento
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

// Atualize o array de contagem para conter a posição correta de cada elemento
    for (int i = 1; i <= maximo; i++) {
        count[i] += count[i - 1];
    }

// Crie um array de saída para armazenar os elementos ordenados
    int output[size];

// Coloque cada elemento na posição correta do array de saída
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

// Copie os elementos ordenados para o array original
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

void print(int v[], int tam){

    for(int i=0; i<tam; i++){
        printf("%d|", v[i]);
    }
    printf("\n-----------------\n");
}

void bucket_sort(int v[],int tam){
    bucket b[num_bucket];
    int i,j,k;
    for(i=0;i<num_bucket;i++) //Inicializa o "topo"
        b[i].topo=0;

    for(i=0;i<tam;i++){ //Verifica em que balde o elemento do vetor deve ficar
        int aux = (int) (v[i]/num_bucket);
        b[aux].balde[b[aux].topo] = v[i];
        (b[aux].topo)++;
    }

    printf("Condição dos Baldes\n");
    for(int k=0; k< num_bucket; k++){
        printf("\n Balde %d: ", k);
        for(int i =0; i<b[k].topo; i++){
            printf("%d|",b[k].balde[i]);
        }
    }

    for(i=0;i<num_bucket;i++) //Ordena os baldes utilizando o BubbleSort
        if(b[i].topo)
            countingSort(b[i].balde, b[i].topo);
                    //bubble(b[i].balde,b[i].topo);

    printf("\n\nCondição dos Baldes após Counting Sort\n");
    for(int k=0; k< num_bucket; k++){
        printf("\n Balde %d: ", k);
        for(int i =0; i<b[k].topo; i++){
            printf("%d|",b[k].balde[i]);
        }
    }
    
    i=0;

    for(j=0;j<num_bucket;j++){ //Coloca os elementos dos baldes de volta no vetor
        for(k=0;k<b[j].topo;k++){
            v[i]=b[j].balde[k];
            i++;
        }
    }
}