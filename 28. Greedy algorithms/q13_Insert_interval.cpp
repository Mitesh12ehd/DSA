#include<iostream>
#include<vector>
using namespace std;

//Leetcode 57
//Insert interval

//see notes

// interval = (1,2),(3,4),(5,7),(8,10),(12,16)
// newInterval = (6,8)
// ans will be (1,2),(3,4),(5,10),(12,16)

// approach

// here me make one interval of all intervals who overapp our new interval
// there will be segment on left and right which is not overlap
// only middle part is overlap

// here (1,2),(3,4) _________ (12,16)
//       left        middle   right

// find overlapped interval
//     new interval = (6,8)

//     1. (5,7) overlap because 7(end) < 6(start) not true
//     2. (8,10) overlap because 8 < 8 not true

//     our final interval will be (5,10) (min of all,max of all)

// what if there is no overlap with new interval?
//     then we directly add interval to its correct position

//time = O(n)
//space = O(n) to store answer
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n = intervals.size();
    vector<vector<int>> ans;
    int i = 0;
    
    //left non-overlapped part
    while(i < n && intervals[i][1] < newInterval[0]){
        ans.push_back({intervals[i]});
        i++;
    }

    //middle part
    while(i<n && intervals[i][0] <= newInterval[1]){
        newInterval[0] = min(newInterval[0],intervals[i][0]);
        newInterval[1] = max(newInterval[1],intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval);

    while(i<n){
        ans.push_back(intervals[i]);
        i++;
    }
    return ans;
}

int main(){
    return 0;
}