#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<limits.h>
using namespace std;

void create_Adjacency_List(int n,vector<vector<int>> matrix,unordered_map<int, list<pair<int,int>> >& adjList){
    //create adjacency list
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] != 0){
                adjList[i].push_back({j,matrix[i][j]});
            }
        }
    }
}

int spanningTree(int n,unordered_map<int, list<pair<int,int>> >& adjList){
    //create all 3 array and intialize
    vector<int> key(n,INT_MAX);
    vector<bool> mst(n,false);
    vector<int> parent(n,-1);

    //algorithm
    key[0] = 0;
    parent[0] = -1;

    for(int i=0; i<n; i++){

        //find index that has minimum key value
        int mini = INT_MAX;
        int u;
        for(int m=0; m<n; m++){
            if(mst[m] == false  &&  key[m] < mini){
                u = m;
                mini = key[m];
            }
        }

        //mark u as true
        mst[u] = true;

        //check all neighbour of u
        for(auto nbr:adjList[u]){
            int node = nbr.first;
            int weight = nbr.second;

            if(mst[node] == false  &&  weight < key[node]){
                key[node] = weight;
                parent[node] = u;
            }
        }
    }

    //calculate total weight
    int ans = 0;
    for(int i=0; i<n; i++){
        if(parent[i] == -1){
            continue;
        }
        for(auto nbr:adjList[i]){
            int node = nbr.first;
            int weight = nbr.second;
            if(node == parent[i]){
                ans = ans + weight;
            }
        }
    }
    return ans;
}



int main(){
    vector<vector<int>> graph;
    graph.push_back({0,2,0,6,0});
    graph.push_back({2,0,3,8,5});
    graph.push_back({0,3,0,0,7});
    graph.push_back({6,8,0,0,0});
    graph.push_back({0,5,7,0,0});
    int n = 5;

    unordered_map<int, list<pair<int,int>> > adjList;
    create_Adjacency_List(n,graph,adjList);
    cout << spanningTree(n,adjList);
    return 0;
}