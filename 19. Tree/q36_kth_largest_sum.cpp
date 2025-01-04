#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

//leetcode 2583
//kth largest sum in binary tree

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

void helper(Node* root,int level,unordered_map<int,long long>& mp){
    if(root == NULL){
        return;
    }

    long long sum;
    if(mp.find(level) != mp.end()){
        sum = mp[level];
    }
    else{
        sum = 0;
    }
    mp[level] = sum + root->data;
    helper(root->left,level+1,mp);
    helper(root->right,level+1,mp);
}
long long kthLargestLevelSum(Node* root, int k) {
    unordered_map<int,long long> mp; //level,sum
    helper(root,1,mp);
    
    vector<long long> v;
    for(auto it:mp){
        v.push_back(it.second);
    }

    sort(v.begin(),v.end());

    if(k > v.size()){
        return -1;
    }

    return v[v.size()-k];
}

int main(){
    

    return 0;
}