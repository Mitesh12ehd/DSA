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

int main(){
    return 0;
}