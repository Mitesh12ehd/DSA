#include<iostream>
#include<vector>
#include<limits.h>
#include<cmath>
using namespace std;

//leetcode 875 
//koko eating bananas

int findMax(vector<int>& piles){
    int ans = INT_MIN;
    for(auto it:piles){
        ans = max(ans,it);
    }
    return ans;
}
int calculateTotalHours(int k,vector<int>& piles){
    int time = 0;
    for(int i=0; i<piles.size(); i++){
        time = time + ceil( (double)piles[i] / (double)k );
    }
    return time;
}

//brute force time = O(max(piles) * n)
int minEatingSpeed(vector<int>& piles, int h) {
    int maxi = findMax(piles);

    for(int i=1; i<=maxi; i++){
        int reqTime = calculateTotalHours(i,piles);
        if(reqTime <= h){
            return i;
        }
    }
    return maxi; //it never execute
}

//optimal time = (n * log(max(piles)))
int minEatingSpeed(vector<int>& piles, int h) {
    int start = 1; 
    int end = findMax(piles);
    int ans = INT_MAX;

    while(start <= end){
        int mid = start + (end-start)/2;
        int totalHours = calculateTotalHours(mid,piles);
        if(totalHours <= h){
            ans = min(ans,mid);
            end = mid-1; 
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main(){
    

    return 0;
}