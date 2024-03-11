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
bool isMirror(Node* p, Node* q) {
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

    bool leftAns = isMirror(p->left,q->right);
    bool rightAns = isMirror(p->right,q->left);
    bool current = (p->data == q->data);
    return leftAns && rightAns && current;
}
bool isSymmetric(Node* root) {
    return isMirror(root->left,root->right);
}
int main(){
    return 0;
}