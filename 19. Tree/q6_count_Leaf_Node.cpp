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

Node* buildTree(Node* root){
    int data;
    cout << "enter the data = ";
    cin >> data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout << "enter data for left of : " << data <<endl;
    root->left = buildTree(root->left); 
    cout << "enter data for right of : " << data <<endl;
    root->right = buildTree(root->right); 
    return root;
}

void inorder(Node*& root,int& count){
    if(root == NULL){
        return;
    }

    inorder(root->left,count);

    //leaf node
    if(root->left == NULL && root->right == NULL){
        count++;
    }

    inorder(root->right,count);
}

int noOfLeafNodes(Node *root){
    int count = 0;
    inorder(root,count);
    return count;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout <<endl;
    cout << "total leaf node = " <<noOfLeafNodes(root);
    return 0;
}