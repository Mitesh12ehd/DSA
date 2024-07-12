#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int secondLargest(vector<int>& arr){
    int maxi = INT_MIN;

    for(auto it:arr){
        maxi = (it > maxi) ? (it) : (maxi) ;
    }

    int ans = INT_MIN;
    for(auto it:arr){
        if(it < maxi  && it > ans){
            ans = it;
        }
    }
    return ans;
}

int main(){
    vector<int> arr{1,2,3,4,5,6,7,8,9,10,11,112,566,334};
    cout << secondLargest(arr);

    return 0;
}