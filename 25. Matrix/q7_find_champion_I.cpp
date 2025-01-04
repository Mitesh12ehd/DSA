#include<iostream>
#include<vector>
using namespace std;

//leetcode 2923
//find champion I

//champion node is more stronger 
//i.e. champion node have most number of weaker node
//it means that in champion's row there is most number of ones
//we have to find row that has most number of ones

int findChampion(vector<vector<int>>& grid) {
    int n = grid.size();
    int maxOne = 0;
    int ans = -1;
    for(int i=0; i<n; i++){
        int ones = 0;
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1){
                ones++;
            }
        }
        if(ones > maxOne){
            ans = i;
            maxOne = ones;
        }
    }
    return ans;
}

int main(){
    return 0;
}