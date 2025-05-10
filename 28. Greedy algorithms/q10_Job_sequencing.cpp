#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//GFG
//Job Sequencing

//see notes

// given job deadline and profit
// job can be performed before or on that day of deadline
// each job takes one day to finish

// ex. deadline[i] = 4, ith job can be done on 4th day or before it.
// only one job can be done in one day

// find
// The total maximum profit earned by completing those jobs.
// The maximum number of jobs that can be completed within their deadlines.

//time = O(nlogn + n*maxProfit) in worst case
//space = O(n + maxDeadLine)
static bool myComp(pair<int,int>& a,pair<int,int>& b){
    return a.second > b.second;
}
vector<int> jobSequencing(vector<int> deadline, vector<int> profit) {
    int n = deadline.size();

    int maxDeadline = -1; //to use later
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        maxDeadline = max(maxDeadline,deadline[i]);
        v.push_back({deadline[i],profit[i]});
    }
    sort(v.begin(),v.end(),myComp);

    int count = 0;
    int totalProfit = 0;
    vector<bool> slot(maxDeadline+1,false); //true -> slot filled. else false

    for(int i=0; i<n; i++){
        for(int j=v[i].first; j>=1; j--){
            if(slot[j] == false){
                count++;
                totalProfit += v[i].second;
                slot[j] = true;
                break;
            }
        }
    }
    return {count,totalProfit};
}

//optimized approach using disjoint set union (DSU)

//time = O(nlogn)
//space = O(n)

//small change in unionBySize
//generally we we union by size and mark parent based on size of set u and v
//but here we need to make u to the parent of v always
//so that parent[ulp_v] = ulp_u;
//        size[ulp_u] += size[ulp_v];
  
class DisjointSet{
    public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int node){
        if(parent[node] == node){
            return node;
        }
        parent[node] = findParent(parent[node]);
        return parent[node];
    }
    void UnionBySize(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        //if they are already belonged to same component
        if(ulp_u == ulp_v){
            return;
        }

        // u will always become parent of v
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }
};
vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    int n = deadline.size();

    int maxDeadline = -1; //to use later
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        maxDeadline = max(maxDeadline,deadline[i]);
        v.push_back({deadline[i],profit[i]});
    }
    sort(v.begin(),v.end(),myComp);

    DisjointSet ds(maxDeadline+1);
    int count = 0;
    int totalProfit = 0;
    for(int i=0; i<n; i++){
        int emptySlot = ds.findParent(v[i].first);

        if(emptySlot > 0){
            totalProfit += v[i].second;
            count++;

            ds.UnionBySize(emptySlot - 1, emptySlot);
        }
    }
    return {count,totalProfit};
}

int main(){
    jobSequencing({2,1,2,1,1},{100,19,27,25,15});
    return 0;
}