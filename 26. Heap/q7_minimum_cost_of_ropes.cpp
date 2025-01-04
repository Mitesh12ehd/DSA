#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//gfg
//minimum cost of ropes

int minCost(vector<int>& arr) {
    priority_queue<int,vector<int>,greater<int>> minheap;
        
    for(auto it:arr){
        minheap.push(it);
    }
        
    int totalCost = 0;
    while(minheap.size() > 1){
        int roap1 = minheap.top();
        minheap.pop();
        int roap2 = minheap.top();
        minheap.pop();
            
        int currentCost = roap1+roap2;
        totalCost = totalCost + currentCost;
        minheap.push(currentCost);
    }
    return totalCost;
}

int main(){
    return 0;
}