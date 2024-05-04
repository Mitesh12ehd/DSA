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

//head is poining to NULL
void convert_into_LL(Node* root,Node*& head){
    if(root == NULL){
        return;
    }

    //right sub tree
    convert_into_LL(root->right,head);

    //attach root node
    root->right = head;
    if(head != NULL){
        head->left = NULL;
    }
    //update head
    head = root;

    //left sub tree
    convert_into_LL(root->left,head);
} 

void print_LL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout <<  temp->data << " ";
        temp = temp->right;
    }
}

int main(){
    Node* root = new Node(5);
    Node* first = new Node(3);
    Node* second = new Node(7);
    Node* third = new Node(2);
    Node* fourth = new Node(4);
    Node* fifth = new Node(6);
    Node* sixth = new Node(8);

    root->left = first;
    root->right = second;
    first->left = third;
    first->right = fourth;
    second->left = fifth;
    second->right = sixth;

    Node* head = NULL;
    convert_into_LL(root,head);
    print_LL(head);
    return 0;
}