#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
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

Node* build(int& i,int min,int max,vector<int>& preorder){
    if(i >= preorder.size()){
        return NULL;
    }

    Node* root = NULL;
    if(preorder[i] > min && preorder[i] < max){
        root = new Node(preorder[i]);
        i++;
        root->left = build(i,min,root->data,preorder);
        root->right = build(i,root->data,max,preorder);
    }
    return root;
}

Node* bstFromPreorder(vector<int>& preorder) {
    int min = INT_MIN;
    int max = INT_MAX;
    int i=0;
    Node* ans = build(i,min,max,preorder);
    return ans;
}

int main(){
    return 0;
}   