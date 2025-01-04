#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;

int minimumMultiplications(vector<int>& arr, int start, int end) {
    int mod = 100000;
    queue<pair<int,int>> q; // {steps,number}
    q.push({0,start});
    vector<int> dist(100000,INT_MAX);
    dist[start] = 0;
        
    while(!q.empty()){
        int node = q.front().second;
        int steps = q.front().first;
        q.pop();
            
        if(node == end){
            return steps;
        }
            
        for(auto it:arr){
            int num = (node*it) % mod;
                
            if(steps+1 < dist[num]){
                dist[num] = steps+1;
                q.push({steps+1,num});
            }
        }
    }
    return -1;
}

int main(){
    return 0;
}