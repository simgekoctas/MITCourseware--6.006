/*
 * InsertionSort.h
 *
 * Author: skoctas
 */

#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_

class InsertionSort
    {
public:
    void InsertionSortAlgorithm(int*, int);
    void adjustArray(int*, int, int);
    void pairwiseSwap(int*, int, int);
    void showArray(int*, int);
    int BinarySearch(int*, int, int, int);

    };

#endif /* INSERTIONSORT_H_ */
