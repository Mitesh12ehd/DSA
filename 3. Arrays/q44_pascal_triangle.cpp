#include<iostream>
#include<vector>
using namespace std;

//question can be asked in three way
//read notes

//1) given row = x, col = y , find element of that place
int findElement(int row,int col){
    row--;
    int ans = 1;
    for(int i=1; i<col; i++){
        ans = ans * row;
        ans = ans / i;
        row--;
    }
    return ans;
}

//2) find nth row of pascal triangle
//brute force : nth row has n elements , time = O(n^2)
vector<int> findRow(int n){
    vector<int> ans;
    for(int col=1; col<=n; col++){
        ans.push_back(findElement(n,col));
    }
    return ans;
}
//optimal approach
vector<int> findRow(int n){
    vector<int> v;
    int ans = 1;
    v.push_back(ans);
    //we run loop from second col , index = 1
    for(int i=1; i<n; i++){
        ans = ans * (n-i);
        ans = ans / i;
        v.push_back(ans);
    }
    return v;
}

//3) print till nth row of pascal triangle, leetcode 118
//brute force
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for(int row=1; row<=numRows; row++){
        vector<int> v;
        for(int col=1; col<=row; col++){
            v.push_back(findElement(row,col));
        }
        ans.push_back(v);
    }
    return ans;
}
//optimal
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for(int row=1; row<=numRows; row++){
        ans.push_back(findRow(row));
    }
    return ans;
}

int main(){
    return 0;
}