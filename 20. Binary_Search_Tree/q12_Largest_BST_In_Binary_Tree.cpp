#include<iostream>
#include<limits.h>
#include<queue>
using namespace std;

//GFG
//Largest BST

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

// brute force will be check for each subtree is bst or not
// time = O(n^2)

// optimal approachs
class Nodedata{
    public:
    int size;
    int minVal;
    int maxVal;
    bool validBST;

    Nodedata(){
        
    }

    Nodedata(int size,int minVal,int maxVal,bool validBST){
        this->size = size;
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->validBST = validBST;

    }
};

Nodedata largestBst(Node *root,int& ans){
    //base case
    if(root == NULL){
        Nodedata temp(0,INT_MAX,INT_MIN,true);
        return temp;
    }

    Nodedata leftKaAns = largestBst(root->left,ans);
    Nodedata rightKaAns = largestBst(root->right,ans);

    Nodedata current;
    current.size = leftKaAns.size + rightKaAns.size + 1;
    current.minVal = min(root->data,leftKaAns.minVal);
    current.maxVal = max(root->data,rightKaAns.maxVal);

    if(leftKaAns.validBST &&
        rightKaAns.validBST &&
        (root->data > leftKaAns.maxVal) &&
        (root->data < rightKaAns.minVal) )
    {
        current.validBST = true;
    }
    else{
        current.validBST = false;
    }

    if(current.validBST){
        ans = max(ans,current.size);
    }
    return current;
}



int main(){
    return 0;
}