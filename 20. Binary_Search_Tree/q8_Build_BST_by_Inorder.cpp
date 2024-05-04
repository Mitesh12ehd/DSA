#include<iostream>
#include<queue>
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

void levelOrderTravesal(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        cout << temp->data << " ";
        
        q.pop();

        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }

    }
}

Node* build_BST(int inorder[],int start,int end){
    if(start > end){
        return NULL;
    }

    int mid = (start+end) / 2;
    Node* root = new Node(inorder[mid]);

    root->left = build_BST(inorder,start,mid-1);
    root->right = build_BST(inorder,mid+1,end);
    return root;
}

int main(){
    int inorder[] = {1,2,3,4,5,6,7,8,9};
    int start = 0;
    int end = 8;

    Node* root = build_BST(inorder,start,end);
    levelOrderTravesal(root);

    return 0;
}