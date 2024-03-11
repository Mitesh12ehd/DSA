#include<iostream>
#include<limits.h>
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

void solve(Node* root,int len,int& maxlen,int sum,int& maxSum){
    //base case
    if(root == NULL){
        if(len > maxlen){
            maxlen = len;
            maxSum = sum;
        }
        else if(len == maxlen){
            maxSum = max(sum,maxSum);
        }
        return;
    }

    sum = sum + root->data;

    solve(root->left,len+1,maxlen,sum,maxSum);
    solve(root->right,len+1,maxlen,sum,maxSum);
}

int sumOfLongRootToLeafPath(Node *root){
    int len = 0;
    int maxlen = 0;
    int sum = 0;
    int maxSum = INT_MIN;
    
    solve(root,len,maxlen,sum,maxSum);
    return maxSum;
}

int main(){
    return 0;
}