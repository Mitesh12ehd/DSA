#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

//leetcode 703
//kth largest element in a stream

//brute force
class KthLargest {
public:
    vector<int> v;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        sort(nums.begin(),nums.end());
        for(auto it:nums){
            v.push_back(it);
        }
    }
    
    // time = O(n)
    int add(int val) {
        v.push_back(val);
        int i = v.size()-2;
        while(i>=0 && v[i]>val){
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = val;

        return v[v.size()-k];
    }
};

//optimal
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minheap;
    int capacity;
    KthLargest(int k, vector<int>& nums) {
        capacity = k;
        for(auto it:nums){
            minheap.push(it);
            if(minheap.size() > k){
                minheap.pop();
            }
        }
    }
    
    // time = O(n)
    int add(int val) {
        if(minheap.size() < capacity){
            minheap.push(val);
        }
        else if(minheap.top() < val){
            minheap.pop();
            minheap.push(val);
        }
        return minheap.top();
    }
};

int main(){
    return 0;
}