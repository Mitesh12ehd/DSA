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

vector<int> merge(Node *root1, Node *root2){
    vector<int> ans;
    stack<Node*> sa,sb;
    Node* a = root1;
    Node* b = root2;

    while(a != NULL || b!= NULL || !sa.empty() || !sb.empty()){
        while(a != NULL){
            sa.push(a);
            a = a->left;
        }

        while(b != NULL){
            sb.push(b);
            b = b->left;
        }

        if(sb.empty() || (!sa.empty() && sa.top()->data <= sb.top()->data)){
            Node* atop = sa.top();
            ans.push_back(atop->data);
            sa.pop();
            a = atop->right;
        }
        else{
            Node* btop = sb.top();
            ans.push_back(btop->data);
            sb.pop();
            b = btop->right;
        }
    }
    return ans;
}

int main(){
    return 0;
}