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

void storeInOrder(vector<int>& inorder,Node* root){
    if(root == NULL){
        return;
    }

    storeInOrder(inorder,root->left);
    inorder.push_back(root->data);
    storeInOrder(inorder,root->right);
}

bool findTarget(Node* root, int k) {

    vector<int> inorder;
    storeInOrder(inorder,root);

    int start = 0;
    int end = inorder.size() - 1;

    while(start < end){
        int sum = inorder[start] + inorder[end];

        if(sum == k){
            return true;
        }

        if(sum > k){
            end--;
        }
        else{
            start++;
        }
    }
    return false;
}

int main(){
    

    return 0;
}