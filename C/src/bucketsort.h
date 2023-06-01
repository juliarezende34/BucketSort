#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam_bucket 100
#define num_bucket 10
#define max 10
#define tam_vet 10


typedef struct {
    int topo;
    int balde[tam_bucket];
}bucket;

void bucket_sort(int v[],int tam);
void countingSort(int array[], int size);
void print(int v[], int tam);