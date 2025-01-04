#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;

//leetcode 632
//smallest range covering elements from k lists

//brute force
//total element = m
//time = O(m*k)
//space = O(k)
vector<int> smallestRange(vector<vector<int>>& nums) {
    pair<int,int> ans = {-1000000,1000000};
    int k = nums.size();
    vector<int> index(k,0);

    while(true){
        //calculate range
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        bool outOfBound = false;
        for(int i=0; i<k; i++){
            if(index[i] >= nums[i].size()){
                outOfBound = true;
                break;
            }

            min_val = min(min_val,nums[i][index[i]]);
            max_val = max(max_val,nums[i][index[i]]);
        }

        if(outOfBound){
            break;
        }

        //update answer range if we got shorter range
        if ((max_val - min_val < ans.second - ans.first) ||
            (max_val - min_val == ans.second- ans.first && min_val < ans.first)) {
            ans = {min_val, max_val};
        }

        //now increament the pointer who point the current minimum for all three array
        int mini_index = 0;
        for(int i=1; i<k; i++){
            if(nums[i][index[i]] < nums[mini_index][index[mini_index]]){
                mini_index = i;
            }
        }
        index[mini_index]++;
    }
    return {ans.first,ans.second};
}

//optimal
class node{
    public:
    int data;
    int row;
    int col;

    node(int data,int row,int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};
vector<int> smallestRange(vector<vector<int>>& nums) {
    int k = nums.size();
    priority_queue<node*,vector<node*>,compare> minheap;

    int rangeStart = INT_MAX;
    int rangeEnd = INT_MIN;
    for(int i=0; i<k; i++){
        int element = nums[i][0];
        rangeStart = min(rangeStart,element);
        rangeEnd = max(rangeEnd,element);

        node* temp = new node(element,i,0);
        minheap.push(temp);
    }

    int min_val = rangeStart;
    int max_val = rangeEnd;
    while(!minheap.empty()){
        node* temp = minheap.top();
        minheap.pop();

        min_val = temp->data;
        int row = temp->row;
        int col = temp->col;

        if ((max_val - min_val < rangeEnd - rangeStart) ||
            (max_val - min_val == rangeEnd- rangeStart && min_val < rangeStart)) {
            rangeStart = min_val;
            rangeEnd = max_val;
        }
            
        if(col+1 < nums[row].size()){
            node* newNode = new node(nums[row][col+1],row,col+1);
            minheap.push(newNode);
            max_val = max(max_val,nums[row][col+1]);
        }
        else{
            break;
        }
    }

    return {rangeStart,rangeEnd};
}


int main(){
    return 0;
}