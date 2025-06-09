#include<iostream>
#include<vector>
using namespace std;

// GFG
// 0/1 knapsack problem

/*
 -We need to pick item such that we can maximize profit
 -and to maximize profit, we need to fill bag as much as possible,
 -we can pick each item once only

 ex. n=3 weight={3, 4, 5}
         value ={30,50,60}
         capacity = 8

         1. we pcik item 2
            totalvalue = 60
            capacity = 8-5 =3
         2. we pick item 0
            totalvalue = 60+30 = 90
            capacity = 3-3 = 0
*/

/*
 Solution:
    - here we can't apply greedy, because due to greedy nature 
      we pick item with more value first and now remaining bag capacity not fullfill
      and it lead to reducing our overall value

      ex. weight = [100, 99, 99]
          value =  [100, 99, 99]
          capacity = 198

          greedy first pick item with weight=100, value=100
                totalValue = 100
                capacity = 198 - 100 = 98

          now we can't pick anymore item
    
          but optimal pick will be 99 + 99 = 198 value
*/

// recursion
/*
    try out all combination to get maximum values
    1. express in terms of index, (index, capacity)
    2. follow exclusion inclusion pattern

    f(n-1,capacity) give till index from 0 to n-1, what maximum value you 
        can generate within given capacity
*/
// time = O(2^n)
// space = O(n)
int fun(int index,int capacity,vector<int>& val,vector<int>& wt){
    if(index == 0){
        if(wt[index] <= capacity){
            return val[index];
        }
        else{
            return 0;
        }
    }

    //exclude
    int exclude = fun(index-1,capacity,val,wt);
    //include
    int include = 0;
    if(wt[index] <= capacity){
        include = val[index] + fun(index-1,capacity-wt[index],val,wt);
    }
    return max(exclude,include);
}
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    return fun(val.size()-1,W,val,wt);
}

// memorization
/*
    1. Find overlapping subproblem
    2. changing parameter are index, 0 to n-1
                            capacity, 0 to W
    3. so we need n * W+1 size dp array
*/
// time = O(n*W)
// space = O(n*W + n)
int fun(int index,int capacity,vector<int>& val,vector<int>& wt,vector<vector<int>>& dp){
    if(index == 0){
        if(wt[index] <= capacity){
            return val[index];
        }
        else{
            return 0;
        }
    }
    if(dp[index][capacity] != -1){
        return dp[index][capacity];
    }

    //exclude
    int exclude = fun(index-1,capacity,val,wt,dp);
    //include
    int include = 0;
    if(wt[index] <= capacity){
        include = val[index] + fun(index-1,capacity-wt[index],val,wt,dp);
    }
    dp[index][capacity] = max(exclude,include);
    return dp[index][capacity];
}
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return fun(val.size()-1,W,val,wt,dp);
}

// tabulation
// time = O(n*W)
// space = O(n*W)
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<vector<int>> dp(n,vector<int>(W+1,-1));

    //base case
    for(int capacity=0; capacity<=W; capacity++){
        if(wt[0] <= capacity){
            dp[0][capacity] = val[0];
        }
        else{
            dp[0][capacity] = 0;
        }
    }

    //logic
    for(int index=1; index<n; index++){
        for(int capacity=0; capacity<=W; capacity++){
            //exclude
            int exclude = dp[index-1][capacity];
            //include
            int include = 0;
            if(wt[index] <= capacity){
                include = val[index] + dp[index-1][capacity-wt[index]];
            }
            dp[index][capacity] = max(exclude,include);
        }
    }
    return dp[n-1][W];
}

// space optimization 1
// time = O(n*W)
// space = O(2W)
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<int> prevRow(W+1,-1);

    //base case
    for(int capacity=0; capacity<=W; capacity++){
        if(wt[0] <= capacity){
            prevRow[capacity] = val[0];
        }
        else{
            prevRow[capacity] = 0;
        }
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
                include = val[index] + prevRow[capacity-wt[index]];
            }
            currRow[capacity] = max(exclude,include);
        }
        prevRow = currRow;
    }
    return prevRow[W];
}

// space optimization 2
// see notes and dryrun 
// time = O(n*W)
// space = O(W)
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<int> prevRow(W+1,-1);

    //base case
    for(int capacity=0; capacity<=W; capacity++){
        if(wt[0] <= capacity){
            prevRow[capacity] = val[0];
        }
        else{
            prevRow[capacity] = 0;
        }
    }

    //logic
    for(int index=1; index<n; index++){
        for(int capacity=W; capacity>=0; capacity--){
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