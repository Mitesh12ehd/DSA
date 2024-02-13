#include<iostream>
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

pair<bool,int> isSumTreeHelper(Node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    //check for leaf node
    if((root->left == NULL) && (root->right == NULL)){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> left = isSumTreeHelper(root->left);
    pair<bool,int> right = isSumTreeHelper(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool condition = (root->data  == (left.second + right.second));

    pair<bool,int> ans;
    ans.first = (leftAns && rightAns && condition);
    ans.second = root->data + left.second + right.second;
    return ans;
}

bool isSumTree(Node* root){
    pair<bool,int> ans = isSumTreeHelper(root);
    return ans.first;
}

int main(){
    return 0;
}