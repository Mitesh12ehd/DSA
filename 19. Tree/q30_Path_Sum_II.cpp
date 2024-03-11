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

void travese(Node* root,int& targetSum,vector<vector<int>>& ans,vector<int>& path){
    if(root == NULL){
        return;
    }

    path.push_back(root->data);
    targetSum = targetSum - root->data;
    if(targetSum == 0 && !root->left && !root->right){
        ans.push_back(path);
    }

    travese(root->left,targetSum,ans,path);
    travese(root->right,targetSum,ans,path);

    //backtrack
    path.pop_back();
    targetSum = targetSum + root->data;
}

vector<vector<int>> pathSum(Node* root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> path;
    travese(root,targetSum,ans,path);
    return ans;
}

int main(){
    return 0;
}