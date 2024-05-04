#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class Graph{
    public:

    unordered_map<int, list<pair<int,int>> > adjList;
    void addEdge(int u,int v,int weight,bool direction){
        //direction = 0, undirected
        //direction = 1, directed

        //create edge from u to v
        adjList[u].push_back({v,weight});
        if(direction == 0){
            // create add from v to u
            adjList[v].push_back({u,weight});
        }
    }

    void printAdjacencyList(){
        for(auto node:adjList){
            cout << node.first << " -> ";
            for(auto neighbour : node.second){
                cout << "("  << neighbour.first << "," << neighbour.second << "),";
            }
            cout << endl;
        }
    }

    void ShortestPath_BFS(int src,int dest){
        queue<int> q;
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto nbr:adjList[frontNode]){
                if(!visited[nbr.first]){
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                    parent[nbr.first] = frontNode;
                }
            }
        }
        
        //create ans from parent map
        vector<int> ans;
        int node = dest;
        while(node != -1){
            ans.push_back(node);
            node = parent[node];
        }
        reverse(ans.begin(),ans.end());
        cout << "shortest path" << endl;
        for(auto it:ans){
            cout << it << ",";
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0,1,1,0);
    g.addEdge(0,2,1,0);
    g.addEdge(0,3,1,0);
    g.addEdge(1,4,1,0);
    g.addEdge(2,5,1,0);
    g.addEdge(3,6,1,0);
    g.addEdge(4,5,1,0);
    g.addEdge(5,6,1,0);
    int n = 7;

    g.printAdjacencyList();

    int src = 0;
    int dest = 5 ;
    g.ShortestPath_BFS(src,dest);


    return 0;
}