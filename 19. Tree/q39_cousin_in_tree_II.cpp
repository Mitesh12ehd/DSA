#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//leetcode 2641
//cousins in binary tree II

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

void helper1(Node* root,int level,vector<int>& mp){
    if(root == NULL){
        return;
    }

    int sum = mp[level];
    mp[level] = sum + root->data;
    helper1(root->left,level+1,mp);
    helper1(root->right,level+1,mp);
}
void helper2(Node* root,int level,vector<int>& mp,int sib){
    if(!root){
        return;
    }

    //store the leftsibling and rightsibling because dfs will change it
    int leftsibling = 0;
    int rightsibling = 0;
    if(root->left){
        leftsibling = root->left->data;
    }
    if(root->right){
        rightsibling  = root->right->data;
    }

    int ans = mp[level] - root->data - sib;
    root->data = ans;

    helper2(root->left,level+1,mp,rightsibling);
    helper2(root->right,level+1,mp,leftsibling);
}
Node* replaceValueInTree(Node* root) {
    vector<int> mp(100001,0);
    helper1(root,0,mp);
    helper2(root,0,mp,0);
    return root;
}

int main(){
    return 0;
}