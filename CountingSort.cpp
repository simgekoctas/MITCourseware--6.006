/*
 * CountingSort.cpp
 * Counting sort for both positive and negative elements. Complexity: O(n + k), n is the number of elements in the vector, k is the range of the count vector
 * Author: skoctas
 */

#include "CountingSort.h"
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void printVector(vector<int> vect){

    vector<int>::iterator itr;

    for(itr = vect.begin(); itr != vect.end(); itr++){
	cout << *itr << " ";
    }
    cout << "\n";
}

int findMin(vector<int> vect){

    int min = vect.at(0);
    vector<int>::iterator itr;

    for(itr = vect.begin(); itr != vect.end(); itr++){
	if(*itr < min)
	    min = *itr;
    }

    return min;
}

int findMax(vector<int> vect){

    int max = vect.at(0);
    vector<int>::iterator itr;

    for(itr = vect.begin(); itr != vect.end(); itr++){
	if(*itr > max){
	    max = *itr;
	}
    }

    return max;
}

void CountingSortAlgorithm(vector<int> &vect){

    int min = findMin(vect);
    int max = findMax(vect);
    int size = max - min + 1;

    vector<int> count(size);
    vector<int> output(vect.size());
    vector<int>::iterator itr;


    for(itr = vect.begin(); itr != vect.end(); itr++){
	count[*itr - min]++;
    }

    for(int i = 0; i < size; i++){
	count[i + 1] += count[i];
    }

    for(auto it = vect.rbegin(); it != vect.rend(); it++){
	output[count[*it - min] - 1] = *it;
	count[*it - min]--;
    }

    vect = output;

}

int main(){

   vector<int> vect = {-5, -4, -7, 0, 7, -3, 11, 9};
   CountingSortAlgorithm(vect);
   printVector(vect);

   return 0;
}

