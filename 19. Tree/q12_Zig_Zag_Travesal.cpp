#include<iostream>
#include<vector>
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

vector<vector<int>> zigzagLevelOrder(Node* root) {
    vector<vector<int>> ans;
    if(root == NULL){
        return ans;
    }

    bool leftTORight = true;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int width = q.size();
        vector<int> oneLevel(width);

        for(int i=0; i<width; i++){
            Node* front = q.front();
            q.pop();
            int index = leftTORight ? i : width-i-1;
            oneLevel[index] = front->data;

            if(front->left != NULL){
                q.push(front->left);
            }
            if(front->right != NULL){
                q.push(front->right);
            }
        }

        //change the direction
        leftTORight = !leftTORight;
        ans.push_back(oneLevel);
    }
    return ans;
}

int main(){
    return 0;
}