#include <stdio.h>

//Insertion sort builds the sorted array one element at a time


void insert(int *array, int rightIndex, int value) {
    int j;
    for(j = rightIndex; array[j] > value && j >= 0; j--) {
        array[j+1] = array[j];
    }
    array[j+1] = value;
}

void insertionSort(int *array, int arrayLength) {
    for(int i = 1; i < arrayLength; i++) {
        insert(array, i-1, array[i]);
    }
}


int main()
{
    int numbahs[] = {67, 423, 3, 457, 1, 46};

    insertionSort(numbahs, (sizeof(numbahs)/sizeof(numbahs[0])));

    for(int i = 0; i < 6; i++) {
        printf("%d\n", numbahs[i]);
    }
    return 0;
}
