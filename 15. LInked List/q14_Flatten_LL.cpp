#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* bottom;

    Node(){
        this->data = 0;
        this->next = NULL;
        this->bottom = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
    }
    ~Node(){
        int value = this->data;
        cout << "Node with value = "<< value << " is deleted" <<endl;
    }
};
Node* mergeTwoLists(Node* left, Node* right) {
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
    Node* ansHead = new Node(-1);
    Node* temp = ansHead;

    while(left != NULL && right != NULL){
        if(left->data <= right->data){
            temp->bottom = left;
            temp = left;
            left = left->bottom;
        }
        else{
            temp->bottom = right;
            temp = right;
            right = right->bottom;
        }
    }

    if(left != NULL){
        temp->bottom = left;
    }
    if(right != NULL){
        temp->bottom = right;
    }

    //free the -1 node
    Node* varNode = ansHead;
    ansHead = ansHead->bottom;
    varNode->bottom = NULL;
    delete varNode;

    return ansHead;
}
Node *flatten(Node *root){
    if(root == NULL){
        return NULL;
    }
    Node* ptr = flatten(root->next);
    Node* mergedLL = mergeTwoLists(root,ptr);
    return mergedLL;
}
int main(){
    //see book and geeks for geeks
    return 0;
}