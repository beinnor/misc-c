

## Summary

Algorithm Name | Basic Concept | O (worst case) | Ω (best case)
---------------|---------------|----------------|--------------
Selection sort | Find the *smallest* unsorted element in an array and swap it with the *first* unsorted element of that array. | n² | n²
Bubble sort | Swap *adjacent pairs* of elements if they are out of order, effectively "bubbling" larger elements to the right and smaller ones to the left. | n² | n
Insertion sort | Proceed once through the array from left-to-right, *shifting* elements as necessary to insert each element into its correct place. | n² | n
Merge sort | *Split* the full array into subarrays, then *merge* those subarrays back together in the correct order. | n log n | n log n
Linear search | *Iterate* across the array from left-to-right, trying to find the target element. | n | 1
Binary search | Given a **sorted** array, *divide and conquer* by systematically eliminating half of the remaining elements in the search for the target element. | log n | 1
