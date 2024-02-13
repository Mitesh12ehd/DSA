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

void solve(Node* root,vector<int>& ans,int row){
    if(root == NULL){
        return;
    }

    //we entered into new row
    if(row == ans.size()){
        ans.push_back(root->data);
    }

    solve(root->left,ans,row+1);
    solve(root->right,ans,row+1);
}

vector<int> leftView(Node *root){
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}

int main(){
    return 0;
}