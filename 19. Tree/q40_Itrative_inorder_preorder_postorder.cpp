#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

//see notes
//find inorder, preorder, and postorder travesal without recursion

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

// pre order
vector<int> preorderTraversal(Node* root) {
    stack<Node*> st;
    st.push(root);
    vector<int> ans;

    while(!st.empty()){
        Node* top = st.top();
        st.pop();

        if(top != NULL){
            ans.push_back(top->data);

            st.push(top->right);
            st.push(top->left);
        }
    }
    return ans;
}

// in order
vector<int> inorderTraversal(Node* root) {
    stack<Node*> st;
    Node* node = root;
    vector<int> ans;

    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()){
                break;
            }
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            node = node->right;
        }
    }
    return ans;
}

// Post order 
vector<int> postorderTraversal(Node* root) {
    if(!root){
        return {};
    }

    stack<Node*> st;
    vector<int> ans;
    st.push(root);

    while(!st.empty()){
        Node* top = st.top();
        ans.push_back(top->data);
        st.pop();

        if(top->left){
            st.push(top->left);
        }
        if(top->right){
            st.push(top->right);
        }
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    return 0;
}