/*
 * HeapSort.cpp
 * Complexity: O(nlogn)
 * Author: skoctas
 */

#include "HeapSort.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void HeapSort::swapElements(int& element1, int& element2) // swapping vector elements, we get the elements by its reference so it can take an effect in the original vector
{
    int temp = element1;
    element1 = element2;
    element2 = temp;
}

void HeapSort::heapify(vector<int>& vec, int size, int element_index)
{
    int left_index = 2 * element_index + 1; // left child index
    int right_index = 2 * element_index + 2; // right child index
    int left_child = -1; // if there is no left or right child, we are assinging a default value of -1
    int right_child = -1;

    if(left_index >= size && right_index >= size){ // if the node is a leave node
        return;
    }

    if(left_index < size) // if there is a left node, find it in the vector. If we dont check this and try to access the index that is not a part of vector, it gives an error
	left_child =  vec.at(2 * element_index + 1);
    if(right_index < size) // if there is a right node, find it in the vector
	right_child = vec.at(2 * element_index + 2);

    int max;
    int max_index;

    if(left_child <= right_child && right_index < size){ // we should not look at the nodes that are bigger than the size. We find the max child node
	max = right_child;
	max_index = right_index;
    }
    else if(left_child >= right_child && left_index < size){
	max = left_child;
	max_index = left_index;
    }

    if(vec.at(element_index) < max){ // if the child is bigger than its parent, we swap the elements
	swapElements(vec.at(element_index), vec[max_index]);
	heapify(vec, size, max_index); // we call heapify again for checking the smaller elements position and if it needs to be swapped by the other childs. The childs need to be adjusted before go to the top of the tree
    }
    else{
	return;
    }

}

void HeapSort::heapSortAlgorithm(vector<int> &vec, int size)
{
    while(size != 0){ //we are starting from the last parent node, go up to the parent node. If swapping happens, before going to up, the swapped element need to be checked if it satisfies the conditions

	int lastparent = size/2 - 1; // last parent index

	    for(int i = lastparent; i >= 0; i--){
		heapify(vec, size, i); // calling heapify to check the parent
	    }

	    if(vec.at(0) > vec.at(size - 1)){
		swapElements(vec.at(0), vec.at(size - 1));
	    }
	    size--;
    }

}

int main()
{
    int size = 0;
    int element;

    cout << "Enter the size of the vector to be sorted:" <<"\n";
    cin >> size;

    vector<int> vec;
    vector<int>::iterator itr;

    cout << "Enter the elements of the vector, enter -1 to finish:" << "\n";
    while(cin >> element && element != -1)
    {
	vec.push_back(element);
    }

    cout << "Elements:" << "\n";
    for(itr = vec.begin(); itr != vec.end(); itr++)
    {
	cout << *itr << " ";
    }
    cout << "\n";

    HeapSort h;

    auto start = high_resolution_clock::now();

    h.heapSortAlgorithm(vec, size);

    cout << "Elements after sort:" << "\n";
    for(itr = vec.begin(); itr != vec.end(); itr++)
    {
    	cout << *itr << " ";
    }
    cout << "\n";

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds";


}

