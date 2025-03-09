#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int countDays(vector<int>& weights,int capacity){
    int day = 1;
    int loaded = 0;
    int n = weights.size();

    for(int i=0; i<n; i++){
        if(loaded + weights[i] <= capacity){
            loaded = loaded + weights[i];
        }
        else{
            day++;
            loaded = weights[i];
        }
    }
    return day;
}

//brute force time = O( (sum-maxi+1) * n)
int shipWithinDays(vector<int>& weights, int days) {
    //here starting is maxi because if capacity is less than maxi 
    //then how we can ship item that have more weight than capacity
    int maxi = INT_MIN;
    int sum = 0;
    for(auto it:weights){
        maxi = max(maxi,it);
        sum += it;
    }

    for(int i=maxi; i<=sum; i++){
        int day = countDays(weights,i);
        if(day <= days){
            return i;
        }   
    }
    return -1;
}

//optimal time = O( log(sum-maxi+1) * n)
int shipWithinDays(vector<int>& weights, int days) {
    //here starting is maxi because if capacity is less than maxi 
    //then how we can ship item that have more weight than capacity
    int maxi = INT_MIN;
    int sum = 0;
    for(auto it:weights){
        maxi = max(maxi,it);
        sum += it;
    }

    int start = maxi;
    int end = sum;
    int ans = INT_MAX;
    while(start <= end){
        int mid = (start+end)/2;
        int day = countDays(weights,mid);
        if(day <= days){
            ans = min(ans,mid);
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}

int main(){
    

    return 0;
}