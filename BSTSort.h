/*
 * BSTSort.h
 *
 * Author: skoctas
 */

#ifndef BSTSORT_H_
#define BSTSORT_H_

#include <iostream>
#include <array>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data){
	this->data = data;
	left = NULL;
	right = NULL;
    }
};

class BSTSort
    {
public:
    Node* CreateBinarySeachTree(Node*, int);
    void BinarySearchTreeSorting(Node*);
    };

#endif /* BSTSORT_H_ */
