#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

void bubbleSort(int *array, int arraySize);
void selectionSort(int *array, int arraySize);
void insertionSort(int *array, int arraySize);

void mergeSort(int *array, int arraySize);
void sort(int low, int high, int *array); // mergeSort
void merge(int low, int mid, int high, int *array); // mergeSort

// TODO: void quickSort(int *array, int arraySize);


#endif
