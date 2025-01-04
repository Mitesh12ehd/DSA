#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
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

void fun(Node* root,unordered_map<int,bool>& visited,bool& ans){
    if(root == NULL){
        return;
    }

    //visit the node
    visited[root->data] = true;
    if(root->left == NULL && root->right == NULL){
        //leaf node
        int xp1 = root->data + 1;
        int xm1 = root->data - 1 == 0 ? root->data : root->data - 1;
        if(visited.find(xp1) != visited.end()  &&  visited.find(xm1) != visited.end()){
            ans = true;
            return;
        }
    }

    fun(root->left,visited,ans);
    fun(root->right,visited,ans);
}

bool isDeadEnd(Node *root){
    bool ans = false;
    unordered_map<int,bool> visited;
    fun(root,visited,ans);
    return ans;
}

//range based hand made approach
// bool helper(Node* root,int mini,int maxi){
//     if(!root->left && !root->right){
//         bool isLeftNotPossible = (root->data + 1 == maxi);
//         bool isRightNotPossible = mini + 1 == root->data;
//         return isLeftNotPossible && isRightNotPossible;
//     }
//     if(!root->left){
//         return helper(root->right,root->data,maxi);
//     }
//     if(!root->right){
//         return helper(root->left,mini,root->data);
//     }

//     //left and right both exist
//     bool leftAns = helper(root->left,mini,root->data);
//     bool rightAns = helper(root->right,root->data,maxi);
//     return leftAns || rightAns;
// }
// bool isDeadEnd(Node *root){
//     int mini = 0;
//     int maxi = 10002;
//     return helper(root,mini,maxi);
// }

int main(){
    return 0;
}