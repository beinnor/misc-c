
#include "sorting.h"
#include "helpers.h"
#include <stdio.h>



/**
 * Bubble sort.
 * This is a simple sorting algorithm. The idea is to move higher valued
 * elements generally towards the right and lower valued elements generally to
 * the left.
 *
 * Even though the algorithm is simple, it is slow and impractical for most
 * problems even when compared to insertion sort. It is mostly useful for
 * educational purposes.
 *
 * WORST CASE:
 *  O(n²). The array is in reverse order; we have to "bubble" each of the
 *  n elements all the way across the array, and since we can only fully bubble
 *  one element into position per pass, we must do this n times.
 *
 * BEST CASE:
 *  Ω(n). The array is already sorted and we make no swaps at the first pass.
 *
 *
 * PSEUDO CODE:
 *  - Set swap counter to a non-zero value
 *  - Repeat until swap counter is zero
 *    - Reset swap counter to 0
 *    - Look at each adjacent pair
 *      - If two adjacent pairs is not in order, swap them and
 *        add one to the swap counter.
 *
 *
 * @param array     array
 * @param arraySize size of array
 */
void bubbleSort(int *array, int arraySize)
{

  int swapcounter = -1;

  while (swapcounter != 0) {
    swapcounter = 0;

    for (int i = 0; i < arraySize - 1; i++) {

      if (array[i] > array[i+1]) {
        swapValues(array, i, i+1);
        swapcounter++;
      }

    }

  }

}


/**
 * Selection sort
 * In selection sort, the idea of the algorithm is to find the smallest
 * unsorted element and add it to the end of the sorted list.
 *
 * WORST CASE:
 *  O(n²). We must iterate over each of the n elements of the array (to find
 *  the smallest unsorted element) and we must repeat this process n times,
 *  since only one element gets sorted on each pass.
 *
 * BEST CASE:
 *  Ω(n²). Exactly the same.
 *  There is no way to guarantee the array is sorted until
 *  we go through this process for all the elements.
 *
 * PSEUDO CODE:
 * - Repeat until no unsorted elements remain:
 *   - Search the unsorted part of the data to find the smallest value
 *   - Swap the smallest found value with the first element
 *     of the unsorted part.
 *
 *
 * @param array     the array
 * @param arraySize size of the array
 */
void selectionSort(int *array, int arraySize)
{

  for (int i = 0; i < arraySize; i++) {

    int min = i;

    for (int j = i; j < arraySize; j++) {

      if (array[min] > array[j]) {

        min = j;

      }

    }

    swapValues(array, i, min);

  }
}


/**
 * Insertion sort iterates, consuming one input element each repetition,
 * and growing a sorted output list. Each iteration, insertion sort removes one
 * element from the input data, finds the location it belongs within the sorted
 * list, and inserts it there. It repeats until no input elements remain.
 *
 * This is the way most people would sort a deck of cards.
 *
 * WORST CASE:
 * O(n²). The array is in reverse order; we have to shift each of the n
 * elements n positions each time we make an insertion.
 *
 * BEST CASE:
 * Ω(n). The array is already perfectly sorted, and we simply keep moving the
 * line between "unsorted" and "sorted" as we examine each element.
 *
 *
 * PSEUDO CODE:
 *
 * - Call the first element of the array "sorted"
 * - Repeat until all elements are sorted:
 *  - Look at the next unsorted element. Insert into "sorted" portion by
 *    shifting the requisite number of elements.
 *
 * Sources: https://en.wikipedia.org/wiki/Insertion_sort,
 *          HarvardX: CS50 Introduction to Computer Science
 *
 * @param array     the array
 * @param arraySize size of the array
 */
void insertionSort(int *array, int arraySize)
{

  for (int i = 0; i < arraySize; i++) {

    int j = i;

    int toInsert = array[i];

    while ((j > 0) && (array[j-1] > toInsert)) {

      array[j] = array[j-1];
      j--;

    }

    array[j] = toInsert;

  }

}

/**
 * Merge sort splits the full array into subarrays, then merges those subarrays
 * back into the correct order.
 *
 * WORST CASE:
 * n log n. We have to split n elements up and then recombine them, effectively
 * doubling thesorted subarrays as we build them up. (combining sorted
 * 1-element arrays into 2-element arrays, combining sorted 2-element arrays
 * into 4-element arrays...).
 *
 * BEST CASE:
 * n log n. The array is already perfectly sorted. But we still have to split
 * and recombine it back together with this algorithm.
 *
 *
 * PSEUDO CODE:
 *
 * - Sort the left half of the array (assuming n > 1)
 * - Sort the right half of the array (assuming n > 1)
 * - Merge the two halves together
 *
 * Sources: https://en.wikipedia.org/wiki/Insertion_sort,
 *          HarvardX: CS50 Introduction to Computer Science
 *
 * @param array     the array
 * @param arraySize size of the array
 */
void mergeSort(int *array, int arraySize)
{
  if (arraySize == 1) { // only 1 element, e.g. already sorted
    return;
  }

  sort(0, arraySize, array);

}

void sort(int left, int right, int *array)
{
  int mid;

  if (left < right) {
    mid = (left + right) / 2;
    sort(left, mid, array);
    sort(mid+1, right, array);
    merge(left, mid, right, array);
  } else {
    return;
  }


}


void merge(int left, int mid, int right, int *array)
{
  int l1, l2, i;
  int b[left+right];

  for (l1 = left, l2 = mid+1, i = left; l1 <= mid && l2 <= right; i++) {
    if(array[l1] <= array[l2])
      b[i] = array[l1++];
     else
      b[i] = array[l2++];
  }

  while (l1 <= mid)
    b[i++] = array[l1++];

  while (l2 <= right)
    b[i++] = array[l2++];

  for (i = left; i <= right; i++)
      array[i] = b[i];
}
