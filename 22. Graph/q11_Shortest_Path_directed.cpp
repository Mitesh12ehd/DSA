#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
#include<algorithm>
#include<stack>
#include<limits.h>
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

    void topological(int src,unordered_map<int,bool>& visited,stack<int>& ans){
        visited[src] = true;

        for(auto neighbour : adjList[src]){ 
            if(!visited[neighbour.first]){
                topological(neighbour.first,visited,ans);
            }
        }
        //while retruning push in stack
        ans.push(src);
    }

    void shortest_path_dfs(stack<int> topological_order,int n){
        vector<int> dist(n,INT_MAX);

        int src = topological_order.top();
        topological_order.pop();
        dist[src] = 0;

        for(auto nbr:adjList[0]){
            if(dist[0] + nbr.second < dist[nbr.first]){
                dist[nbr.first] = dist[0] + nbr.second;
            }
        }

        while(!topological_order.empty()){
            int topElement = topological_order.top();
            topological_order.pop();

            if(dist[topElement] != INT_MAX){
                for(auto nbr:adjList[topElement]){
                    if(dist[topElement] + nbr.second < dist[nbr.first]){
                        dist[nbr.first] = dist[topElement] + nbr.second;
                    }
                }
            }
        }

        cout << "printing ans" <<endl;
        for(int i=0; i<n; i++){
            cout << i << "->" <<dist[i] << endl;
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,3,1);
    g.addEdge(2,1,2,1);
    g.addEdge(1,3,3,1);
    g.addEdge(2,4,6,1);
    g.addEdge(4,3,1,1);
    g.addEdge(2,3,5,1);
    int n = 5;

    g.printAdjacencyList();

    stack<int> topological_order;
    unordered_map<int,bool> visited;
    g.topological(0,visited,topological_order);
    g.shortest_path_dfs(topological_order,5);




    return 0;
}