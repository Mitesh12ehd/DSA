#include<iostream>
#include<queue>
#include<vector>
#include<stack>
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

vector<int> inorderTravesal(Node* root){
    stack<Node*> st;
    vector<int> ans;

    Node* node = root;
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

vector<int> inorderTravesal(Node* root){
    stack<Node*> st;
    vector<int> ans;

    Node* node = root;
    while(true){
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }

        if (st.empty()) {
            break;
        }

        node = st.top();
        st.pop();
        ans.push_back(node->data);
        node = node->right;
    }
    return ans;
}

int main(){
    return 0;
}