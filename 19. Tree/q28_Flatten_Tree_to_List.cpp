#include<iostream>
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

//method 1
// void preOrder(Node* root , vector<Node*>& arr){
//     if(root == NULL){
//         return;
//     }
//     arr.push_back(root);

//     preOrder(root->left,arr);
//     preOrder(root->right,arr);
// }
// void flatten(Node* root) {
//     vector<Node*> arr;
//     preOrder(root,arr);
//     arr.push_back(NULL);

//     //we have mapping
//     for(int i=0; i<arr.size()-1; i++){
//         Node* node = arr[i];
//         node->right = arr[i+1];
//         node->left = NULL;
//     }
// }

//method 2 using recursive approach
//1. convert left subtree using recurion
//2. store root->right pointer in temp
//3. root->right = leftSubtreeAns
//4. go to right in depth and attach temp node that we have stored
Node* helper(Node* root){
    if(!root){
        return NULL;
    }

    Node* rightPart = root->right;
    root->right = helper(root->left);

    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
        
    temp->right = helper(rightPart);
    root->left = NULL;
    return root;
}
void flatten(Node* root) {
    root = helper(root);
}


void flatten(Node* root) {
    Node* curr = root;

    while(curr != NULL){
        if(curr->left != NULL){
            //find precedessor
            Node* pred = curr->left;
            while(pred->right != NULL){
                pred = pred->right;
            }

            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}


int main(){
    return 0;
}