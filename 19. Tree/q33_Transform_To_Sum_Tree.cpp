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

int sum(Node* root){
    if(root == NULL){
        return 0;
    }
    if(!root->left && !root->right){
        int temp = root->data;
        root->data = 0;
        return temp;
    }

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    int temp = root->data;
    root->data = leftSum + rightSum;
    return (root->data + temp);
}

void toSumTree(Node *node){
    sum(node);
}

int main(){
    return 0;
}