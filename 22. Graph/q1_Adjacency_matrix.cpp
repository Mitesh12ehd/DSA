#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout << "enter number of node : ";
    cin >> n;

    vector<vector<int>> adj(n,vector<int>(n,0));

    int e;
    cout << "enter number of edge : ";
    cin >> e;

    for(int i=0; i<e; i++){
        int u,v;
        cin >> u >> v;
        //mark 1
        adj[u][v] = 1;
    }

    //printing
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}