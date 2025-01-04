#include<iostream>
#include<vector>
#include<algorithm>
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

//pair<int,int>  <size,height>

static bool myComp(int a,int b){
    return a>b;
}
pair<int,int> helper(Node* root,vector<int>& arr){
    if(root == NULL){
        pair<int,int> p = {0,0};
        return p;
    }

    pair<int,int> leftAns = helper(root->left,arr);
    pair<int,int> rightAns = helper(root->right,arr);
    if(leftAns.first == -1 || rightAns.first == -1){
        pair<int,int> p = {-1,0};
        return p;
    }

    pair<int,int> p;
    //check if height balanced
    if(leftAns.second ==  rightAns.second){
        p.first = leftAns.first + rightAns.first + 1;
        arr.push_back(p.first);
    }
    else{
        p.first = -1;
    }
    p.second = max(leftAns.second,rightAns.second) + 1;
    return p;
}

int kthLargestPerfectSubtree(Node* root, int k) {
    vector<int> arr;
    pair<int,int> p =  helper(root,arr);
    sort(arr.begin(),arr.end(),myComp);
    if(arr.size() >= k){
        return arr[k-1];
    }
    return -1;
}

int main(){
    return 0;
}