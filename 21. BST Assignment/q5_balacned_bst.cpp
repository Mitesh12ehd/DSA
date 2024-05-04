#include<iostream>
#include<queue>
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

Node* build_BST(vector<int>& inorder,int start,int end){
    if(start > end){
        return NULL;
    }

    int mid = (start+end) / 2;
    Node* root = new Node(inorder[mid]);

    root->left = build_BST(inorder,start,mid-1);
    root->right = build_BST(inorder,mid+1,end);
    return root;
}

void store_inorder(Node* root,vector<int>& inorder){
    if(root == NULL){
        return;
    }

    store_inorder(root->left,inorder);
    inorder.push_back(root->data);
    store_inorder(root->right,inorder);
}

Node* balanceBST(Node* root) {
    vector<int> inorder;
    store_inorder(root,inorder);

    int start = 0;
    int end = inorder.size() - 1;
    root = build_BST(inorder,start,end);
    return root;
}

int main(){
    return 0;
}