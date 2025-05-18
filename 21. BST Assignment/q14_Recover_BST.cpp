#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;

//Leetcode 99
//Recover Binary Search Tree

//see notes

class Node{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL; 
    }
};

// brute force
// time = O(n + nlogn + n)
// space = O(n + logn) 

//optimized approach

Node* prevNode;
Node* first;
Node* middle;
Node* last;
void inorder(Node* root){
    if(!root){
        return;
    }

    //go to left
    inorder(root->left);

    //logic
    if(root->data < prevNode->data){
        if(first == NULL){
            //first vialotion
            first = prevNode;
            middle = root;
        }
        else{
            //second vialation
            last = root;
        }
    }

    //go to right
    prevNode = root;
    inorder(root->right);
}
void recoverTree(Node* root) {
    first = middle = last = NULL;
    prevNode = new Node(INT_MIN);
    inorder(root);

    if(first && last){
        swap(first->data,last->data);
    }
    else{
        swap(first->data,middle->data);
    }
}