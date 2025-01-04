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

    //check for p and q
    if(root->data == p->data){
        return p;
    }
    if(root->data == q->data){
        return q;
    }

    Node* leftAns = lowestCommonAncestor(root->left,p,q);
    Node* rightAns = lowestCommonAncestor(root->right,p,q);

    if(leftAns == NULL && rightAns == NULL){
        return NULL;
    }
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else{
        // (leftAns != NULL && rightAns != NULL)
        //LCA found
        return root;
    }
}

int main(){
    return 0;
}