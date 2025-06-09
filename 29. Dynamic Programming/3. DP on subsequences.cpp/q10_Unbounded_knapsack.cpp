#include<iostream>
#include<vector>
using namespace std;

// GFG
// Knapsack with duplicate items

/*
    here we have infinite supply so that we include again item after picking it
*/

// recursion
// time = more than O(2^n), we can say expontial
// space = O(capacity)
int fun(int index,int capacity,vector<int>& val,vector<int>& wt){
    if(index == 0){
        return val[0] * (capacity/wt[0]);
    }

    //exclude
    int exclude = fun(index-1,capacity,val,wt);
    //include
    int include = 0;
    if(wt[index] <= capacity){
        include = val[index] + fun(index,capacity-wt[index],val,wt);
    }
    return max(exclude,include);
}
int knapSack(vector<int>& val, vector<int>& wt, int W) {
    return fun(val.size()-1,W,val,wt);
}

//memorization
//time = O(n*capacity)
//space = O(n*capacity + capacity)
int fun(int index,int capacity,vector<int>& val,vector<int>& wt,vector<vector<int>>& dp){
    if(index == 0){
        return val[0] * (capacity/wt[0]);
    }
    if(dp[index][capacity] != -1){
        return dp[index][capacity];
    }

    //exclude
    int exclude = fun(index-1,capacity,val,wt,dp);
    //include
    int include = 0;
    if(wt[index] <= capacity){
        include = val[index] + fun(index,capacity-wt[index],val,wt,dp);
    }
    dp[index][capacity] = max(exclude,include);
    return dp[index][capacity];
}
int knapSack(vector<int>& val, vector<int>& wt, int W) {
    int n = val.size();
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return fun(val.size()-1,W,val,wt,dp);
}

// tabulation
// time = O(n*capacity)
// space = O(n*capacity)
int knapSack(vector<int>& val, vector<int>& wt, int W) {
    int n = val.size();
    vector<vector<int>> dp(n,vector<int>(W+1,-1));

    //base case
    for(int capacity=0; capacity<=W; capacity++){
        dp[0][capacity] = val[0] * (capacity/wt[0]);
    }

    //logic
    for(int index=1; index<n; index++){
        for(int capacity=0; capacity<=W; capacity++){
            //exclude
            int exclude = dp[index-1][capacity];
            //include
            int include = 0;
            if(wt[index] <= capacity){
                include = val[index] + dp[index][capacity-wt[index]];
            }
            dp[index][capacity] = max(exclude,include);
        }
    }
    return dp[n-1][W];
}

// space optimization
// time = O(n*W)
// space = O(2W)
int knapSack(vector<int>& val, vector<int>& wt, int W) {
    int n = val.size();
    vector<int> prevRow(W+1,-1);

    //base case
    for(int capacity=0; capacity<=W; capacity++){
        prevRow[capacity] = val[0] * (capacity/wt[0]);
    }

    //logic
    for(int index=1; index<n; index++){
        vector<int> currRow(W+1,-1);
        for(int capacity=0; capacity<=W; capacity++){
            //exclude
            int exclude = prevRow[capacity];
            //include
            int include = 0;
            if(wt[index] <= capacity){
                include = val[index] + currRow[capacity-wt[index]];
            }
            currRow[capacity] = max(exclude,include);
        }
        prevRow = currRow;
    }
    return prevRow[W];
}

// space optimization 2
/*
    to calculate currRow[capacity] we only need prevRow[capacity]
    so we can replace it within one row
*/
// time = O(n*W)
// space = O(W)
int knapSack(vector<int>& val, vector<int>& wt, int W) {
    int n = val.size();
    vector<int> prevRow(W+1,-1);

    //base case
    for(int capacity=0; capacity<=W; capacity++){
        prevRow[capacity] = val[0] * (capacity/wt[0]);
    }

    //logic
    for(int index=1; index<n; index++){
        for(int capacity=0; capacity<=W; capacity++){
            //exclude
            int exclude = prevRow[capacity];
            //include
            int include = 0;
            if(wt[index] <= capacity){
                include = val[index] + prevRow[capacity-wt[index]];
            }
            prevRow[capacity] = max(exclude,include);
        }
    }
    return prevRow[W];
}

int main(){
    return 0;
}