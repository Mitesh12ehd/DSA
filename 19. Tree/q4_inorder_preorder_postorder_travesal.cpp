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
    cout << "enter the data = " <<endl;
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

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    inorder(root); cout << endl;
    preOrder(root); cout << endl;
    postOrder(root); cout << endl;
    return 0;
}