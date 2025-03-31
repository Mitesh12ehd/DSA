#include<iostream>
#include<vector>
using namespace std;

//Leetcode 216
//Combination Sum III

//time = O(2^9) space = O(2^9 + 9)
void helper(int k,int n,int i,int count,int sum,
            vector<int>& v,vector<vector<int>>& ans){
    if(count == k){
        if(sum == n){
            ans.push_back(v);
        }
        return;
    }
    // sum > n is a pruning condition to reduce tree
    if(i >= 10 || sum > n){
        return;
    }

    //include
    v.push_back(i);
    helper(k,n,i+1,count+1,sum+i,v,ans);
    v.pop_back();
    //exclude
    helper(k,n,i+1,count,sum,v,ans);
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    int i=1;
    int count=0;
    int sum = 0;
    vector<int> v;
    helper(k,n,i,count,sum,v,ans);
    return ans;
}


int main(){
    return 0;
}