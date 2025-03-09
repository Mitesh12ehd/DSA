#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//GFG
//Painter partition

bool isPossibleSolution(vector<int>& arr,int answer,int k){
    int timeSum = 0;
    int count = 1;

    for(int i=0; i<arr.size(); i++){
        if(timeSum + arr[i] > answer){
            count++;
            timeSum = 0;
            timeSum = timeSum + arr[i];

            if(count > k){
                return false;
            }
        }
        else{
            timeSum = timeSum + arr[i];
        }
    }
    return true;
}

int minTime(vector<int>& arr, int k) {
    int start = INT_MIN;
    int end = 0;
    for(auto it:arr){
        start = max(start,it);
        end = end + it;
    }

    int ans = -1;
    while(start<=end){
        int mid = (start+end) / 2;
        if(isPossibleSolution(arr,mid,k)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main(){
    return 0;
}