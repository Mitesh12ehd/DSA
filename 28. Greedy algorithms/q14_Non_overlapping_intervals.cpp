#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Leetcode 435
//Non overlapping intervals

//This is inverse problem of N meetings in room
//here we need count for interval that cause overlap
//in N meeting in room we count meetings that can schedule without overlap

//Change : here (1,2),(2,3) considered as non overlap intervals

//so here we try to arrange non-overlaped intervals
//and remaining intervals become overlapped, we should remove it

//time = O(nlogn)
//space = O(n)
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();

    //sort according to end
    vector<vector<int>> v; // {endt,start}
    for(int index=0; index<n; index++){
        v.push_back({intervals[index][1],intervals[index][0]});
    }
    sort(v.begin(),v.end());

    int count = 1;
    int freeTime = v[0][0];
    for(int i=1; i<n; i++){
        if(v[i][1] >= freeTime){
            count++;
            freeTime = v[i][0];
        }
    }
    return n-count;
}

int main(){
    return 0;
}