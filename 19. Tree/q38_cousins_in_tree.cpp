#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//leetcode 993
//cousins in binary tree

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

int xLevel = 0;
int yLevel = 0;
Node* xParent = NULL;
Node* yParent = NULL;
void helper(Node* root, int x, int y,int level){
    if(!root){
        return;
    }

    if(root->left){
        if(root->left->data == x){
            xParent = root;
            xLevel = level+1;
        }
        if(root->left->data == y){
            yParent = root;
            yLevel = level+1;
        }
    }
    if(root->right){
        if(root->right->data == x){
            xParent = root;
            xLevel = level+1;
        }
        if(root->right->data == y){
            yParent = root;
            yLevel = level+1;
        }
    }

    helper(root->left,x,y,level+1);
    helper(root->right,x,y,level+1);
}
    
bool isCousins(Node* root, int x, int y) {
    helper(root,x,y,1);
    return xLevel==yLevel && xParent!=yParent;
}

int main(){
    return 0;
}