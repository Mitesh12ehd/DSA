#include<iostream>
#include<vector>
#include<map>
using namespace std;

//first read concept in book after question 46

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

//Method 1 
int find_Position_From_inorder(int in[],int element,int n,int inorderStart){
    for(int i=inorderStart; i<n; i++){
        if(in[i] == element){
            return i;
        }
    }
    return -1;
}
Node* solve(int in[],int pre[],int& index,int inorderStart,int inorderEnd,int n){
    if(index >= n || inorderStart > inorderEnd){
        return NULL;
    }

    int element = pre[index];
    Node* root = new Node(element);
    index++;
    int position = find_Position_From_inorder(in,element,n,inorderStart); 

    root->left = solve(in,pre,index,inorderStart,position-1,n);
    root->right = solve(in,pre,index,position+1,inorderEnd,n);
    return root; 
}
Node* buildTree(int in[],int pre[], int n){
    int index = 0;
    Node* ans = solve(in,pre,index,0,n-1,n);
    return ans;
}


// //Method 2
// void createMapping(int in[],map<int,int>& NodeToIndex,int n){
//     for(int i=0; i<n; i++){
//         NodeToIndex[in[i]] = i;  
//     }
// }
// Node* solve(int in[],int pre[],int& index,int inorderStart,int inorderEnd,int n,map<int,int>& mp){
//     if(index >= n || inorderStart > inorderEnd){
//         return NULL;
//     }

//     int element = pre[index];
//     Node* root = new Node(element);
//     index++;
//     int position = mp[element]; 

//     root->left = solve(in,pre,index,inorderStart,position-1,n,mp);
//     root->right = solve(in,pre,index,position+1,inorderEnd,n,mp);
//     return root; 
// }
// Node* buildTree(int in[],int pre[], int n){
//     int preOrderIndex = 0;
//     map<int,int> NodeToIndex;
//     createMapping(in,NodeToIndex,n);
//     Node* ans = solve(in,pre,preOrderIndex,0,n-1,n,NodeToIndex);
//     return ans;
// }
int main(){
    return 0;
}