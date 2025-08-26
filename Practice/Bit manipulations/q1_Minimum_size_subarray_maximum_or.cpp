#include<iostream>
#include<vector>
using namespace std;

// Leetcode 2411
// Smallest Subarrays With Maximum Bitwise OR

// brute force
vector<int> smallestSubarrays(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n,1);

    for(int i=0; i<n; i++){
        int bitwiseOR = 0;
        int maxi = 0;
        for(int j=i; j<n; j++){
            bitwiseOR = bitwiseOR | nums[j];
            if(bitwiseOR > maxi){
                ans[i] = j-i+1;
                maxi = bitwiseOR;
            }
        }
    }

    return ans;
}

// optimal using leetcode hints
vector<int> smallestSubarrays(vector<int>& nums) {
    int n = nums.size();

    vector<int> ans(n,1);
    vector<int> lastSeen(32,0); // assume 32 bit number

    for(int i=n-1; i>=0; i--){
        for(int bit=0; bit<32; bit++){
            // check bit'th bit is 1 or not
            if((nums[i] & (1 << bit)) > 0) {
                lastSeen[bit] = i;
            }

            ans[i] = max(ans[i],lastSeen[bit] - i + 1);
        }
    }

    return ans;
}

int main(){
    return 0;
}