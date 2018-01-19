#include <stdio.h>

//Searches the index of a target value in an array
int binarySearch(int array[], int target, int arraySize) {
    int min = 0;

    int max = arraySize - 1;
    int guess;

    while(max >= min) {
        guess = (min+max)/2;

        if(array[guess] == target) {
            return guess;
        } else if(array[guess] < target) {
            min = guess + 1;
        } else {
            max = guess - 1;
        }
    }
    return -1;
}

int main()
{
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int result = binarySearch(primes, 7, (sizeof primes/primes[0]));
    printf("Found prime at index %d\n", result);
    return 0;
}
