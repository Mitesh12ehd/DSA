#include<iostream>
#include<vector>
using namespace std;

// Naukri
// Longest Bitonic Sequence

// Prerequisite :  print LIS

/*
    here we can consider subsequence as bitonic if
    1. it is only increasing
    2. it is only decreasing
    3. it is increasing and then decreasing

    we can store 2 dp array,
        dp1 indicate increasing sequence from front
        dp2 indicate incrasing sequence from end

    arr = [1, 11, 2, 10, 4, 5, 2, 1]
    dp1 = [1, 2,  2, 3,  3, 4, 2, 1]
    dp2 = [1, 5,  2, 4,  3, 3, 2, 1]

    at index 3:
        till index 3 length of longest incresing sunsequence = 3
        and from back till index 3 length of longest increasing subsequence = 4

        so that length of bitonic sequence = 3 + 4 -1 = 6
        -1 because ele at index 3 = 10 is counted in from both side

    note that at index 5 we also get length of bitonic sequence = 6

    Follow-up:
        if we have given rule that,
        increasing and then decreasing sequence are considered as bitonic
        (only increasing or decreasing are not considered)

        in that everything remain same, 
        - intialize ans to 0 because it can be possible ans
        - when we update ans we check if dp1[i] > 1 && dp2[i] > 1
          then we only consider it
*/

// time = O(n^2)
// space = O(1)
int longestBitonicSubsequence(vector<int> &nums,int n) {
    vector<int> dp1(n,1);
    vector<int> dp2(n,1);
    
    for(int i=0; i<n; i++){
        for(int prev=0; prev<i; prev++){
            if(nums[prev] < nums[i]){
                dp1[i] = max(dp1[i],1 + dp1[prev]);
            }
        }
    }

    for(int i=n-1; i>=0; i--){
        for(int prev=n-1; prev>i; prev--){
            if(nums[prev] < nums[i]){
                dp2[i] = max(dp2[i],1 + dp2[prev]);
            }
        }
    }

    int ans = 1;
    for(int i=0; i<n; i++){
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    return ans;
}

int main(){
    return 0;
}