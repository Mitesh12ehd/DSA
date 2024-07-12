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
int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    int ans = max(leftHeight,rightHeight) + 1;
    return ans;
}

// //method 1
int diameterOfBinaryTree(Node* root) {
    if(root == NULL){
        return 0;
    }

    int op1 = diameterOfBinaryTree(root->left);
    int op2 = diameterOfBinaryTree(root->right);
    int op3 = height(root->left) + 1 + height(root->right);

    return max(op1,max(op2,op3));
}

//method 2
pair<int,int> diameterHelper(Node* root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameterHelper(root->left);
    pair<int,int> right = diameterHelper(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second;

    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second) + 1;

    return ans;
}
int diameterOfBinaryTree(Node* root) {
    pair<int,int> ans = diameterHelper(root);
    return ans.first; 
}

int main(){
    return 0;
}