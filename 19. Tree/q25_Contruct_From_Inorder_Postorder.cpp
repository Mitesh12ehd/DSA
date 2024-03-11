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

int find_Position_From_inorder(vector<int>& inorder,int element,int inorderStart){
    for(int i=inorderStart; i<inorder.size(); i++){
        if(inorder[i] == element){
            return i;
        }
    }
    return -1;
}
Node* solve(vector<int>& inorder,vector<int>& postOrder,
            int& index,int inorderStart,int inorderEnd){
    if(index < 0 || inorderStart > inorderEnd){
        return NULL;
    }

    int element = postOrder[index];
    index--;
    Node* root = new Node(element);
    int position = find_Position_From_inorder(inorder,element,inorderStart);
    
    root->right = solve(inorder,postOrder,index,position+1,inorderEnd);
    root->left = solve(inorder,postOrder,index,inorderStart,position-1);
    
    return root;
}
Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int index = inorder.size()-1;
    Node* ans = solve(inorder,postorder,index,0,inorder.size()-1);
    return ans;
}
int main(){
    return 0;
}