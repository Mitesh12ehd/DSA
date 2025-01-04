#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//method 1
int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    return nums[nums.size()-k];
}

//method 2
//time = O(nlogn) space = O(k)
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0; i<k; i++){
        pq.push(nums[i]);
    }

    for(int i=k; i<nums.size(); i++){
        if(pq.top() < nums[i]){
            pq.pop();
            pq.push(nums[i]);
        }
    }

    return pq.top();
}

int main(){
    return 0;
}