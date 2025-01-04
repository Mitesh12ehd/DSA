#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

//using array of list
int main(){
    
    int n;
    cout << "enter number of node : ";
    cin >> n;

    int m;
    cout << "enter number of edge : ";
    cin >> m;

    vector<int> adj[n+1];

    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;

        //for undirected
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //printing
    for(int i=0; i<n+1; i++){
        cout << i << " -> ";
        for(int j=0; j<adj[i].size(); j++){
            cout << adj[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}

//using list of list
// int main(){
//     int n;
//     cout << "enter number of node : ";
//     cin >> n;

//     int m;
//     cout << "enter number of edge : ";
//     cin >> m;

//     vector<vector<int>> adj(n+1);

//     for(int i=0; i<m; i++){
//         int u,v;
//         cin >> u >> v;

//         //for undirected
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     //printing
//     for(int i=0; i<n+1; i++){
//         cout << i << " -> ";
//         for(int j=0; j<adj[i].size(); j++){
//             cout << adj[i][j] << ",";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//using map
// int main(){
//     int m;
//     cout << "enter number of edge : ";
//     cin >> m;

//     unordered_map< int,vector<int> > adj;

//     for(int i=0; i<m; i++){
//         int u,v;
//         cin >> u >> v;

//         //for undirected
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
        
//     for(auto node:adj){
//         cout << node.first << " -> ";
//         for(auto neighbour : node.second){
//             cout << neighbour << ",";
//         }
//         cout << endl;
//     }
//     return 0;
// }