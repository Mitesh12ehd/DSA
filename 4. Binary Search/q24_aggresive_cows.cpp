#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//gfg

//question explaination
// arr[] = {0,3,4,7,10,9} k = 4
// first we need to sort array because, after sorting,minimum distance exist only
// between consicutinve stalls

// we have to place 4 cows
// {0,3,4,7,9,10}

// 1. we place cows on 0,1,2,3, index
//     0,3,4,7  minimum distance = 1

// 2. we can place cown on 0,2,4,5 index
//     0,  4,  9,10  minimum distance = 1

// 3. we can place cows on 0,2,3,5
//     0,  4,7,  10  minimum distance = 3

// so that answer is 3 ,it is maximum
// (at maximum distace cows will not fight,at small distance
// they may fight because they are aggressive :) )

//approach
//first try with minimum distance 1
//  check if it possible to place k cows possible or not
//  if possible then store answer

//try with minimum distacne 2
//  check if it possible to place k cows possible or not
//  if possible then store answer

bool isPossileSolution(vector<int> &stalls , int k,int mid){
    //can we place k cow with atleast mid minimum distance 
    int count = 1;
    int pos = stalls[0];

    for(int i=1; i<stalls.size(); i++){
        if(stalls[i] - pos >=mid){
            //place cow
            count++;
            pos = stalls[i];
        }
        if(count == k){
            return true;
        }
    }
    return false;
}

//brute force time = O((max-min) * n)
int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(),stalls.end());
    int start = 1;
    int end = stalls[stalls.size()-1] - stalls[0];

    for(int i=start; i<=end; i++){
        if(!isPossileSolution(stalls,k,i)){
            return i-1;
        }
    }
    return end;
}

//optimal time = O(log(max-min) * n)
int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(),stalls.end());
    int start = 1;
    int end = stalls[stalls.size()-1] - stalls[0];
    int ans = -1;

    while(start<=end){
        int mid = start + (end-start)/2;
        if(isPossileSolution(stalls,k,mid)){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}

int main(){
    return 0;
}