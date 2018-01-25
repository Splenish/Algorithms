#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Swap two elements of an array
void swap(int *array, int firstIndex, int secondIndex) {
    int temp;
    temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

//Search the index of the smallest value of an sub-array
int indexOfMin(int *array, int startIndex, int arrayLength) {

    //First set the smallest value and index to correspond with the chosen element
    int minValue = array[startIndex];
    int minIndex = startIndex;

    //Start comparing the chosen element to other elements
    for(int i = minIndex + 1; i < arrayLength; i++) {
        //If a element is smaller than that becomes new smallest element
        if (array[i] < minValue) {
            minIndex = i;
            minValue = array[i];
        }
    }
    //Return the index of the smallest element of the sub-array
    return minIndex;
}

//Selection sort selects the smallest value of the sub-array
//and swaps it with the first element of the sub-array
void selectionSort(int *array, int arrayLength) {
    int min;
    for(int i = 0; i < arrayLength; i++){
        //index of min returns the smallest element
        //of the sub-array, starting at element i
        min = indexOfMin(array, i, arrayLength);
        //swaps the smallest element with the first element
        //of the sub-array
        swap(array, i, min);
    }
}



int main()
{
    //seed random and initialize variables
    srand(time(NULL));
    int arraySize;

    //prompt for array size
    printf("give array size ");
    scanf("%d", &arraySize);

    int numbers[arraySize];
    //generate random array
    for(int i = 0; i < arraySize; i++) {
        numbers[i] = (rand() % 100)+1;
    }

    //print original array
    printf("array:\n");
    for(int i = 0; i < arraySize; i++) {
        printf("%d\n", numbers[i]);
    }

    //do a selection sort
    selectionSort(numbers, (sizeof(numbers)/sizeof(numbers[0])));

    //print sorted array
    printf("sorted array:\n");
    for(int i = 0; i < arraySize; i++) {
        printf("%d\n", numbers[i]);
    }
    return 0;
}
