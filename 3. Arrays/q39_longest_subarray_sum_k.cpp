#include<iostream>
#include<vector>
#include<limits.h>
#include<unordered_map>
using namespace std;

//longest sub array with sum k
//array only contain positive interger

//brute force
int lenOfLongestSubarr(vector<int>& arr, int k) {
    int n = arr.size();
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum = sum + arr[j];
            if(sum == k){
                ans = max(ans,j-i+1);
            }
        }
    }
    return ans;
}

//two pointer approach
int lenOfLongestSubarr(vector<int>& arr, int k) {
    int n = arr.size();
    int left=0,right=0;
    int sum = 0;
    int ans = 0;

    while(right < n){
        while(left <= right && sum > k){
            sum = sum - arr[left];
            left++;
        }

        if(sum == k){ 
            ans = max(ans,right-left+1);
        }
        right++;
        if(right < n){
            sum = sum + arr[right];
        }
    }
    return ans;
}

//this approach can handle nagative also

//prefix sum
//maintain each prefix sum with index mapping
//arr = [1,2,3,1,1,1,1,4,2,3] dryrun on it

//edgecase
//arr[2,0,0,3]  k = 3
//we only update prefix sum in map if we get new sum
//if we directly update sum in map check what happens we get short prefix sum but we want older sum first, so that we get longest subarray
//valid ans = 3  but ans given by algorithm = 2 (before handling case)
int lenOfLongestSubarr(vector<int>& arr, int k) {
    int n = arr.size();
    unordered_map<int,int> mp; //sum,index
    int ans = 0;
    int sum = 0;

    for(int i=0; i<n; i++){
        sum = sum + arr[i];

        //execute only for subarray with some intial elements
        if(sum == k){
            ans = max(ans,i+1);
        }

        int remainder = sum  - k;
        if(mp.find(remainder) != mp.end()){
            int len = i - mp[remainder];
            ans = max(ans,len);
        }

        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
    }
    return ans;
}

int main(){
    

    return 0;
}