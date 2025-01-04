#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

//leetcode 1331
//rank transform of an array

//brute force
vector<int> arrayRankTransform(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans;

    for(int i=0; i<n; i++){
        set<int> st;
        for(int j=0; j<n; j++){
            if(arr[j] < arr[i]){
                st.insert(arr[j]);
            }
        }
            
        ans.push_back(st.size()+1);
    }

    return ans;
}

//here we take map of element,array of index
//because array may contain duplicate and map remove duplicates automatically
vector<int> arrayRankTransform(vector<int>& arr) {
    map<int,vector<int>> mp; //<element,index>

    for(int i=0; i<arr.size(); i++){
        mp[arr[i]].push_back(i);
    }

    int rank = 1;
    for(auto it:mp){
        for(auto index:it.second){
            arr[index] = rank;
        }

        rank++;
    }

    return arr;
}

int main(){
    

    return 0;
}