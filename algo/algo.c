#include <stdio.h>
#include "helpers.h"
#include "searching.h"
#include "sorting.h"


int main (int argc, char *argv[])
{

  int arraySize = 10;

  int array[arraySize];

  generateShuffledArray(array, arraySize);

  printf("Unsorted array:\n");
  printArray(array, arraySize);
/*
  int searchFor = 5;

  int whereIsIt = linearSearch(array, arraySize, searchFor);

  if (whereIsIt > 0) {
    printf("\nFound %d at index %d!\n", searchFor, whereIsIt);
  } else {
    printf("\n%d is not in array\n", searchFor);
  }
*/


  // bubbleSort(array, arraySize);
  // selectionSort(array, arraySize);
  // insertionSort(array, arraySize);
  mergeSort(array, arraySize);


  printf("Sorted array:\n");
  printArray(array, arraySize);


  int searchFor = 33;

  int whereIsIt = linearSearch(array, arraySize, searchFor);

  if (whereIsIt > 0) {
    printf("\nFound %d at index %d!\n", searchFor, whereIsIt);
  } else {
    printf("\n%d is not in array\n", searchFor);
  }

}
