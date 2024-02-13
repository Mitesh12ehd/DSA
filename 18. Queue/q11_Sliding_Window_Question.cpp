//sum of min and max element of all subarray of size k

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq1;
    deque<int> dq2;
    int ans = 0;

    for(int i=0; i<k; i++){
        //remove smnaller element than current
        while(!dq1.empty() && nums[i] >= nums[dq1.back()]){
            dq1.pop_back();
        }

        //remove larger element than current
        while(!dq2.empty() && nums[i] <= nums[dq2.back()]){
            dq2.pop_back();
        }
        dq1.push_back(i);
        dq2.push_back(i);
    }
    ans = ans + nums[dq1.front()] + nums[dq2.front()];

    //process remaining window
    for(int i=k; i<nums.size(); i++){
        //remove element 
        if(!dq1.empty() && (i - dq1.front() >= k)){
            dq1.pop_front();
        }
        if(!dq2.empty() && (i - dq2.front() >= k)){
            dq2.pop_front();
        }

        //remove element smaller than currrent
        while(!dq1.empty() && nums[i] >= nums[dq1.back()]){
            dq1.pop_back();
        }
        // remove larger element than current
        while(!dq2.empty() && nums[i] <= nums[dq2.back()]){
            dq2.pop_back();
        }
        //insert element of next window
        dq1.push_back(i);
        dq2.push_back(i);

        //find ans of k window
        ans = ans + nums[dq1.front()] + nums[dq2.front()];
    }
    return ans;
}

int main(){
    vector<int> nums{2,5,-1,7,-3,-1,-2};
    int k = 4;
    cout << maxSlidingWindow(nums,k);
    return 0;
}