#include<iostream>
using namespace std;

//gfg
//is binary tree heap

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void countNode(Node* root,int& totalNode){
    if(root == NULL){
        return;
    }
    totalNode++;
    countNode(root->left,totalNode);
    countNode(root->right,totalNode);
} 
bool isCBT(Node* root,int index,int totalNode){
    if(root == NULL){
        return true;
    }
        
    if(index >= totalNode){
        return false;
    }
        
    bool leftAns = isCBT(root->left,2*index+1,totalNode);
    bool rightAns = isCBT(root->right,2*index+2,totalNode);
    return leftAns && rightAns;
}
bool isMaxOrder(Node* root){
    if(!root->left && !root->right){
        return true;
    }
    if(root->left == NULL){
        return (root->data > root->right->data);
    }
    if(root->right == NULL){
        return (root->data > root->left->data);
    }
        
    bool leftAns = isMaxOrder(root->left);
    bool rightAns = isMaxOrder(root->right);
    bool current = (root->data > root->left->data && 
                    root->data > root->right->data);
                    
    return leftAns && rightAns && current;
}
bool isHeap(struct Node* tree) {
    int index = 0;
    int totalNode = 0;
    countNode(tree,totalNode);
        
    if(isCBT(tree,index,totalNode) && isMaxOrder(tree)){
        return true;
    }
    return false;
}

int main(){
    return 0;
}