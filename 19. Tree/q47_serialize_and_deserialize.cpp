#include<iostream>
#include<queue>
using namespace std;

//Leetcode 297
//Serialize and Deserialize binary tree

//see notes  

//time = O(n)
//space = O(n)
//for both functions

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

class Codec {
    public:
        // Encodes a tree to a single string.
        string serialize(Node* root) {
            if(!root){
                return "";
            }

            string str = "";
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                Node* curr = q.front();
                q.pop();

                if(curr == NULL){
                    str = str + "#,";
                }
                else{
                    str = str + to_string(curr->data) + ",";
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
            return str;
        }
    
        // Decodes your encoded data to tree.
        Node* deserialize(string data) {
            if(data.empty()){
                return NULL;
            }

            //split string by ','
            vector<string> v;
            for(int i=0; i<data.length(); i++){
                string s = "";
                while(i< data.length() && data[i] != ','){
                    s.push_back(data[i]);
                    i++;
                }
                if(s != ""){
                    v.push_back(s);
                }
            }

            int index = 0;
            Node* root = new Node(stoi(v[index++]));
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                Node* node = q.front();
                q.pop();

                string s = v[index++];
                if(s == "#"){
                    node->left = NULL;
                }
                else{
                    Node* leftNode = new Node(stoi(s));
                    node->left = leftNode;
                    q.push(leftNode);
                }

                s = v[index++];
                if(s == "#"){
                    node->right = NULL;
                }
                else{
                    Node* rightNode = new Node(stoi(s));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
            return root;
        }
    };