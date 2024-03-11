#include<iostream>
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

string preOrder(Node* root,unordered_map<string,int>& mp,vector<Node*>& ans){
    if(root == NULL){
        return "N";
    }

    string curr = to_string(root->data);
    string LeftTree = preOrder(root->left,mp,ans);
    string rightTree = preOrder(root->right,mp,ans);
    curr = curr + "," + LeftTree + "," + rightTree;

    if(mp.find(curr) != mp.end()){
        if(mp[curr] == 1){
            ans.push_back(root);
        }
        mp[curr]++;
    }
    else{
        mp[curr] = 1;
    }
    return curr;
}

vector<Node*> findDuplicateSubtrees(Node* root) {
    vector<Node*> ans;
    unordered_map<string,int> mp;
    preOrder(root,mp,ans);
    return ans;
}


int main(){
    return 0;
}