#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//leetcode 1334
//find the city with smallest number of neighbours at a thresold distance

//this can be solved using floyd warshall algorithm and dijkastra both
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist(n,vector<int>(n,100000));
    for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int weight = it[2];
        dist[u][v] = weight;
        dist[v][u] = weight;
    }
    for(int i=0; i<n; i++){
        dist[i][i] = 0;
    }

    //floyd warshall
    for(int via=0; via<n; via++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
            }
        }
    }

    int minCount = INT_MAX;
    int cityNo = -1;
    for(int i=0; i<n; i++){
        int count = 0;
        for(int j=0; j<n; j++){
            if(dist[i][j] <= distanceThreshold){
                count++;
            }
        }

        if(count <= minCount){
            minCount = count;
            cityNo = i;
        }
    }
    return cityNo;
}

int main(){
    return 0;
}