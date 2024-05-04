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

Node* findPredecessor(Node* root, Node* p) {
    Node* pred = NULL;
    Node* curr = root;
    while(curr != NULL){
        if(curr->data < p->data){
            pred = curr;
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    return pred;
}

int main(){
    return 0;
}