#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//GFG
//Fractional knapsack

//here to maintain sorted order based on val/wt 
//we can use priority_queue<pair<double,pair<int,int>>> pq;
//or else vector<double,pair<int,int>>, sort it using comparator

//time = O(nlogn)
//spac = O(n)
static bool myComp(pair<double,pair<int,int>> &a, pair<double,pair<int,int>> &b){
    return a.first > b.first;
}
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    vector<pair<double,pair<int,int>>> v;
    for(int i=0; i<val.size(); i++){
        double ratio = (double)val[i] / (double)wt[i];
        v.push_back({ratio,{val[i],wt[i]}});
    }
    sort(v.begin(),v.end(),myComp);

    double value = 0;
    for(int i=0; i<v.size(); i++){
        if(capacity >= v[i].second.second){
            value = value + v[i].second.first;
            capacity = capacity - v[i].second.second;
        }
        else{
            value = value + ((double)capacity * ((double)v[i].second.first) / (double)v[i].second.second);
            break;
        }
    }
    return value;
}

int main(){
    return 0;
}