/*
 * HeapSort.h
 *
 * Author: skoctas
 */

#ifndef HEAPSORT_H_
#define HEAPSORT_H_

#include <iostream>
#include <vector>

using namespace std;

class HeapSort
    {
public:
    void heapify(vector<int>&, int, int);
    void heapSortAlgorithm(vector<int>&, int);
    void swapElements(int &, int &);
    };

#endif /* HEAPSORT_H_ */
