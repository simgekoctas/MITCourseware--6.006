/*
 * AVLSort.h
 *
 * Author: skoctas
 */

#ifndef AVLSORT_H_
#define AVLSORT_H_

#include <iostream>

using namespace std;

struct AVLTree{

	int data;
	int height;
	AVLTree* left;
	AVLTree* right;

	AVLTree(int data)
	{
	   this->data = data;
	   height = 1;
	   left = NULL;
	   right = NULL;
	}
};


class AVLSort
{

    public:

	AVLTree* insertAVL(AVLTree*, int);
	int height(AVLTree*);
	int returnMax(AVLTree*, AVLTree*);
	AVLTree* leftRotate(AVLTree*);
	AVLTree* rightRotate(AVLTree*);


};

#endif /* AVLSORT_H_ */
