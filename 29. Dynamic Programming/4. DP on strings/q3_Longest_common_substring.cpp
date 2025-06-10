#include<iostream>
#include<vector>
using namespace std;

// GFG
// Longest common substring

// see notes

// tabulation
// time = O(m*n)
// space = O(m*n)
int longestCommonSubstr(string& s1, string& s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    //base case
    for(int i=0; i<=m; i++){
        dp[i][0] = 0;
    }
    for(int j=0; j<=n; j++){
        dp[0][j] = 0;
    }

    //logic
    int ans = 0;
    for(int index1=1; index1<=m; index1++){
        for(int index2=1; index2<=n; index2++){
            if(s1[index1 - 1] == s2[index2 - 1]){
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                ans = max(ans,dp[index1][index2]);
            } 
            else{
                dp[index1][index2] = 0;
            }
        }
    }
    return ans;
}

// space optimizations
// time = O(m*n)
// space = O(n)
int longestCommonSubstr(string& s1, string& s2) {
    int m = s1.size();
    int n = s2.size();
    vector<int> prevRow(n+1,0);

    //base case
    for(int j=0; j<=n; j++){
        prevRow[j] = 0;
    }

    //logic
    int ans = 0;
    for(int index1=1; index1<=m; index1++){
        vector<int> currRow(n+1,0);
        for(int index2=1; index2<=n; index2++){
            if(s1[index1 - 1] == s2[index2 - 1]){
                currRow[index2] = 1 + prevRow[index2 - 1];
                ans = max(ans,currRow[index2]);
            } 
            else{
                currRow[index2] = 0;
            }
        }
        prevRow = currRow;
    }
    return ans;
}

int main(){
    return 0;
}