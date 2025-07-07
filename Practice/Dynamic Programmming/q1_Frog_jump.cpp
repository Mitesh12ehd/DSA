#include<iostream>
#include<vector>
using namespace std;

// Leetcode 403
// Frog jump

// recursion
// time = O(3^n)
// space = O(n)
bool fun(int k,int index,vector<int>& stones){
    //base case
    int n = stones.size();
    if(index >= n){
        return false;
    }
    if(index == n-1){
        return true;
    }
    
    int maxLimit = stones[index] + k + 1;
    int ans1 = false;
    int ans2 = false;
    int ans3 = false;
    for(int m=index+1; m<n && stones[m] <= maxLimit; m++){
        if(stones[m] == stones[index] + k - 1){
            ans1 = fun(k-1,m,stones);
        }
        else if(stones[m] == stones[index] + k){
            ans2 = fun(k,m,stones);
        }
        else if(stones[m] == stones[index] + k + 1){
            ans3 = fun(k+1,m,stones);
        }
    }
    return ans1 || ans2 || ans3;
}
bool canCross(vector<int>& stones) {
    int n = stones.size();
    if(stones[1] != 1){
        return false;
    }

    return fun(1,1,stones);
}

// memorization
// time = O(n^2)
// space = O(n^2 + n)
bool fun(int k,int index,vector<int>& stones,vector<vector<int>>& dp){
    //base case
    int n = stones.size();
    if(index >= n){
        return false;
    }
    if(index == n-1){
        return true;
    }
    if(dp[k][index] != -1){
        return dp[k][index];
    }
    
    int maxLimit = stones[index] + k + 1;
    int ans1 = false;
    int ans2 = false;
    int ans3 = false;
    for(int m=index+1; m<n && stones[m] <= maxLimit; m++){
        if(stones[m] == stones[index] + k - 1){
            ans1 = fun(k-1,m,stones,dp);
        }
        else if(stones[m] == stones[index] + k){
            ans2 = fun(k,m,stones,dp);
        }
        else if(stones[m] == stones[index] + k + 1){
            ans3 = fun(k+1,m,stones,dp);
        }
    }
    dp[k][index] = ans1 || ans2 || ans3;
    return dp[k][index];
}
bool canCross(vector<int>& stones) {
    int n = stones.size();
    if(stones[1] != 1){
        return false;
    }

    vector<vector<int>> dp(n,vector<int>(n,-1));
    return fun(1,1,stones,dp);
}

// tabulation
bool canCross(vector<int>& stones) {
    int n = stones.size();
    if(stones[1] != 1){
        return false;
    }

    vector<vector<bool>> dp(n+1,vector<bool>(n,false));

    //base case
    for(int i=0; i<n; i++){
        dp[i][n-1] = true;
    }

    for(int k=1; k<n; k++){
        for(int index=n-2; index>=1; index--){
            int maxLimit = stones[index] + k + 1;
            int ans1 = false;
            int ans2 = false;
            int ans3 = false;
            for(int m=index+1; m<n && stones[m] <= maxLimit; m++){
                if(stones[m] == stones[index] + k - 1){
                    ans1 = dp[k-1][m];
                }
                else if(stones[m] == stones[index] + k){
                    ans2 = dp[k][m];
                }
                else if(stones[m] == stones[index] + k + 1){
                    ans3 = dp[k+1][m];
                }
            }
            dp[k][index] = ans1 || ans2 || ans3;
        }
    }

    return dp[1][1];
}

int main(){
    return 0;
}