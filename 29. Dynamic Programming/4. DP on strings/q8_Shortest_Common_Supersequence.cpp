#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Leetcode 1092
// Shortest Common Supersequence 

// see notes

//tabulation
//time = O(m*n)
//space = O(m*n)
string shortestCommonSupersequence(string str1, string str2) {
    int m = str1.size();
    int n = str2.size();
    
    //lcs logic to fill table
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    //base case
    for(int i=0; i<=m; i++){
        dp[i][0] = 0;
    }
    for(int j=0; j<=n; j++){
        dp[0][j] = 0;
    }
    //logic
    for(int index1=1; index1<=m; index1++){
        for(int index2=1; index2<=n; index2++){
            if(str1[index1 - 1] == str2[index2 - 1]){
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
            } 
            else{
                dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
            }
        }
    }

    int i=m, j=n;
    string ans = "";
    while(i>0 && j>0){
        if(str1[i-1] == str2[j-1]){
            ans.push_back(str1[i-1]);
            i--,j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            //moving upward
            ans.push_back(str1[i-1]);
            i--;
        }
        else{
            //moving downword
            ans.push_back(str2[j-1]);
            j--;
        }
    }
    while(i>0){
        ans.push_back(str1[i-1]);
        i--;
    }
    while(j>0){
        ans.push_back(str2[j-1]);
        j--;
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    return 0;
}