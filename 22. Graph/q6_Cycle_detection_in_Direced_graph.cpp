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

    void dfs(int src,unordered_map<int,bool>& visited){
        cout << src << ",";
        visited[src] = true;

        for(auto neighbour : adjList[src]){
            if(!visited[neighbour]){
                dfs(neighbour,visited);
            }
        }
    }

    bool cycle_detection_using_dfs(int src,unordered_map<int,bool>& visited,
                                    unordered_map<int,bool>& dfsVisited){
        visited[src] = true;
        dfsVisited[src] = true;

        for(auto neighbour:adjList[src]){
            if(!visited[neighbour]){
                bool ageKaAnswer = cycle_detection_using_dfs(neighbour,visited,dfsVisited);
                if(ageKaAnswer == true){
                    return true;
                }
            }
            if(visited[neighbour] == true && dfsVisited[neighbour] == true){
                return true;
            }
        }
        dfsVisited[src] = false;
        return false;
    }
};

int main(){
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(4,0,1);
    int n = 5;

    g.printAdjacencyList();
    cout << endl;

    //driver code for using dfs
    bool is_cycle_present = false;
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            is_cycle_present = g.cycle_detection_using_dfs(i,visited,dfsVisited);
            if(is_cycle_present){
                break;
            }
        }
    }
    if(is_cycle_present){
        cout << "cycle present" << endl;
    }
    else{
        cout << "cycle not present" << endl;
    }
    

    return 0;
}