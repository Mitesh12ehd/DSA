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

Node* buildTree(Node* root){
    int data;
    cout << "enter the data = " << endl;
    cin >> data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout << "enter data for left of : " << data <<endl;
    root->left = buildTree(root->left); 
    cout << "enter data for right of : " << data <<endl;
    root->right = buildTree(root->right); 
    return root;
}

void levelOrderTravesal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}

//better level order travesal
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    if(root == NULL){
        return ans;
    }

    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        //get size of current level
        int size = q.size();

        //create ans of one level
        vector<int> v;
        for(int i=0; i<size; i++){
            Node* front = q.front();
            q.pop();
            v.push_back(front->data);
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }

        //store ans of one level
        ans.push_back(v);
    }
    return ans;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //level order
    levelOrderTravesal(root);
    return 0;
}