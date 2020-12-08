/*
 * BSTSort.cpp
 * Complexity: O(nlogn), worst case: O(n^2)
 * Author: skoctas
 */

#include "BSTSort.h"
#include <iostream>
#include <array>

using namespace std;

Node* BSTSort::CreateBinarySeachTree(Node* root, int data){

    if(root == NULL){
	return new Node(data);
    }

    if(root->data > data){
	root->left = CreateBinarySeachTree(root->left, data);
    }
    else{
	root->right = CreateBinarySeachTree(root->right, data);
    }

    return root;

}

void BSTSort::BinarySearchTreeSorting(Node* root){

    if(root == NULL){
	return;
    }

    BinarySearchTreeSorting(root->left);
    cout << root->data << " ";
    BinarySearchTreeSorting(root->right);
}


int main(){

    Node* root = NULL;
    BSTSort b;

    array<int, 10> arr = {15, 12, 20,7, 18, 13, 25, 5, 16, 32};

    for(auto itr = begin(arr); itr != end(arr); itr++){
	root = b.CreateBinarySeachTree(root, *itr);
    }

    b.BinarySearchTreeSorting(root);

    return 0;

}



