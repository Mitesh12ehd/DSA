#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// 1547
// Minimum Cost to Cut a Stick

// see notes

// recursion
// time = O(2^m), in worst case we try all combination of cuts
// space = O(m)
int fun(int i,int j,vector<int>& cuts){
    if(i>j){
        return 0;
    }

    int minCost = INT_MAX;
    for(int k=i; k<=j; k++){
        int cost = cuts[j+1] - cuts[i-1] + fun(i,k-1,cuts) + fun(k+1,j,cuts);
        minCost = min(minCost,cost);
    }
    return minCost;
}
int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(),cuts.end());
    //modify the array by inseerting 0 at start and length at end
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    return fun(1,cuts.size()-2,cuts);
}

// memorization
// time = O(m^3) two changing parameter take m^2 and we run loop each time
// space = O(m^2 + m)
int fun(int i,int j,vector<int>& cuts,vector<vector<int>>& dp){
    if(i>j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int minCost = INT_MAX;
    for(int k=i; k<=j; k++){
        int cost = cuts[j+1] - cuts[i-1] + fun(i,k-1,cuts,dp) + fun(k+1,j,cuts,dp);
        minCost = min(minCost,cost);
    }
    dp[i][j] = minCost;
    return dp[i][j];
}
int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(),cuts.end());
    //modify the array by inseerting 0 at start and length at end
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);

    int m = cuts.size();
    vector<vector<int>> dp(m,vector<int>(m,-1));
    return fun(1,cuts.size()-2,cuts,dp);
}

// tabulation
// time = O(m^3)
// space = O(m^2)
int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(),cuts.end());
    //modify the array by inseerting 0 at start and length at end
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);

    int m = cuts.size();
    vector<vector<int>> dp(m,vector<int>(m,0));

    //base case : we intilize dp as 0

    //logic
    for(int i=m-2; i>=1; i--){
        for(int j=1; j<=m-2; j++){
            //handled base case
            if(i>j){
                continue;
            }

            int minCost = INT_MAX;
            for(int k=i; k<=j; k++){
                int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                minCost = min(minCost,cost);
            }
            dp[i][j] = minCost;
        }
    }
    return dp[1][m-2];
}

int main(){
    return 0;
}