#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;

//Leetcode 1108
//Construct binary search tree from preorder travesal

//brute forces
//we call insert into bst function for each element in array

//better approach
//generate inorder by sorting preorder travesal
//now generate tree from inorder and preorder using concept 
//that we have seen in binary tree

//optimal approach

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

Node* build(int& i,int min,int max,vector<int>& preorder){
    if(i >= preorder.size()){
        return NULL;
    }

    Node* root = NULL;
    if(preorder[i] > min && preorder[i] < max){
        root = new Node(preorder[i]);
        i++;
        root->left = build(i,min,root->data,preorder);
        root->right = build(i,root->data,max,preorder);
    }
    return root;
}

Node* bstFromPreorder(vector<int>& preorder) {
    int min = INT_MIN;
    int max = INT_MAX;
    int i=0;
    Node* ans = build(i,min,max,preorder);
    return ans;
}

int main(){
    return 0;
}   