#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//see notes both approach are at different place

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

void storeInOrder(vector<int>& inorder,Node* root){
    if(root == NULL){
        return;
    }

    storeInOrder(inorder,root->left);
    inorder.push_back(root->data);
    storeInOrder(inorder,root->right);
}

bool findTarget(Node* root, int k) {

    vector<int> inorder;
    storeInOrder(inorder,root);

    int start = 0;
    int end = inorder.size() - 1;

    while(start < end){
        int sum = inorder[start] + inorder[end];

        if(sum == k){
            return true;
        }

        if(sum > k){
            end--;
        }
        else{
            start++;
        }
    }
    return false;
}

//most optimized appraoch
class BSTIterator {
    public:
        stack<Node*> st1;
        stack<Node*> st2;
        BSTIterator(Node* root) {
            //store extreme left into st1
            Node* curr = root;
            while(curr){
                st1.push(curr);
                curr = curr->left;
            }

            //store extreme right into st2
            Node* curr = root;
            while(curr){
                st2.push(curr);
                curr = curr->right;
            }
        }
        
        int next() {
            Node* top = st1.top();
            st1.pop();
            Node* curr = top->right;
            while(curr){
                st1.push(curr);
                curr = curr->left;
            }
            return top->data;
        }

        int before(){
            Node* top = st2.top();
            st2.pop();
            Node* curr = top->left;
            while(curr){
                st2.push(curr);
                curr = curr->right;
            }
            return top->data;
        }
        
        bool hasNext() {
            return !st1.empty();
        }

        bool hasBefore(){
            return !st2.empty();
        }
    };

bool findTarget(Node* root, int k) {
    if(!root){
        return false;
    }

    BSTIterator  it(root);
    int left = it.next();
    int right = it.before();
    while(left < right){
        if(left + right == k){
            return true;
        }
        else if(left + right < k){
            left = it.next();
        }
        else{
            right = it.before();
        }
    }
    return false;
}

int main(){
    

    return 0;
}