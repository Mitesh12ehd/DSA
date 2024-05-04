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

int rangeSumBST(Node* root, int low, int high) {
    if(root == NULL){
        return 0;
    }

    int ans = 0;
    bool wasInRange = false;
    if(root->data >= low && root->data >= high){
        wasInRange = true;
        ans = ans + root->data;
    }

    if(wasInRange){
        ans = ans + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
    }
    else if(root->data < low){
        ans = ans + rangeSumBST(root->right,low,high);
    }
    else if(root->data > high){
        ans = ans + rangeSumBST(root->left,low,high);
    }
    return ans;
}

int main(){
    return 0;
}