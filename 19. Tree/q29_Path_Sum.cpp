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


void travese(Node* root,int& targetSum,bool& flag){
    if(root == NULL){
        return;
    }
    targetSum = targetSum - root->data;
    if(targetSum == 0 && !root->left && !root->right){
        flag = true;
    }
    travese(root->left,targetSum,flag);
    travese(root->right,targetSum,flag);
    
    targetSum = targetSum + root->data;
}
bool hasPathSum(Node* root, int targetSum) {
    bool flag = false;
    travese(root,targetSum,flag);
    return flag;
}

int main(){
    return 0;
}