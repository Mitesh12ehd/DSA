#include<iostream>
#include<vector>
#include<deque>
#include<climits>
using namespace std;

//Take u forward
//Frog jumps with k distances

//recursion
//time = O(k^n)
//space = O(n)
int fun(int index,vector<int>& heights,int k){
    if(index == 0){
        return 0;
    }

    int minCost = INT_MAX;
    for(int j=1; j<=k; j++){
        //cost to jump from index-j th stone to index stone
        if(index-j < 0){
            break;
        }
        int cost = fun(index-j,heights,k) + abs(heights[index] - heights[index-j]);
        minCost = min(minCost,cost);
    }
    return minCost;
}
int frogJump(vector<int>& heights, int k) {
    return fun(heights.size()-1,heights,k);
}

//memorization
//time = O(k*n)
//space = O(2n)
int fun(int index,vector<int>& dp,vector<int>& heights,int k){
    if(index == 0){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }

    int minCost = INT_MAX;
    for(int j=1; j<=k; j++){
        //cost to jump from index-j th stone to index stone
        if(index-j < 0){
            break;
        }
        int cost = fun(index-j,dp,heights,k) + abs(heights[index] - heights[index-j]);
        minCost = min(minCost,cost);
    }
    dp[index] = minCost;
    return dp[index];
}
int frogJump(vector<int>& heights, int k) {
    vector<int> dp(heights.size(),-1);
    return fun(heights.size()-1,dp,heights,k);
}

//tabulation
//time = O(n)
//space = O(n)
int frogJump(vector<int>& heights, int k) {
    int n = heights.size();

    vector<int> dp(n,-1);
    dp[0] = 0;
    for(int index=1; index<n; index++){
        int minCost = INT_MAX;
        for(int j=1; j<=k; j++){
            //cost to jump from index-j th stone to index stone
            if(index-j < 0){
                break;
            }
            int cost = dp[index-j] + abs(heights[index] - heights[index-j]);
            minCost = min(minCost,cost);
        }
        dp[index] = minCost;
    }
    return dp[n-1];
}


//space optimization
//time = O(n)
//space = O(k) in worst case it also take O(n)

// in frog jump question we optimize space to O(n) to O(2) 
// because in that question frog can jump at max 2 step 
// so we need 2 variable to store them

// so here we can optimize O(n) to O(k)
// we only need answer of prev k indexes

// so we can use structure like deque to store only k element
// when we move to new index remove element from front and add element to back

int main(){
    return 0;
}