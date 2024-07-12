#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

class Graph{
    public:
    unordered_map< int,list<int> > adjList;

    void addEdge(int u,int v,bool direction){
        //direction = 0, undirected
        //direction = 1, directed

        //create edge from u to v
        adjList[u].push_back(v);
        if(direction == 0){
            // create add from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList(){
        for(auto node:adjList){
            cout << node.first << " -> ";
            for(auto neighbour : node.second){
                cout << neighbour << ",";
            }
            cout << endl;
        }
    }

    void bfs(int src,unordered_map<int,bool>& visited){
        queue<int> q;

        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            cout << frontNode << ",";

            //insert neighbours
            for(auto neighbour:adjList[frontNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(3,5,0);
    g.addEdge(3,7,0);
    g.addEdge(7,6,0);
    g.addEdge(7,4,0);

    g.printAdjacencyList();
    cout << endl;
    // g.bfs(0);

    unordered_map<int,bool> visited;
    int n = 7; //number of node
    for(int i=0; i<n; i++){
        if(!visited[i]){
            g.bfs(i,visited);
        }
    }

    return 0;
}