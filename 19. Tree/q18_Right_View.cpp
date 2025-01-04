#include<iostream>
#include<vector>
#include<map>
#include<queue>
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

    solve(root->right,ans,row+1);
    solve(root->left,ans,row+1);
}

vector<int> rightView(Node *root){
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}

//iterative
vector<int> rightView(Node *root){
    map<int,int> mp;//row,value
    queue<pair<Node*,int>> q; //node,row
    q.push({root,0});
        
    while(!q.empty()){
        auto front = q.front();
        q.pop();
            
        Node* temp = front.first;
        int row = front.second;
            
        mp[row] = temp->data;
            
        if(temp->left){
            q.push({temp->left,row+1});
        }
        if(temp->right){
            q.push({temp->right,row+1});
        }
    }
            
    vector<int> ans;
    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){
    return 0;
}