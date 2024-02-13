#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
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
vector<vector<int>> verticalTraversal(Node* root) {
    queue< pair< Node*,pair<int,int>>> q; // queue :  {Node*,{row,col}}
    q.push({root,{0,0}});
    map< int, map<int,multiset<int>>> mp;

    //create entry in map
    while(!q.empty()){
        auto front = q.front();
        q.pop();

        Node* temp = front.first;
        auto coordinate = front.second; //{x,y}
        int row = coordinate.first;
        int col = coordinate.second;

        mp[col][row].insert(temp->data);

        if(temp->left != NULL){
            q.push({ temp->left, {row+1,col-1}});
        }
        if(temp->right != NULL){
            q.push({ temp->right, {row+1,col+1}});
        }
    }

    //iterate on map and create ans;
    vector<vector<int>> ans;
    for(auto it:mp){
        auto colMap = it.second;
        vector<int> virticalLine;
        for(auto it1:colMap){
            auto rowMap = it1.second;
            for(auto it:rowMap){
                virticalLine.push_back(it);
            }
        }
        ans.push_back(virticalLine);
    }
    return ans;
}

int main(){
    return 0;
}