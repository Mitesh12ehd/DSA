#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Leetcode 1463
// Cheery pickup II

//recursion
/*
- here we have to move with both robot at same time,
  because there might be common cell, so we need to consider common cell
  once only in answer

  1. index are (i,j1,j2)
  2. explore all paths
  3. take max

- here there are 3 movement of robot 1, and for each movement of robot 1,
  there are 3 movement of robot 2
  so there will be 9 combination of moving two robots
*/
//time = O( 9^m )  there can be 9 call per 1 call and depth of tree = n
//space = O(m)
int fun(int i,int j1,int j2,vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();

    if(j1 < 0 || j1 >=n || j2 < 0 || j2 >= n){
        //out of bound base case
        return INT_MIN;
    }
    if(i == m-1){
        //both robot reaches the last row, we can also write i2 == m-1
        if(j1 == j2){
            //both robot reach to same cell in last row
            return grid[i][j1];
        }
        else{
            return grid[i][j1] + grid[i][j2]; 
        }
    }

    //logic for all 9 combination
    //dj means delta j = change in j
    int maxi = INT_MIN;
    for(int dj1=-1; dj1<=1; dj1++){
        for(int dj2=-1; dj2<=1; dj2++){
            //robot 1 go into change in dj1
            //robot 2 go into change in dj2
            int ans;
            if(j1 == j2){
                ans = grid[i][j1] + fun(i+1, j1 + dj1, j2 + dj2,grid);
            }
            else{
                ans = grid[i][j1] + grid[i][j2] + fun(i+1, j1 + dj1, j2 + dj2,grid);
            }
            maxi = max(maxi,ans);
        }
    }
    return maxi;
}
int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    return fun(0,0,n-1,grid);
}

//memorization
/*
 1. Find changing variable
     here i, j1, j2
 2, Range of i, 0 to m-1,
             j1,0 to n-1
             j2,0 to n-1
    
    we need m*n*n dp array
*/
//time = O(9*m*n*n)
//space = O(m*n*n + m)
int fun(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
    int m = grid.size();
    int n = grid[0].size();

    if(j1 < 0 || j1 >=n || j2 < 0 || j2 >= n){
        //out of bound base case
        return INT_MIN;
    }
    if(i == m-1){
        //both robot reaches the last row, we can also write i2 == m-1
        if(j1 == j2){
            //both robot reach to same cell in last row
            return grid[i][j1];
        }
        else{
            return grid[i][j1] + grid[i][j2]; 
        }
    }
    if(dp[i][j1][j2] != -1){
        return dp[i][j1][j2];
    }

    //logic for all 9 combination
    //dj means delta j = change in j
    int maxi = INT_MIN;
    for(int dj1=-1; dj1<=1; dj1++){
        for(int dj2=-1; dj2<=1; dj2++){
            //robot 1 go into change in dj1
            //robot 2 go into change in dj2
            int ans;
            if(j1 == j2){
                ans = grid[i][j1] + fun(i+1, j1 + dj1, j2 + dj2,grid,dp);
            }
            else{
                ans = grid[i][j1] + grid[i][j2] + fun(i+1, j1 + dj1, j2 + dj2,grid,dp);
            }
            maxi = max(maxi,ans);
        }
    }
    dp[i][j1][j2] = maxi;
    return dp[i][j1][j2];
}
int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
    return fun(0,0,n-1,grid,dp);
}

//tabulation
/*
 1. use same size of array
 2. use reverse logic of recursion

 - base case: base case will be hit for last row
    dp[m-1][j1][j2]
 - express changing variable in terms of loops
    i,  m-2 to 0
    j1, 0 to n-1
    j2, 0 to n-1
*/
//time = O(n*n + m*n*n*9)
//space = O(m*n*n)
int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));

    //base case
    for(int j1=0; j1<n; j1++){
        for(int j2=0; j2<n; j2++){
            if(j1 == j2){
                dp[m-1][j1][j2] = grid[m-1][j1];
            }
            else{
                dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }
    }
    
    //logic
    for(int i=m-2; i>=0; i--){
        for(int j1=0; j1<n; j1++){
            for(int j2=0; j2<n; j2++){

                //9 combinations
                int maxi = INT_MIN;
                for(int dj1=-1; dj1<=1; dj1++){
                    for(int dj2=-1; dj2<=1; dj2++){
                        int ans;
                        if(j1+dj1 < 0 || j1+dj1 >=n || j2+dj2 < 0 || j2+dj2 >= n){
                            continue;
                        }
                        
                        if(j1 == j2){
                            ans = grid[i][j1] + dp[i+1][j1 + dj1][j2 + dj2];
                        }
                        else{
                            ans = grid[i][j1] + grid[i][j2] + dp[i+1][j1+ dj1][j2 + dj2];
                        }
                        maxi = max(maxi,ans);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][n-1];
}

//space optimization
/*
- in 1D dp we optimize from n to 1
  in 2D dp we optimize from n^2 to n
  now in 3D dp we optimize from n^3 to n^2

- we just require ans of nextRow to calculate ans of current row
*/
//time = O(n*n + m*n*n*9)
//space = O(n*n)
int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> nextRow(n,vector<int>(n));

    //base case
    for(int j1=0; j1<n; j1++){
        for(int j2=0; j2<n; j2++){
            if(j1 == j2){
                nextRow[j1][j2] = grid[m-1][j1];
            }
            else{
                nextRow[j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }
    }
    
    //logic
    for(int i=m-2; i>=0; i--){
        vector<vector<int>> currRow(n,vector<int>(n));
        for(int j1=0; j1<n; j1++){
            for(int j2=0; j2<n; j2++){
                //9 combinations
                int maxi = INT_MIN;
                for(int dj1=-1; dj1<=1; dj1++){
                    for(int dj2=-1; dj2<=1; dj2++){
                        int ans;
                        if(j1+dj1 < 0 || j1+dj1 >=n || j2+dj2 < 0 || j2+dj2 >= n){
                            continue;
                        }
                        
                        if(j1 == j2){
                            ans = grid[i][j1] + nextRow[j1 + dj1][j2 + dj2];
                        }
                        else{
                            ans = grid[i][j1] + grid[i][j2] + nextRow[j1+ dj1][j2 + dj2];
                        }
                        maxi = max(maxi,ans);
                    }
                }
                currRow[j1][j2] = maxi;
            }
        }
        nextRow = currRow;
    }
    return nextRow[0][n-1];
}

int main(){
    return 0;
}