#include<iostream>
#include<queue>
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

Node* insertIntoBST(Node* root,int data){
    if(root == NULL){
        //first node
        root = new Node(data);
        return root;
    }

    if(root->data  >  data){
        //insert in left
        root->left = insertIntoBST(root->left,data);
    }
    else{
        root->right = insertIntoBST(root->right,data);
    }
    return root;
}

void takeInput(Node*& root){
    int data;
    cin >> data;
    while(data != -1){
        root = insertIntoBST(root,data);
        cin >> data;
    }
}

bool find_Node(Node* root,int target){
    if(root == NULL){
        return false;
    }

    if(root->data == target){
        return true;
    }
    if(target > root->data){
        return find_Node(root->right,target);
    }
    else{
        return find_Node(root->left,target);
    }
}

int main(){
    Node* root = NULL;
    cout << "Enter the data for node : " << endl;
    takeInput(root);

    cout << "Enter node you want to find" << endl;
    cout << find_Node(root,190);
    return 0;
}