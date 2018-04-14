#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "helpers.h"


/**
 * Generates a shuffled array of specific size, with
 * integers from 0 to size - 1.
 *
 * @param array the array
 * @param size  size of the array
 */
void generateShuffledArray(int *array, int size) {

  int i;
  time_t t;

  // Initalize srand
  srand((unsigned) time(&t));

  // Fill array
  for (i = 0; i < size; i++) {

    array[i] = i;

  }

  int random;
  int swap;

  // Shuffle array using Fisher-Yates shuffle algorithm
  for (i = size - 1; i > 1; i--) {

    random = rand() % i;
    swap = array[i];
    array[i] = array[random];
    array[random] = swap;

  }

}


/**
 * Prints the array 'beautifully'
 *
 * @param array the array
 * @param size  size of the array
 */
void printArray(int *array, int size) {

  int i;

  for (i = 0; i < size * 4; i++) {
    printf("-");
  }

  printf("\n");

  for (i = 0; i < size; i++) {
    printf("| %d ", array[i]);
  }

  printf("|\n");

  for (i = 0; i < size * 4; i++) {
    printf("-");
  }

  printf("\n");

}


/**
 * Prints a table with marks in two cells.
 * Useful when visualizing array operations.
 *
 * @param size  size of array
 * @param mark1 first mark
 * @param mark2 second mark
 */
void printMarkedArray(int size, int mark1, int mark2)
{
  // TODO: Make this function better and more universal


  int i;

  for (i = 0; i < size * 4; i++) {
    printf("-");
  }

  printf("\n");

  for (i = 0; i < size; i++) {
    if (i == mark1 || i == mark2) {
      printf("| X ");
    } else {
      printf("|   ");
    }
  }

  printf("|\n");

  for (i = 0; i < size * 4; i++) {
    printf("-");
  }

  printf("\n");

}


/**
 * Simple, swaps to values in an array.
 *
 * @param array  array where swap occurs
 * @param first  first value
 * @param second second value
 */
void swapValues(int *array, int first, int second)
{
  int temp = array[first];
  array[first] = array[second];
  array[second] = temp;
}
