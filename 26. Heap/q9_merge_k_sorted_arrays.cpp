#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//approach 1
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    vector<int> ans;
    for(auto it:arr){
        for(auto it1:it){
            ans.push_back(it1);
        }
    }

    sort(ans.begin(),ans.end());
    return ans;
}

//approach 3
//time = O(mlogk) space = O(k)
class node{
    public:
    int data;
    int i;
    int j;

    node(int data,int i,int j){
        this->data = data;
        this->i = i;
        this->j = j;
    }
};
class myComp{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    priority_queue<node*,vector<node*>,myComp> minheap;
    for(int i=0; i<K; i++){
        node* temp = new node(arr[i][0],i,0);
        minheap.push(temp);
    }

    vector<int> ans;
    while(!minheap.empty()){
        node* temp = minheap.top();
        ans.push_back(temp->data);
        minheap.pop();

        //push next elment of array who is considered as smallest
        int i = temp->i;
        int j = temp->j;

        if(j+1 < arr[i].size()){
            node* next = new node(arr[i][j+1],i,j+1);
            minheap.push(next);
        }
    }
    return ans;
}

int main(){
    

    return 0;
}