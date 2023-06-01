#include "BucketSort.hpp"
#include <chrono>
#include <iomanip>
int main(){
    BucketSort * b = new BucketSort();
    //int cont = tam_vet - 1;
    int vet[tam_vet];
        for(int i=0; i< tam_vet; i++){
            vet[i]=rand()%100 +1;
            //vet[i] = i;//vetor crescente 
            //vet[i] = cont;//vetor decrescente 
            //cont--;
        }
    printf("Vetor que será ordenado:\n");
    b->imprimir(vet, tam_vet);
    chrono::steady_clock::time_point inicio = chrono::steady_clock::now();
    b->bucket_sort(vet, tam_vet);
    chrono::steady_clock::time_point fim = chrono::steady_clock::now();
    chrono::duration<double, milli> tempo = (fim- inicio);
    printf("\n\nResultado - Vetor Ordenado:\n");
    b->imprimir(vet,tam_vet);
    cout<<"TEMPO DE EXECUÇÃO: "<< fixed  << setprecision(2)<< tempo.count() <<" ms "<<endl;
    return 0;
}