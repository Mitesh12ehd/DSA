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
void solve(Node* root,int targetSum,vector<int>& path,int& count){
    if(root == NULL){
        return;
    }

    path.push_back(root->data);

    solve(root->left,targetSum,path,count);
    solve(root->right,targetSum,path,count);

    //check for targetSum
    int sum = 0;
    for(int i=path.size()-1; i>=0; i--){
        sum = sum + path[i];
        if(sum == targetSum){
            count++;
        }
    }

    //backtrack
    path.pop_back();
}
int pathSum(Node* root, int targetSum) {
    vector<int> path;
    int count = 0;
    solve(root,targetSum,path,count);
    return count;
}

//METHOD 2 -- Time = O(N^2) Space O(N)
// int ans = 0;
// void path_From_Root(Node* root,long long sum){
//     if(root == NULL){
//         return;
//     }
//     sum = sum - root->data;
//     if(sum == 0){
//         ans++;
//     }
//     path_From_Root(root->left,sum);
//     path_From_Root(root->right,sum);
// }
// int pathSum(Node* root, long long targetSum) {
//     if(root != NULL){
//         path_From_Root(root,targetSum);
//         pathSum(root->left,targetSum);
//         pathSum(root->right,targetSum);
//     }
//     return ans;
// }

int main(){
    return 0;
}