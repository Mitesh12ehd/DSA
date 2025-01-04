#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#include<set>
using namespace std;

//gfg

//using minheap
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    int v = adj.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(v,INT_MAX);

    pq.push({0,src});
    dist[src] = 0;

    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it:adj[node]){
            int weight = it.second;
            int adjNode = it.first;

            if(distance + weight < dist[adjNode]){
                dist[adjNode] = distance + weight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

//using set
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    int v = adj.size();
    set<pair<int,int>> st;
    vector<int> dist(v,INT_MAX);

    st.insert({0,src});
    dist[src] = 0;

    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int distance = it.first;
        st.erase(it);

        for(auto it:adj[node]){
            int adjNode = it.first;
            int weight = it.second;

            if(distance + weight < dist[adjNode]){
                //erase if it previsouly visited
                if(dist[adjNode] != INT_MAX){
                    st.erase({dist[adjNode],adjNode});
                }

                dist[adjNode] = distance + weight;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

int main(){
    

    return 0;
}