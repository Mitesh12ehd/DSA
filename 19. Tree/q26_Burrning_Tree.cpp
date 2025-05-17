#include<iostream>
#include<map>
#include<queue>
using namespace std;

//This problem is same concept as 45.all node at distance k
//first solve that problem than solve this 

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

Node* create_Parent_Mapping(Node* root,int target,map<Node*,Node*>& nodeToParent){
    Node* targetNode = NULL;

    //normal level order travesal
    queue<Node*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front->data == target){
            targetNode = front;
        }

        if(front->left != NULL){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if(front->right != NULL){
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return targetNode;
}

int burnTree(Node* targetNode,map<Node*,Node*>& nodeToParent){
    map<Node*,bool> visited;
    queue<Node*> q;

    q.push(targetNode);
    visited[targetNode] = true;
    int ans = 0;

    while(!q.empty()){
        bool isQueue_Addition_Done = false;
        int size = q.size();
        for(int i=0; i<size; i++){
            //process neighbour node
            Node* front = q.front();
            q.pop();

            if(front->left != NULL && visited[front->left] == false){
                isQueue_Addition_Done = true;
                q.push(front->left);
                visited[front->left] = true;
            }
            if(front->right != NULL && visited[front->right] == false){
                isQueue_Addition_Done = true;
                q.push(front->right);
                visited[front->right] = true;
            }
            if(nodeToParent[front] != NULL && visited[nodeToParent[front]] == false){
                isQueue_Addition_Done = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }
        if(isQueue_Addition_Done){
            ans++;
        }
    }
    return ans;
}

int minTime(Node* root, int target) {
    //create mapping and find target node
    map<Node*,Node*> nodeToParent;
    Node* targetNode = create_Parent_Mapping(root,target,nodeToParent);

    int ans = burnTree(targetNode,nodeToParent);
    return ans;
}

int main(){
    return 0;
}