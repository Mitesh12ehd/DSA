#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//leetcode 56
//Merge intervals
//read notes

//time = nlogn
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    int n = intervals.size();
    sort(intervals.begin(),intervals.end());
    ans.push_back(intervals[0]);
    for(int i=1; i<n; i++){
        auto back = ans[ans.size() - 1];

        if(back[1] >= intervals[i][0]){
            //check if it overlap
            int start = back[0];
            int end = max(back[1],intervals[i][1]);
            ans[ans.size() - 1] = {start,end};
        }
        else{
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}

int main(){
    return 0;
}