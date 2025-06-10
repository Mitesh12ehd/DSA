#include<iostream>
#include<vector>
using namespace std;

// GFG
// Boolean parentharization

// see notes

// recursion
// time = O(4^n)
// space = O(n)
int fun(int i,int j,bool eval,string& s){
    if(i > j){
        return 0;
    }
    if(i == j){
        if(eval == true){
            return s[i] == 'T';
        }
        else{
            return s[i] == 'F';
        }
    }

    // k indicate where we make partition
    int ways = 0;
    for(int k=i+1; k<=j-1; k=k+2){
        int leftTrue = fun(i,k-1,true,s);
        int leftFalse = fun(i,k-1,false,s);
        int rightTrue = fun(k+1,j,true,s);
        int rightFalse = fun(k+1,j,false,s);

        if(s[k] == '&'){
            if(eval == true){
                ways += leftTrue * rightTrue;
            }
            else{
                ways += (leftTrue*rightFalse) + (leftFalse*rightTrue) + (leftFalse*rightFalse);
            }
        }
        else if(s[k] == '|'){
            if(eval == true){
                ways += (leftTrue * rightTrue) + (leftTrue*rightFalse) + (leftFalse*rightTrue);
            }
            else{
                ways += leftFalse*rightFalse;
            }
        }   
        else if(s[k] == '^'){
            if(eval == true){
                ways += (leftTrue * rightFalse) + (leftFalse * rightTrue);
            }
            else{
                ways += (leftTrue*rightTrue) + (leftFalse*rightFalse);
            }
        }
    }
    return ways;
}
int countWays(string &s) {
    int n = s.length();
    return fun(0,n-1,true,s);
}

// memorization
// time = O(n*n*2*n)
// space = O(n*n*2 + n)
int fun(int i,int j,bool eval,string& s,vector<vector<vector<int>>>& dp){
    if(i > j){
        return 0;
    }
    if(i == j){
        if(eval == true){
            return s[i] == 'T';
        }
        else{
            return s[i] == 'F';
        }
    }
    if(dp[i][j][eval] != -1){
        return dp[i][j][eval];
    }       

    // k indicate where we make partition
    int ways = 0;
    for(int k=i+1; k<=j-1; k=k+2){
        int leftTrue = fun(i,k-1,true,s,dp);
        int leftFalse = fun(i,k-1,false,s,dp);
        int rightTrue = fun(k+1,j,true,s,dp);
        int rightFalse = fun(k+1,j,false,s,dp);

        if(s[k] == '&'){
            if(eval == true){
                ways += leftTrue * rightTrue;
            }
            else{
                ways += (leftTrue*rightFalse) + (leftFalse*rightTrue) + (leftFalse*rightFalse);
            }
        }
        else if(s[k] == '|'){
            if(eval == true){
                ways += (leftTrue * rightTrue) + (leftTrue*rightFalse) + (leftFalse*rightTrue);
            }
            else{
                ways += leftFalse*rightFalse;
            }
        }   
        else if(s[k] == '^'){
            if(eval == true){
                ways += (leftTrue * rightFalse) + (leftFalse * rightTrue);
            }
            else{
                ways += (leftTrue*rightTrue) + (leftFalse*rightFalse);
            }
        }
    }
    dp[i][j][eval] = ways;
    return dp[i][j][eval];
}
int countWays(string &s) {
    int n = s.length();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
    return fun(0,n-1,true,s,dp);
}

// tabulation
// time = O(n*n*2*n)
// space = O(n*n*2)
int countWays(string &s) {
    int n = s.length();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,0)));

    //base case
    for(int i=0; i<n; i++){
        dp[i][i][0] = (s[i] == 'F');
        dp[i][i][1] = (s[i] == 'T');
    }

    //logic
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            for(int eval=0; eval<=1; eval++){
                //handled base cases
                if(i > j){
                    continue;
                }
                if(i == j){
                    continue;
                }

                int ways = 0;
                for(int k=i+1; k<=j-1; k=k+2){
                    int leftTrue = dp[i][k-1][true]; 
                    int leftFalse = dp[i][k-1][false];
                    int rightTrue = dp[k+1][j][true];
                    int rightFalse = dp[k+1][j][false];

                    if(s[k] == '&'){
                        if(eval == true){
                            ways += leftTrue * rightTrue;
                        }
                        else{
                            ways += (leftTrue*rightFalse) + (leftFalse*rightTrue) + (leftFalse*rightFalse);
                        }
                    }
                    else if(s[k] == '|'){
                        if(eval == true){
                            ways += (leftTrue * rightTrue) + (leftTrue*rightFalse) + (leftFalse*rightTrue);
                        }
                        else{
                            ways += leftFalse*rightFalse;
                        }
                    }   
                    else if(s[k] == '^'){
                        if(eval == true){
                            ways += (leftTrue * rightFalse) + (leftFalse * rightTrue);
                        }
                        else{
                            ways += (leftTrue*rightTrue) + (leftFalse*rightFalse);
                        }
                    }
                }
                dp[i][j][eval] = ways; 
            }
        }
    }
    return dp[0][n-1][true];
}

int main(){
    return 0;
}