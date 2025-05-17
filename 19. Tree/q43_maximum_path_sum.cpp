#include<iostream>
#include<limits.h>
using namespace std;

//Leetcode 124
//Maximum path sum in binary tree

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

int helper(Node* root,int& maxSum){
    if(!root){
        return 0;
    }

    int leftMax = max(0,helper(root->left,maxSum));
    int rightMax = max(0,helper(root->right,maxSum));
    maxSum = max(maxSum, root->data + leftMax + rightMax);
    return root->data + max(leftMax,rightMax);
}
int maxPathSum(Node* root) {
    int maxSum = INT_MIN;
    helper(root,maxSum);
    return maxSum;
}

int main(){ 
    return 0;
}