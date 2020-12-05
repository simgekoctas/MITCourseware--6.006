/*
 * InsertionBinarySort.cpp
 *
 * Author: skoctas
 */

#include "InsertionBinarySort.h"
#include <iostream>

using namespace std;

void InsertionBinarySort::showArray(int* array, int size)
{
    cout << "Array:" << "\n";
    for(int i = 0; i < size; i++)
	{
	    cout << *(array + i) << " ";
	}
    cout << "\n";
}

void InsertionBinarySort::pairwiseSwap(int* array, int pos1, int pos2)
{
    for(int i = pos1; i > pos2; i--)
    {
	int temp = *(array + i);
	*(array + i) = *(array + i - 1);
	*(array + i - 1) = temp;
    }
}

void InsertionBinarySort::BinaryInsertionSortAlgorithm(int* array, int size)
{
    for(int i = 1; i < size; i++)
    {
	int loc = BinarySearch(array, 0, i - 1, *(array + i));
	pairwiseSwap(array, i, loc);
    }
}

int InsertionBinarySort::BinarySearch(int* array, int low, int high, int element)
{
    if(high <= low ){ // if the there is only one element, return the index of the correct position
	return *(array + high) > element ? high : high + 1;
    }

    int mid = low + (high - low) / 2;

    if(element > *(array + mid)){ // if the element is larger than the middle element, look at the second half of the array
	BinarySearch(array, mid + 1, high, element);
    }

    else if(element < *(array + mid)){ // if the element is smaller than the middle element, look at the first half of the array
	BinarySearch(array, low, mid - 1, element);
    }

}
/*
int main()
{
    int arr[6] = {8, 2, 4, 9, 3, 7};
    int size = 6;
    InsertionBinarySort in;

    in.BinaryInsertionSortAlgorithm(arr, size);
    in.showArray(arr, size);
}
*/
