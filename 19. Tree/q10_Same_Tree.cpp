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
bool isSameTree(Node* p, Node* q) {
    //base case
    if(p == NULL && q == NULL){
        return true;
    }
    if(p == NULL && q != NULL){
        return false;
    }
    if(p != NULL && q == NULL){
        return false;
    }
    //now at this line, both node have value

    bool leftAns = isSameTree(p->left,q->left);
    bool rightAns = isSameTree(p->right,q->right);
    bool current = (p->data == q->data);
    return leftAns && rightAns && current;
}

int main(){
    return 0;
}