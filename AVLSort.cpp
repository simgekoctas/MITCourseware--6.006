/*
 * AVLSort.cpp
 * Complexity: O(nlogn)
 * Author: skoctas
 */

#include "AVLSort.h"
#include <iostream>

using namespace std;


AVLTree* AVLSort::insertAVL(AVLTree* root, int data)
{
    if(root == NULL)
    {
	root = new AVLTree(data);
	return root;
    }

    if(root->data < data)
    {
	root->right = insertAVL(root->right, data);
    }
    else if(data < root->data)
    {
    	root->left = insertAVL(root->left, data);
    }

    root->height = 1 + returnMax(root->left, root->right);
    int difference = height(root->left) - height(root->right);

    if(difference > 1 && data < root->left->data)
    {
	root = rightRotate(root);
    }

    if(difference > 1 &&  root->left->data < data)
    {
    	root->left = leftRotate(root->left);
    	root = rightRotate(root);
    }

    if(difference < -1 && data < root->right->data)
    {
    	root->right = rightRotate(root->right);
    	root = leftRotate(root);
    }

    if(difference < -1 &&  root->right->data < data)
    {
	root = leftRotate(root);
    }

    return root;
}

AVLTree* AVLSort::leftRotate(AVLTree* root)
{
    AVLTree* temp = root->right->left;
    AVLTree* temp2 = root->right;

    root->right = temp;
    temp2->left = root;

    root->height = 1 + returnMax(temp, root->left);
    temp2->height = 1 + returnMax(root, temp2->right);

    return temp2;
}
AVLTree* AVLSort::rightRotate(AVLTree* root)
{
    AVLTree* temp = root->left->right;
    AVLTree* temp2 = root->left;

    root->left = temp;
    temp2->right = root;

    root->height = 1 + returnMax(temp, root->right);
    temp2->height = 1 + returnMax(root, temp2->left);

    return temp2;
}


int AVLSort::height(AVLTree* root)
{
    if(root == NULL)
	return 0;
    return root->height;
}

int AVLSort::returnMax(AVLTree* node1, AVLTree* node2)
{
    return height(node1) >= height(node2) ? height(node1) : height(node2);
}

int main(){

    AVLTree* root = NULL;

    AVLSort a;

    root = a.insertAVL(root, 30);
    root = a.insertAVL(root, 25);
    root = a.insertAVL(root, 37);
    root = a.insertAVL(root, 20);
    root = a.insertAVL(root, 28);
    root = a.insertAVL(root, 29);

    /*
    cout << "root->data: " << root->data << "\n";
    cout << "root->height: " << root->height << "\n";
    cout << "root->left->data: " << root->left->data << "\n";
    cout << "root->left->height: " << root->left->height << "\n";
    cout << "root->right->data: " << root->right->data << "\n";
    cout << "root->right->height: " << root->right->height << "\n";
     */
    return 0;
}

