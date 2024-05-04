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

bool solve(Node* root,int lower_bound,int upper_bound){
    if(root == NULL){
        return true;
    }

    if(root->data > lower_bound && root->data < upper_bound){
        bool left_ans = solve(root->left,lower_bound,root->data);
        bool right_ans = solve(root->right,root->data,upper_bound);
        return left_ans && right_ans;
    }
    else{
        return false;
    }
}

bool isValidBST(Node* root) {
    int lower_bound = -4294967296;
    int upper_bound = 4294967296;
    bool ans = solve(root,lower_bound,upper_bound);
    return ans;
}

int main(){
    return 0;
}