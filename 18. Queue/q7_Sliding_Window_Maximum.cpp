#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;

    for(int i=0; i<k; i++){
        //remove smnaller element than current
        while(!dq.empty() && nums[i] >= nums[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(nums[dq.front()]);

    //process remaining window
    for(int i=k; i<nums.size(); i++){
        //remove element 
        if(!dq.empty() && (i - dq.front() >= k)){
            dq.pop_front();
        }

        //remove element smaller than currrent
        while(!dq.empty() && nums[i] >= nums[dq.back()]){
            dq.pop_back();
        }
        //insert element of next window
        dq.push_back(i);

        //find ans of k window
        ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main(){
    vector<int> nums{1,3,1,2,0,5};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums,k);
    for(auto it:ans){
        cout << it << " ";
    }
    return 0;
}