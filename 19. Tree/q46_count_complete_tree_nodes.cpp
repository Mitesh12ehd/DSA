#include<iostream>
using namespace std;

//Leetcode 222
//Count complete tree nodes

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

//Solution 1: travese whole tree
//time = O(n) 
//space = O(logn) because tree is complete binary tree

//optimal approach

int findLeftHeight(Node* root){
    int height = 0;
    while(root){
        height++;
        root->left;
    }
    return height;
}
int findRightHeight(Node* root){
    int height = 0;
    while(root){
        height++;
        root->right;
    }
    return height;
}
int countNodes(Node* root) {
    if(!root){
        return 0;
    }

    int leftHeight = findLeftHeight(root);
    int rightHeight = findRightHeight(root);

    if(leftHeight == rightHeight){
        return 1 << leftHeight - 1;  //same as 2^height - 1
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main(){
    return 0;
}