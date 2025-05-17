#include<iostream>
using namespace std;

//Children sum property
//naukri

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

//brute force 
//time = O(n^2) 
//space = O(height)

//we can increament either left child or right child ,
//it can be our choice but, update whole subtree accordingly
void increament(Node* root,int difference){
    if(root->left){
        root->left->data = root->left->data + difference;
        increament(root->left,difference);
    }
    else if(root->right){
        root->right->data = root->right->data + difference;
        increament(root->right,difference);
    }
}
void changeTree(Node* root) {
    if(!root || (!root->left && !root->right)){
        return;
    }

    changeTree(root->left);
    changeTree(root->right);

    int leftData=0, rightData=0;
    if(root->left){
        leftData = root->left->data;
    }
    if(root->right){
        rightData = root->right->data;
    }

    int difference = leftData + rightData - root->data;
    if(difference > 0){
        root->data = root->data + difference;
    }
    else if(difference < 0){  
        increament(root,abs(difference));
    }
}

//optimized approach
//time = O(n) 
//space = O(height)

void changeTree(Node* root) {
    if(!root){
        return;
    }

    //update the root or left,right
    int leftData=0, rightData=0;
    if(root->left){
        leftData = root->left->data;
    }
    if(root->right){
        rightData = root->right->data;
    }
    
    if(root->data > leftData + rightData){
        if(root->left){
            root->left->data = root->data;
        }
        if(root->right){
            root->right->data = root->data;
        }
    }
    else if(root->data < leftData + rightData){
        root->data = leftData + rightData;
    }
    
    changeTree(root->left);
    changeTree(root->right);

    //update the root or left,right
    leftData=0, rightData=0;
    if(root->left){
        leftData = root->left->data;
    }
    if(root->right){
        rightData = root->right->data;
    }
    
    if(root->data > leftData + rightData){
        if(root->left){
            root->left->data = root->data;
        }
        if(root->right){
            root->right->data = root->data;
        }
    }
    else if(root->data < leftData + rightData){
        root->data = leftData + rightData;
    }
} 

int main(){
    return 0;
}