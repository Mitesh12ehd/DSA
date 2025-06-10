#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Naukri
//Print longest common subsequence

//see notes
//dryrun on s1 = "abcde" , s2 = "bdgek"

//tabulation 
//time = O(m*n + (m+n))
string findLCS(int n, int m,string &text1, string &text2){
    m = text1.size();
    n = text2.size();
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
            if(text1[index1 - 1] == text2[index2 - 1]){
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
            } 
            else{
                dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
            }
        }
    }

    string str = "";
    int i=m, j=n;
    while(i > 0 && j > 0){
        if(text1[i-1] == text2[j-1]){
            str.push_back(text1[i-1]);
            i--,j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(str.begin(),str.end());
    return str;
}

int main(){
    string text1 = "abcde";
    string text2 = "bdgek";
    cout << findLCS(0,0,text1,text2);
    return 0;
}