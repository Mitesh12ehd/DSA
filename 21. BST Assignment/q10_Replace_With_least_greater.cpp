#include<iostream>
#include<queue>
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

Node* insertIntoBST(Node* root,int data,int& succ){
    if(root == NULL){
        //first node
        root = new Node(data);
        return root;
    }

    if(root->data  >  data){
        //insert in left
        succ = root->data;
        root->left = insertIntoBST(root->left,data,succ);
    }
    else{
        root->right = insertIntoBST(root->right,data,succ);
    }
    return root;
}

vector<int> findLeastGreater(vector<int>& arr, int n) {
    vector<int> ans(arr.size());

    Node* root = NULL;
    for(int i=arr.size()-1; i>=0; i--){
        int succ = -1;
        root = insertIntoBST(root,arr[i],succ);
        ans[i] = succ;
    }
    return ans;
}

int main(){
    return 0;
}