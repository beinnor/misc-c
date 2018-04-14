#include "searching.h"

/**
 * Linear search sequentially checks each element of the array for a specific
 * value until a match is found or until all the elements have been searched.
 *
 * Linear search worst case performance is O(n).
 *
 * Source: https://en.wikipedia.org/wiki/Linear_search
 *
 * @param  array array to search
 * @param  size  size of array
 * @param  n     number to search for
 * @return       negative if not found, else index where found
 */
int linearSearch(int *array, int size, int n)
{

  for (int i = 0; i < size; i++) {

    if (array[i] == n) {
      return i;
    }

  }

  return -1; // not found

}


/**
 * Binary search is a search algorithm that finds the position of a specific
 * value within a sorted array. It compares the target value to the
 * middle element of the array; if they are unequal,
 * the half in which the target cannot lie is eliminated and the search
 * continues on the remaining half until it is successful.
 *
 * Binary Search worst case performance is O(log n).
 *
 * Source: https://en.wikipedia.org/wiki/Binary_search_algorithm
 *
 * @param  sortedArray     the sorted array to search
 * @param  arraySize size of the array
 * @param  n         number to search for
 * @return           negative if not found, else index where found
 */
int binarySearch(int *sortedArray, int arraySize, int n)
{

  int lowIndex = 0;
  int highIndex = arraySize - 1;

  while (lowIndex <= highIndex) {

    int middleIndex = (highIndex + lowIndex) / 2;

    if (sortedArray[middleIndex] < n) {

      lowIndex = middleIndex + 1;

    } else if (sortedArray[middleIndex] > n) {

      highIndex = middleIndex - 1;

    } else {

      return middleIndex; // found it

    }

  }

  return -1;  // did not find it
}
