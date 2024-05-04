#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>

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

    void topological_sort(int src,unordered_map<int,bool>& visited,stack<int>& ans){
        visited[src] = true;

        for(auto neighbour : adjList[src]){
            if(!visited[neighbour]){
                topological_sort(neighbour,visited,ans);
            }
        }
        //while retruning push in stack
        ans.push(src);
    }
};

int main(){
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,6,1);
    g.addEdge(5,6,1);
    g.addEdge(6,7,1);
    int n = 8; //number of node

    g.printAdjacencyList();
    cout << endl;

    unordered_map<int,bool> visited;
    stack<int> ans;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            g.topological_sort(i,visited,ans);
        }
    }

    cout << endl;
    cout << "Topological sort " << endl;;
    while(!ans.empty()){
        cout << ans.top() << ",";
        ans.pop();
    }

    return 0;
}