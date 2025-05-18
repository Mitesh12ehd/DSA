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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(root == NULL){
        return NULL;
    }

    //case 1
    if(p->data < root->data  &&  q->data < root->data){
        return lowestCommonAncestor(root->left,p,q);
    }
    //case 2
    if(p->data > root->data  &&  q->data > root->data){
        return lowestCommonAncestor(root->right,p,q);
    }
    //case 3 and 4
    return root;
}

int main(){
    return 0;
}