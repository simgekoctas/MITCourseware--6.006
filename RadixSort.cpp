/*
 * RadixSort.cpp
 * Complexity: O(n)
 * Author: skoctas
 */

#include "RadixSort.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void showVector(vector<int> vect){
    vector<int>::iterator itr;

    cout << "Vector:\n";
    for(itr = vect.begin(); itr != vect.end(); itr++){
	cout << *itr << " ";
    }
    cout << "\n";
}

int getMax(vector<int> vect){
    vector<int>::iterator itr;
    int max = vect.at(0);

    for(itr = vect.begin(); itr != vect.end(); itr++){
	if(*itr > max){
	    max = *itr;
	}
    }

    return max;
}

void RadixSortAlgorithm(vector<int>& vect, int exp, int n){

    vector<int>::iterator itr;
    vector<int> count(10);
    vector<int> output(n);


    for(itr = vect.begin(); itr != vect.end(); itr++){
	count[(*itr / exp) % 10]++;
    }

    for(int i = 0; i < 9; i++){
	count[i + 1] += count[i];

    }

    for(auto it = vect.rbegin(); it != vect.rend(); it++){
	output[count[(*it / exp) % 10] - 1] = *it;
	count[(*it / exp) % 10]--;
    }

    for(int i = 0; i < n; i++){
	vect[i] = output[i];

    }

}

/* Use this if the vector contains all positive elements
int main(){

    vector<int> vect = {329, 12, 457, 100, 25, 157, 12, 9};
    int n = 8;

    int max = getMax(vect);
    int exp = 1;

    while(max / exp != 0){
	RadixSortAlgorithm(vect, exp, n);
	cout << "inside while vect:" << "\n";
	showVector(vect);
	exp *= 10;

    }

    cout << "before radixsort:" << "\n";
    showVector(vect);

    cout << "after radixsort:" << "\n";
    showVector(vect);

    return 0;
}
*/

// Use this for vectors containing negative or positive elements
int main(){

    vector<int> vect = {-3, -1, -2, 329, 12, 457, 100, 25, 157, 12, 9};
    vector<int>::iterator itr;
    vector<int> posvect;
    vector<int> negvect;
    int pos_n = 0;
    int neg_n = 0;
    int max1, max2;

    for(itr = vect.begin(); itr != vect.end(); itr++){ // if a vector contains negative elements, seperate negative and positive elements
	if(*itr < 0){
	    int i = *itr;
	    negvect.push_back(i - i * 2); // change negative elements into positive
	    neg_n++;
	}
	else{
	    posvect.push_back(*itr);
	    pos_n++;
	}
    }

    if(neg_n != 0){
	max1 = getMax(negvect);
    }

    if(pos_n != 0){
	max2 = getMax(posvect);
    }
    int exp = 1;

    while(max1 / exp != 0 && neg_n != 0){
	RadixSortAlgorithm(negvect, exp, neg_n);
	exp *= 10;
    }
    exp = 1;

    while(max2 / exp != 0 && pos_n != 0){
	RadixSortAlgorithm(posvect, exp, pos_n);
	exp *= 10;
    }

    if(neg_n != 0){ // make the negative elements negative again
	for(itr = negvect.begin(); itr != negvect.end(); itr++){
	    int i = *itr;
	    i =  i - i * 2;
	    *itr = i;
	}
	reverse(negvect.begin(), negvect.end()); // reverse the vector

	itr = posvect.begin();
	posvect.insert(itr, negvect.begin(), negvect.end()); // append negative vector in front of the positive vector
	showVector(posvect);
    }
    else{
	showVector(posvect);
    }

    return 0;
}



