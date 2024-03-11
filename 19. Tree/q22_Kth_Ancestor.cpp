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

//METHOD 1
// int ans = -1;
// void solve(Node* root,int k,int node,vector<int>& path){
//     if(root == NULL){
//         return;
//     }

//     path.push_back(root->data);
//     if(root->data == node){
//         if((path.size()-k-1) >=0 && (path.size()-k-1) <=path.size()-1){
//             //condiotion for checking weather array is out of bound or not
//             ans = path[path.size() - k -1];
//         }
//         else{
//             ans = -1;
//         }
//         return;
//     }

//     solve(root->left,k,node,path);
//     solve(root->right,k,node,path);
//     path.pop_back();
// }
// int kthAncestor(Node *root, int k, int node){
//     vector<int> path;
//     solve(root,k,node,path);
//     return ans;
// }

//METHOD 2
Node* solve(Node *root, int& k, int node){
    if(root == NULL){
        return NULL;
    }

    if(root->data == node){
        return root;
    }

    Node* leftAns = solve(root->left,k,node);
    Node* rightAns = solve(root->right,k,node);

    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k==0){
            k = -1;
            return root;
        }
        return leftAns;
    }
    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k==0){
            k = -1;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node){
    Node* ans = solve(root,k,node);
    if(ans == NULL || ans->data == node){
        return -1;
    }
    return ans->data;
}

int main(){
    return 0;
}