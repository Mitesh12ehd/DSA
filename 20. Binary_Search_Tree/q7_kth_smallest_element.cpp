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

int main(){
    

    return 0;
}