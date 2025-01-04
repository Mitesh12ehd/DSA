#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//leetcode 2458
//height of binary tree after subtree removal

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

//method 1 O(n * m)
// int helper(Node* root,int target){
//     if(root == NULL || root->data == target){
//         return 0;
//     }

//     int leftHeight = helper(root->left,target);
//     int rightHeight = helper(root->right,target);
//     return max(leftHeight,rightHeight) + 1;
// }
// vector<int> treeQueries(Node* root, vector<int>& queries) {
//     vector<int> ans;
//     for(int i=0; i<queries.size(); i++){
//         ans.push_back(helper(root,queries[i])-1);
//     }
//     return ans;
// }

//method 2
int arr1[100001];
int arr2[100001];
int maxHeight = 0;
void preOrder(Node* root, int height) {
    if (root == NULL) {
            return;
    }

    arr1[root->data] = maxHeight;
    maxHeight = max(maxHeight, height);
    preOrder(root->left, height + 1);
    preOrder(root->right, height + 1);
}

void postOrder(Node* root, int height) {
    if (root == NULL) {
        return;
    }

    arr2[root->data] = maxHeight;
    maxHeight = max(maxHeight, height);
    postOrder(root->right, height + 1);
    postOrder(root->left, height + 1);
}
vector<int> treeQueries(Node* root, vector<int>& queries) {
    preOrder(root, 0);
    maxHeight = 0;
    postOrder(root, 0);

    vector<int> ans(queries.size());
    for (int i = 0; i < queries.size(); i++) {
        ans[i] = max(arr1[queries[i]], arr2[queries[i]]);
    }
    return ans;
}

int main(){
    

    return 0;
}