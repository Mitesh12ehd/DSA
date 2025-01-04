#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

//leetcode 347
//top k frequent elements

//brute force = O(n logn) space = O(n)
// static bool myComp(int a,int b){
//     return a>b;
// }
// vector<int> topKFrequent(vector<int>& nums, int k) {
//     unordered_map<int,int> mp;
//     for(auto it:nums){
//         mp[it]++;
//     }

//     vector<int> freq;
//     for(auto it:mp){
//         freq.push_back(it.second);
//     }

//     sort(freq.begin(),freq.end(),myComp);
//     unordered_set<int> st;
//     for(int i=0; i<k; i++){
//         st.insert(freq[i]);
//     }

//     vector<int> ans;
//     for(auto it:nums){
//         if(mp[it] != 0){
//             int freq = mp[it];
//             if(st.find(freq) != st.end()){
//                 ans.push_back(it);
//             }

//             mp[it] = 0;
//         }
//     }
//     return ans;
// }

//optimal time = O(nlogk) space = O(n)
class myComp{
    public:
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.first > b.first;
    }
};
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    for(auto it:nums){
        mp[it]++;
    }
        
    priority_queue<pair<int,int>,vector<pair<int,int>>,myComp> pq;
    for(auto it:mp){
        if(pq.size() < k){
            pq.push({it.second,it.first});
        }
        else{
            int topfreq = pq.top().first;

            if(topfreq < it.second){
                pq.pop();
                pq.push({it.second,it.first});
            }
        }
    }

    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int main(){
    return 0;
}