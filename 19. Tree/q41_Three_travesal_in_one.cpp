#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//Find inorder,preorder, postorder in single flow
//this is non intutive algorithm

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

//time = O(n)
//space = O(n)
vector<vector<int> > treeTraversal(Node* root){
    if(!root){
        return {{}};
    }

    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;

    stack<pair<Node*,int>> st;
    st.push({root,1});
    while(!st.empty()){
        Node* node = st.top().first;
        int num = st.top().second;
        st.pop();

        if(num == 1){
            preorder.push_back(node->data);
            st.push({node,2});
            if(node->left){
                st.push({node->left,1});
            }
        }
        else if(num == 2){
            inorder.push_back(node->data);
            st.push({node,3});
            if(node->right){
                st.push({node->right,1});
            }
        }
        else{
            postorder.push_back(node->data);
        }
    }
    return {inorder,preorder,postorder};
}

int main(){
    return 0;
}