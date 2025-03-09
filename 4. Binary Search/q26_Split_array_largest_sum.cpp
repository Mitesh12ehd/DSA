#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//leetcode 410
//split array largest sum

bool isPossibleSolution(vector<int>& arr,int answer,int k){
    int sum = 0;
    int count = 1;

    for(int i=0; i<arr.size(); i++){
        if(sum + arr[i] > answer){
            count++;
            sum = 0;
            sum = sum + arr[i];

            if(count > k){
                return false;
            }
        }
        else{
            sum = sum + arr[i];
        }
    }
    return true;
}

int splitArray(vector<int>& arr, int k) {
    if(arr.size() < k){
        return -1;
    }

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