#include <stdio.h>

//Searches the index of a target value in an sorted array
int binarySearch(int array[], int target, int arraySize) {

    int min = 0;
    int max = arraySize - 1;
    int guess;

    //Loops the search until target is found or there are no more elements in the subarray
    while(max >= min) {

        //Always guesses the middle index of the array
        guess = (min+max)/2;
        //If the value in the guessed index is the target value return the index
        if(array[guess] == target) {
            return guess;
            //If the target is bigger than the value in the guessed index, the next index from guess becomes
            //the minimum index of the subarray
        } else if(array[guess] < target) {
            min = guess + 1;
            //If the target is smaller than the value in the guessed index, the previous index from guess
            //becomes the maximum index of the subarray
        } else {
            max = guess - 1;
        }
    //If the target value is not in the array return -1 as an error
    }
    return -1;
}

int main()
{
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int result = binarySearch(primes, 97, (sizeof primes / sizeof primes[0]));   //sizeof primes / sizeof primes[0] gives length of the array
    printf("Found prime at index %d\n", result);
    return 0;
}
