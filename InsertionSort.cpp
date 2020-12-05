/*
 * InsertionSort.cpp
 *
 * Author: skoctas
 */

#include <iostream>
#include "InsertionSort.h"

using namespace std;

//Start from the second element in the array and if you find an element smaller, pairwise swap the elements or shift the elements to make a room for the element
void InsertionSort::InsertionSortAlgorithm(int* array, int size)
{
    for(int i = 1; i < size; i++)
    {
	for(int j = 0; j < i; j++)
	{
	    if(*(array + j) > *(array + i)){
		pairwiseSwap(array, i, j); // used for pairwise swaps
	    }
	    /*Use this for shifting the elements instead of pairwise swaps
	    if(*(array + j) > *(array + i)){
		int temp = *(array + i);
		adjustArray(array, i, j);
		*(array + j) = temp;
	    }
	    */
	}
    }

}

//If you find an smaller element, make pairwise swaps until the smaller element finds its correct position
void InsertionSort::pairwiseSwap(int* array, int pos1, int pos2)
{
    for(int i = pos1; i > pos2; i--)
    {
	int temp = *(array + i);
	*(array + i) = *(array + i - 1);
	*(array + i - 1) = temp;
    }
}

//If you find an element smaller, shifts the elements so that the smaller element can be positioned to the correct location
void InsertionSort::adjustArray(int* array, int pos1, int pos2)
{
    for(int i = pos1; i > pos2; i--)
    {
    	*(array + i) = *(array + i - 1);
    }
}

void InsertionSort::showArray(int* array, int size)
{
    cout << "Array:\n";
    for(int i = 0; i < size; i++)
	{
	    cout << *(array + i) << " ";
	}
    cout << "\n";
}

int InsertionSort::BinarySearch(int* array, int low, int high, int element)
{
    if(high <= low ){
	return *(array + high) > element ? high : high + 1;
    }

    int mid = low + (high - low) / 2;

    if(element > *(array + mid)){
	BinarySearch(array, mid + 1, high, element);
    }

    else if(element < *(array + mid)){
	BinarySearch(array, low, mid - 1, element);
    }

}

int main()
{
    int arr[6] = {8, 2, 4, 9, 3, 7};
    int size = 6;
    InsertionSort in;

    in.InsertionSortAlgorithm(arr, size);
    in.showArray(arr, size);
}

