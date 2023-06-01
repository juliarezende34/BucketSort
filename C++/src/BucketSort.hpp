#ifndef BUCKETSORT_HPP
#define BUCKETSORT_HPP
#include <iostream>
#include <vector>
#define tam_bucket 100
#define num_bucket 10
#define tam_vet 10

using namespace std;

class BucketSort{
    public:
        int topo;
        int balde[tam_bucket];

        BucketSort();

        void bucket_sort(int v[],int tam);
        void countingSort(int array[], int size);
        void imprimir(int v[], int tam);


};
#endif