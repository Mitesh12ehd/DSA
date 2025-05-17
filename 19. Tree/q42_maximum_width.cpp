#include<iostream>
#include<queue>
using namespace std;

//Leetcode 662
//Maximum width of binary tree

//see notes

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

int widthOfBinaryTree(Node* root) {
    if(!root){
        return 0;
    }

    long long maxWidth = 0;
    queue<pair<Node*,long long>> q;
    q.push({root,0});

    while(!q.empty()){
        //get size of current level
        int size = q.size();

        //element to substract
        long long miniToSubstract = q.front().second;

        long long leftEndIndex;
        long long rightEndIndex;
        for(int i=0; i<size; i++){
            Node* front = q.front().first;
            long long index = q.front().second - miniToSubstract;
            q.pop();

            if(i==0){
               leftEndIndex = index; 
            }
            if(i==size-1){
                rightEndIndex = index;
            }
            if(front->left){
                q.push({front->left,(index*2)+1});
            }
            if(front->right){
                q.push({front->right,(index*2)+2});
            }
        }

        maxWidth = max(maxWidth,rightEndIndex-leftEndIndex+1);
    }
    return maxWidth;
}

int main(){
    return 0;
}