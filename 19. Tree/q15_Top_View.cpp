#include<iostream>
#include<vector>
#include<map>
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

vector<int> topView(Node *root){
    queue< pair< Node*,int>> q; // queue :  {Node*,y coordinate}
    q.push({root,0});
    map< int, int> mp; //{y coordinate,data}

    //create entry in map
    while(!q.empty()){
        auto front = q.front();
        q.pop();

        Node* temp = front.first;
        int col = front.second;

        //check if there is any entry present in map for given y Coordiante
        if(mp.find(col) == mp.end()){
            //create entry
            mp[col] = temp->data;
        }

        if(temp->left != NULL){
            q.push({ temp->left, col-1});
        }
        if(temp->right != NULL){
            q.push({ temp->right, col+1});
        }
    }

    //iterate on map and create ans;
    vector<int> ans;
    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){
    return 0;
}