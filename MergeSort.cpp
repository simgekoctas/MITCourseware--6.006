/*
 * MergeSort.cpp
 * complexity: O(nlogn)
 * Author: skoctas
 */

#include "MergeSort.h"
#include <iostream>

using namespace std;

void MergeSort::MergeSortAlgorithm(int* array, int low, int high)
{
    if(high > low){

	int mid = low + (high - low)/2; // find the middle element to divide the array

	MergeSortAlgorithm(array, low, mid); // call the first part of the array until the size of the array becomes 1 (only one element)
	MergeSortAlgorithm(array, mid + 1, high); // call the second part of the array until the size of the array becomes 1 (only one element)

	Merge(array, low, mid, high); // when there will be more than 1 element in the array, start the merge process

    }
}

void MergeSort::Merge(int* array, int low, int mid, int high)
{

    int firstsize = mid - low + 1; // size of the first half of the array
    int secondsize = high - mid; // size of the second half of the array

    int L[firstsize];
    int R[secondsize];


    for(int i = 0; i < firstsize; i++) // get the elements in the first half
    {
	*(L + i) = *(array + low + i);
    }

    for(int j = 0; j < secondsize; j++) // get the elements in the second half
    {
    	*(R + j) = *(array + mid + 1 + j);
    }

    showArray(L, firstsize);
    showArray(R, secondsize);

    int k = low; // k controls the 'array' boundaries so it needs to start with low so that it can write to the relevant position in the 'array'
    int i = 0; // controls the L array
    int j = 0; // controls the R array

    while(k <= high) // while there are elements in the array
    {
	if(*(L + i) < *(R + j) && i < firstsize) // if the element in L is smaller than R, make adjustments in the 'array' itself. Also, if L has more elements remaining, continue to write them to the 'array'
	{
	    *(array + k) = *(L + i);
	    i++;
	    k++;
	}
	else if (*(L + i) > *(R + j) && j < secondsize) // if the element in R is smaller than L, make adjustments in the 'array' itself. Also, if R has more elements remaining, continue to write them to the 'array'
	{
	    *(array + k) = *(R + j);
	    j++;
	    k++;
	}
	else{
	    return;
	}
    }

}

void MergeSort::showArray(int* array, int size)
{
    cout << "Array:\n";
    for(int i = 0; i < size; i++)
	{
	    cout << *(array + i) << " ";
	}
    cout << "\n";
}

int main()
{
    int array[6] = {12, 11, 13, 5, 6, 7};
    MergeSort m;
    m.MergeSortAlgorithm(array, 0, 5);
    m.showArray(array, 6);
}

