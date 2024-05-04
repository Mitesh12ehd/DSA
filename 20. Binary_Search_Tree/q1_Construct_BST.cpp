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

Node* insertIntoBST(Node* root,int data){
    if(root == NULL){
        //first node
        root = new Node(data);
        return root;
    }

    if(root->data  >  data){
        //insert in left
        root->left = insertIntoBST(root->left,data);
    }
    else{
        root->right = insertIntoBST(root->right,data);
    }
    return root;
}

void takeInput(Node*& root){
    int data;
    cin >> data;
    while(data != -1){
        root = insertIntoBST(root,data);
        cin >> data;
    }
}

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

int main(){
    Node* root = NULL;
    //100 150 200 175 160 140 210 205 190
    cout << "Enter the data for node : " << endl;
    takeInput(root);

    cout << "printing the tree" << endl;
    levelOrderTravesal(root);
    return 0;
}