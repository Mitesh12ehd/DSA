#include<iostream>
#include<vector>
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

void store_inorder(Node* root,vector<int>& inorder){
    if(root == NULL){
        return;
    }

    store_inorder(root->left,inorder);
    inorder.push_back(root->data);
    store_inorder(root->right,inorder);
}

float findMedian(Node *root){
    //we have done -1 beacuse array is 0 indexed
    vector<int> inorder;
    store_inorder(root,inorder);

    int n = inorder.size();
    if(n % 2 != 0){
        //odd
        return inorder[((n+1) / 2) - 1];
    }
    else{
        //even
        float even1 = inorder[(n/2) - 1];
        float even2 = inorder[(n/2) + 1 - 1];
        return (even1 + even2) / 2;
    }
}

int main(){
    return 0;
}