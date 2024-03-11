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

pair<int,int> solve(Node* root){
    if(root == NULL){
        pair<int,int> p = {0,0};
        return p;
    }

    pair<int,int> leftAns = solve(root->left);
    pair<int,int> rightAns = solve(root->right);

    pair<int,int> ans;
    ans.first = root->data + leftAns.second + rightAns.second;
    ans.second = max(leftAns.first,leftAns.second) + max(rightAns.first,rightAns.second);
    return ans;
}
int getMaxSum(Node *root) {
    pair<int,int> ans = solve(root);
    return max(ans.first,ans.second);
}

int main(){
    return 0;
}