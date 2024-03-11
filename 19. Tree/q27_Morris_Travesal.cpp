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

vector<int> inorderTraversal(Node* root) {
    vector<int> ans;
    Node* curr = root;

    while(curr != NULL){
        //if left is null then visit it and go right
        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }
        //if left node is not null
        else{
            //find inorder precedessor
            Node* precedesor = curr->left;
            while(precedesor->right != NULL && precedesor->right != curr){
                precedesor = precedesor->right;
            }

            //if pred->right is null then go left of current after establishing link 
            //from precedessor to currnt
            if(precedesor->right == NULL){
                precedesor->right = curr;
                curr = curr->left;
            }
            else{
                //predecessir->right is not null means that we have establish link
                //it means right node is visited

                //left is visited, go right after visiting curr node and remove link
                precedesor->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}
 
int main(){
    return 0;
}