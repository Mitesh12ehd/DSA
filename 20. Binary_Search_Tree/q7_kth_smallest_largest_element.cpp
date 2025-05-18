#include<iostream>
using namespace std;

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

//Find kth smallest element in BST
//leetcode

//brute force = store inorder travesal , return arr[k-1]

//optimized approach
//can we do inorder travesal
//and maintain a count variable
//whenever we visit node , do count++;
//when count == k
//it will be answer

//here in this approach
//we decreamenting k whenever we visit node
//it is same as increamenting counts

// note: we can do any inorder travelsal: recursive,iterative,morris
// whenver we visit node just decreament count

int kthSmallest(Node* root, int k) {
    if(root == NULL){
        //reflect base condition reached
        return -1;
    }

    //inorder

    //left
    int leftAns = kthSmallest(root->left,k);
    if(leftAns != -1){
        return leftAns;
    }

    //node
    k--;
    if(k == 0){
        return root->data;
    }

    //right ans
    int rightAns = kthSmallest(root->right,k);
    return rightAns;
}

//Find kth largest element in BST
//do a reverse inorder travesal

//1. first find number of nodes in tree = n
//2. kth largest = [n-k]th smallest