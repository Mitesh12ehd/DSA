#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//Leetcode 173
//Binary search tree iterator

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

//brute force approach
void inorder(vector<int>& v,Node* root){
    if(!root){
        return;
    }
    inorder(v,root->left);
    v.push_back(root->data);
    inorder(v,root->right);
}

class BSTIterator {
    public:
        vector<int> v;
        int i = 0;
        BSTIterator(Node* root) {
            inorder(v,root);
        }
        
        int next() {
            int ele = v[i];
            i++;
            return ele;
        }
        
        bool hasNext() {
            if(i < v.size()){
                return true;
            }
        }
    };

//optimal solution
class BSTIterator {
    public:
        stack<Node*> st;
        BSTIterator(Node* root) {
            //store extreme left
            Node* curr = root;
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
        }
        
        int next() {
            Node* top = st.top();
            st.pop();
            Node* curr = top->right;
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            return top->data;
        }
        
        bool hasNext() {
            return !st.empty();
        }
    };