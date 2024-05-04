#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>

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

    void topological_sort(int n,vector<int>& ans){
        queue<int> q;
        unordered_map<int,int> indegree;

        //indegree calculate
        for(auto i:adjList){
            int src = i.first;
            for(auto nbr:i.second){
                indegree[nbr]++;
            }
        }

        //put all node inside queue that has indegree 0
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);

            //decrease indegree when remove from graph
            for(auto nbr:adjList[frontNode]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
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
    
    vector<int> ans;
    //we have assumed connected graph if disconncted then we have to create visited map
    g.topological_sort(n,ans);

    if(ans.size() == n){
        cout << "cycle not present";
    }
    else{
        cout << "cycle present";
    }

    return 0;
}