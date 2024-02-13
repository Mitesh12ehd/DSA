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

void Travese_Left(Node* root,vector<int>& ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        //leaf node
        return;
    }

    ans.push_back(root->data);
    if(root->left != NULL){
        Travese_Left(root->left,ans);
    }
    else{
        Travese_Left(root->right,ans);
    }
}

void Travese_Leaf(Node* root,vector<int>& ans){
    //base case
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }

    Travese_Leaf(root->left,ans);
    Travese_Leaf(root->right,ans);
}

void Travese_Right(Node* root,vector<int>& ans){
    //base case
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }

    if(root->right != NULL){
        Travese_Right(root->right,ans);
    }
    else{
        Travese_Right(root->left,ans);
    }
    //store ans
    ans.push_back(root->data);
}

vector <int> boundary(Node *root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    ans.push_back(root->data);

    //left part
    Travese_Left(root->left,ans);

    //leaf node
    Travese_Leaf(root->left,ans);
    Travese_Leaf(root->right,ans);

    //right part
    Travese_Right(root->right,ans);
}

int main(){
    return 0;
}