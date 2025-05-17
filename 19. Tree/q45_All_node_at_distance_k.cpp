#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

//All nodes at distance k in binary tree
//Leetcode 863

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

//time = O(n)
//space = O(n)

void makeParent(Node* root,unordered_map<Node*,Node*>& parent){
    //level order travesal
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr->left){
            parent[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right){
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }
}
vector<int> distanceK(Node* root, Node* target, int k) {
    //store link of parents
    unordered_map<Node*,Node*> parent;
    makeParent(root,parent);

    //do a bfs from target node
    unordered_map<Node*,bool> visited;
    visited[target] = true;
    queue<Node*> q;
    q.push(target);
    int curr_level = 0;

    while(!q.empty()){
        int size = q.size();
        if(curr_level == k){
            break;
        }

        for(int i=0; i<size; i++){
            Node* curr = q.front();
            q.pop();

            if(curr->left && !visited[curr->left]){
                q.push(curr->left);
                visited[curr->left] = true;
            }
            if(curr->right && !visited[curr->right]){
                q.push(curr->right);
                visited[curr->right] = true;
            }
            if(parent.find(curr) != parent.end() && !visited[parent[curr]]){
                q.push(parent[curr]);
                visited[parent[curr]] = true;
            }
        }
        curr_level++;
    }

    vector<int> ans;
    while(!q.empty()){
        ans.push_back(q.front()->data);
        q.pop();
    }
    return ans;
}

int main(){
    return 0;
}