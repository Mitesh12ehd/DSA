#include<iostream>
#include<vector>
using namespace std;

//see notes 
//dryrun to understand

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

//how time complexity is O(1)
//innner loop establish link by going to right as much as possible
//so overall it runs for O(n) time during whole algorithm

//time = O(2n)
//space = O(1)

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
                //predecessir->right is not null means that we have established link already
                //it means right node is visited already

                //left is visited, go right after visiting curr node and remove link
                precedesor->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}

//in preorder travesal 
//root , left, right
//so here only one change whenever curr = root. before establising pointer
//we can visit first and then establish
//dryrun on same example to understand

vector<int> postOrderTraversal(Node* root) {
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

            if(precedesor->right == NULL){
                precedesor->right = curr;
                ans.push_back(curr->data);
                curr = curr->left;
            }
            else{
                precedesor->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
}
 
int main(){
    return 0;
}