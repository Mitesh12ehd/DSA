#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout << "enter number of node : ";
    cin >> n;

    vector<vector<int>> adj(n+1,vector<int>(n+1,0));

    int m;
    cout << "enter number of edge : ";
    cin >> m;

    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        //mark 1

        //for undirected
        adj[v][u] = 1;
        adj[u][v] = 1;
    }

    //printing
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}