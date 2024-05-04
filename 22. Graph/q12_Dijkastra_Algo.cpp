#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<set>
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

    void Dijkastra(int src,int n){
        vector<int> dist(n,INT_MAX);
        set< pair<int,int> > st;

        //intial step
        dist[src] = 0;
        st.insert({0,src});

        while(!st.empty()){
            //fetch smallest element from set that is first element
            // as set is always sorted
            auto topElement = *(st.begin());//type of st.begin is iterater we fetch value using derefrence operator
            int nodeDistance = topElement.first;
            int node = topElement.second;

            //pop from set
            st.erase(st.begin());

            //travese all neighbour of node
            for(auto nbr:adjList[node]){
                if(nodeDistance + nbr.second < dist[nbr.first]){
                    //update distance
                    //find entry in set
                    auto result = st.find({dist[nbr.first],nbr.first});
                    //if found then remove
                    if(result != st.end()){
                        st.erase(result);
                    }

                    //updation in distance array
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert({dist[nbr.first],nbr.first});
                }
            }
        }
        cout << "printing ans:" << endl;
		for(int i=0; i<n; i++) {
			cout << dist[i] <<", ";
		}
    }
};

int main(){
    Graph g;
    g.addEdge(6,3,2,0);
    g.addEdge(6,1,14,0);
    g.addEdge(6,5,9,0); 
    g.addEdge(1,2,7,0);
    g.addEdge(1,3,9,0);
    g.addEdge(2,3,10,0);
    g.addEdge(2,4,15,0);
    g.addEdge(3,4,11,0);
    g.addEdge(4,5,6,0);

    g.printAdjacencyList();
    
    int n = 7;
    g.Dijkastra(6,n);
    return 0;
}