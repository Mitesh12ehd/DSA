#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Leetcode 1707
// Maximum XOR With an Element From Array

// brute force
// time = O(n * q)
// space = O(1)
vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> ans;
    for(int q=0; q<queries.size(); q++){
        int maxi = -1;
        int num = queries[q][0];
        int bound = queries[q][1];
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= bound){
                maxi = max(maxi,nums[i] ^ num);
            }
        }
        ans.push_back(maxi);
    }
    return ans;
} 

// optimal
// time = O(qlogq + nlogn + n+q)
// space = O(n * 32) in worst case
class Node {
    public:
    Node* links[2]; 
    bool containsKey(int bit) {
        return (links[bit] != NULL); 
    }
    Node* get(int bit) {
        return links[bit]; 
    }
    void put(int bit, Node* node) {
        links[bit] = node; 
    }
};
class Trie {
    private:
    Node* root;
    public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        // we insert from left to right in binary format
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1; // get ith bit
            if (!node->containsKey(bit)) {
                node->put(bit, new Node()); 
            }
            node = node->get(bit); 
        }
    }

    int getMax(int num) {
        Node* node = root; 

        int maxNum = 0;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1; //ith bit of num
            // check if node contain opposite of bit 1
            if(bit == 1 && node->containsKey(0)){
                // mark ith bit of ans as 1
                maxNum = maxNum | (1 << i);

                // move
                node = node->get(0);
            }
            // check if node contain opposite of bit 0
            else if(bit == 0 && node->containsKey(1)){
                // mark ith bit of ans as 1
                maxNum = maxNum | (1 << i);

                // move
                node = node->get(1);
            }
            else{
                // go with same bit as not able to find opposite
                node = node->get(bit);
            }
        }
        return maxNum;
    }
}; 
vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    sort(nums.begin(),nums.end()); 
    vector<pair<int,pair<int,int>>> query; // {ai,{xi,index}}
    for(int i=0; i<queries.size(); i++){
        query.push_back({queries[i][1],{queries[i][0],i}});
    }
    sort(query.begin(),query.end());

    Trie trie;
    vector<int> ans(queries.size(),-1);
    int arrIndex = 0;
    
    //iterate over the queries
    for(int i=0; i<query.size(); i++){
        int ai = query[i].first;
        int xi = query[i].second.first;
        int queryIndex = query[i].second.second;

        // store element that are <= ai
        while(arrIndex < nums.size() && nums[arrIndex] <= ai){
            trie.insert(nums[arrIndex]);
            arrIndex++;
        }

        //if arrIndex == 0 , it means we have not any element that are <= ai
        //                   in that case our ans will be -1
        if(arrIndex != 0){
            ans[queryIndex] = trie.getMax(xi);
        }
    }
    return ans;
}

int main(){
    return 0;
}