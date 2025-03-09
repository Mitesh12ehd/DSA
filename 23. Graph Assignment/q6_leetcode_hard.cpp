#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;

//leetcode 1928
//minimum cost to reach destination in time

//it is little bit similar to cheapest flight within k stops
//in that question we consider totalstops and distance both 
//(totalstops are by simple queue and distance by dist array) 

//likewise here
//both cost and time are important
//so we keep track of both using two array
//and we try to minimize both

int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
    int n = passingFees.size();
    vector<vector<pair<int,int>>> adj(n);
    for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int weight = it[2];
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({passingFees[0],{0,0}}); //cost,time,node

    vector<int> times(n,INT_MAX);
    vector<int> costs(n,INT_MAX);
    costs[0] = passingFees[0];
    times[0] = 0;
            
    while(!pq.empty()){
        int cost = pq.top().first;
        int time = pq.top().second.first;
        int node = pq.top().second.second;
        pq.pop();

        if(node == n-1){
            return cost;
        }

    for(auto it:adj[node]){
        int adjNode = it.first;
        int adjWeight = it.second;
        int newTime = time + adjWeight;

            //if cost can be reduced
            if(newTime <= maxTime && cost+passingFees[adjNode] < costs[adjNode]){
                costs[adjNode] = cost + passingFees[adjNode];
                times[adjNode] = newTime;
                pq.push({costs[adjNode],{newTime,adjNode}});
            }

            //if time can be reduced
            else if(newTime <= maxTime && newTime < times[adjNode]){
                times[adjNode]  = newTime;
                pq.push({cost + passingFees[adjNode],{newTime,adjNode}});
            }
        }
    }
    return -1;
}


int main(){

    return 0;
}