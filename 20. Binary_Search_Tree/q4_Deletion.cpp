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

Node* find_Node(Node* root,int target){
    if(root == NULL){
        return NULL;
    }

    if(root->data == target){
        return root;
    }
    if(target > root->data){
        return find_Node(root->right,target);
    }
    else{
        return find_Node(root->left,target);
    }
}

int find_maximum(Node* root){
    if(root == NULL){
        return -1;
    }

    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}

Node* deletion_node(Node* root,int target){
    if(root == NULL){
        return NULL;
    }

    if(root->data == target){
        //4 cases
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if(root->left == NULL && root->right != NULL){
            Node* child = root->right;
            delete root;
            return child;
        }
        else if(root->left != NULL && root->right == NULL){
            Node* child = root->left;
            delete root;
            return child;
        }
        else{
            int inorder_predecessor = find_maximum(root->left);
            root->data = inorder_predecessor;
            //delete inordre predecessor from left subtree
            root->left = deletion_node(root->left,inorder_predecessor);
            return root;
        }
    }
    else if(target > root->data){
        root->right = deletion_node(root->right,target);
    }
    else if(target < root->data){
        root->left = deletion_node(root->left,target);
    }
    return root;
}

int main(){
    Node* root = NULL;
    //100 50 150 40 60 175 110 -1
    cout << "Enter the data for node : " << endl;
    takeInput(root);

    cout << "printing the tree" << endl;
    levelOrderTravesal(root);

    deletion_node(root,100);

    cout  << endl;
    cout  << "printing the tree" << endl;
    levelOrderTravesal(root);
    return 0;
}