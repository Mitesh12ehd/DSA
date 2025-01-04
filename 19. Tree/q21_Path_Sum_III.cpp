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

//METHOD 1 -- time = O(n^2) -- Space = O(n) for vector
// void solve(Node* root,int targetSum,vector<int>& path,int& count){
//     if(root == NULL){
//         return;
//     }

//     path.push_back(root->data);

//     solve(root->left,targetSum,path,count);
//     solve(root->right,targetSum,path,count);

//     //check for targetSum
//     int sum = 0;
//     for(int i=path.size()-1; i>=0; i--){
//         sum = sum + path[i];
//         if(sum == targetSum){
//             count++;
//         }
//     }

//     //backtrack
//     path.pop_back();  
// }
// int pathSum(Node* root, int targetSum) {
//     vector<int> path;
//     int count = 0;
//     solve(root,targetSum,path,count);
//     return count;
// }

//METHOD 2 -- Time = O(N^2) Space O(N)
void helper1(Node* root,long long target,int& count){
    if(!root){
        return;
    }

    target = target - root->data;
    if(target == 0){
        count++;
    }
    helper1(root->left,target,count);
    helper1(root->right,target,count);
}
void helper2(Node* root,int targetSum,int& count){
    if(!root){
        return;
    }

    helper1(root,targetSum,count);
    helper2(root->left,targetSum,count);
    helper2(root->right,targetSum,count);
}
int pathSum(Node* root, int targetSum) {
    int count = 0;
    helper2(root,targetSum,count);
    return count;
}

int main(){
    return 0;
}