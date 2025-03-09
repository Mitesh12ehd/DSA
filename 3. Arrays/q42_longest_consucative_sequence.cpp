#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<unordered_set>
using namespace std;

//leetcode 128
//longest consecutive sequence

//naive time=O(n^2) space=O(1)
int linearSearch(vector<int>& nums,int ele){
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(nums[i] == ele){
            return i;
        }
    }
    return -1;
}
int longestConsecutive(vector<int>& nums) {
    int n=nums.size();
    if(n==0) return 0;
    int longest = 1;

    //pick a number and look for its consecutive number
    for(int i=0; i<n; i++){
        int x = nums[i];
        int count = 1;
        while(linearSearch(nums,x+1) != -1){
            x = x+1;
            count = count+1;
        }
        longest = max(longest,count);
    }
    return longest;
}

//better approach using sorting time = O(nlogn)
//[100,102,100,101,101,4,3,2,3,2,1,1,1,2]
// dryrun on given arrays
int longestConsecutive(vector<int>& nums) {
    int n=nums.size();
    if(n==0) return 0;
    sort(nums.begin(),nums.end());

    int longest = 1;
    int lastSmaller = INT_MIN;
    int count = 0;
    for(int i=0; i<n; i++){
        if(nums[i]-1 == lastSmaller){
            //nums[i] is next element of current sequence
            count++;
            lastSmaller = nums[i];
        }
        else if(nums[i] != lastSmaller){
            //start a new sequence
            count = 1;
            lastSmaller = nums[i];
        }
        //ignore case where nums[i] == lastsmaller because then we nothing to do
        longest = max(longest,count);
    }
    return longest;
}

//optimal approach time = O(n)
int longestConsecutive(vector<int>& nums) {
    int n=nums.size();
    if(n==0) return 0;
    unordered_set<int> st;
    for(auto it:nums){
        st.insert(it);
    }

    int longest = 1;
    for(auto it:st){
        if(st.find(it-1) == st.end()){
            int x = it;
            int count = 1;
            while(st.find(x+1) != st.end()){
                x = x+1;
                count++;
            }
            longest = max(longest,count);
        }
    }
    return longest;
}

int main(){
    return 0;
}