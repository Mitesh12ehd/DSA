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

//method 1
// bool isBalanced(Node* root){
//     if(root == NULL){
//         return true;
//     }

//     bool leftAns = isBalanced(root->left);
//     bool rightAns = isBalanced(root->right);
//     bool diff = abs(height(root->left) - height(root->right)) <= 1;
    
//     return leftAns && rightAns && diff;
// }

//method 2
pair<bool,int> isBalancedHelper(Node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> leftAns = isBalancedHelper(root->left);
    pair<bool,int> rightAns = isBalancedHelper(root->right);
    bool diff = abs(leftAns.second - rightAns.second) <= 1;

    pair<bool,int> ans;
    ans.first = leftAns.first && rightAns.first && diff;
    ans.second = max(leftAns.second,rightAns.second) + 1;
    
    return ans;
}
bool isBalanced(Node* root) {
    pair<bool,int> ans = isBalancedHelper(root);
    return ans.first;
}

int main(){
    return 0;
}