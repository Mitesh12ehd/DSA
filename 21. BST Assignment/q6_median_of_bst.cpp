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

void store_inorder(Node* root,vector<int>& inorder){
    if(root == NULL){
        return;
    }

    store_inorder(root->left,inorder);
    inorder.push_back(root->data);
    store_inorder(root->right,inorder);
}

float findMedian(Node *root){
    //we have done -1 beacuse array is 0 indexed
    vector<int> inorder;
    store_inorder(root,inorder);

    int n = inorder.size();
    if(n % 2 == 1){
        return inorder[n/2];
    }
    else{
        float n1 = inorder[n/2];
        float n2 = inorder[(n/2) -1];
        float ans = (float)(n1 + n2)/2;
        return ans;
    }
}

int main(){
    return 0;
}