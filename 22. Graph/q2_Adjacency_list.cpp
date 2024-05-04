#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class Graph{
    public:
    //non- weighted
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


    //weighted
    // unordered_map< int,list<pair<int,int>> > adjList;

    // void addEdge(int u,int v,int weight,bool direction){
    //     //direction = 0, undirected
    //     //direction = 1, directed

    //     //create edge from u to v
    //     adjList[u].push_back({v,weight});
    //     if(direction == 0){
    //         // create add from v to u
    //         adjList[v].push_back({u,weight});
    //     }
    // }

    // void printAdjacencyList(){
    //     for(auto node:adjList){
    //         cout << node.first << " -> ";
    //         for(auto neighbour : node.second){
    //             cout << "("  << neighbour.first << "," << neighbour.second << "),";
    //         }
    //         cout << endl;
    //     }
    // }
};

int main(){
    // int n;
    // cout << "enter number of node : ";
    // cin >> n;

    // int e;
    // cout << "enter number of edge : ";
    // cin >> e;

    //undirected graph
    // Graph g;
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);
    // g.printAdjacencyList();

    //directed adge
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,1);
    g.printAdjacencyList();


    return 0;
}