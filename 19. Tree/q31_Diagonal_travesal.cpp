#include<iostream>
#include<queue>
#include<vector>
#include<map>
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

//method 2
// vector<int> diagonal(Node *root){
//     vector<int> ans;
//     if(root == NULL){
//         return ans;
//     }

//     queue<Node*> q;
//     q.push(root);

//     while(!q.empty()){
//         Node* temp = q.front();
//         q.pop();

//         while(temp != NULL){
//             ans.push_back(temp->data);
//             if(temp->left != NULL){
//                 q.push(temp->left);
//             }
//             temp = temp->right;
//         }
//     }
    
//     return ans;
// }


//method 2
void solve(Node* root,int d,map<int,vector<int>>& mp){
    if(root == NULL){
        return;
    }

    mp[d].push_back(root->data);

    solve(root->left,d+1,mp);
    solve(root->right,d,mp);
}
vector<int> diagonal(Node *root){
    int d = 0;
    map<int,vector<int>> mp;
    solve(root,d,mp);

    vector<int> ans;
    for(auto it:mp){
        for(auto v:it.second){
            ans.push_back(v);
        }
    }
    return ans;
}

int main(){
    return 0;
}