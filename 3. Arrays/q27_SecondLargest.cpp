#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//approach 1 time = O(2n)
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

//apporach 2 time = n
int secondLargest(vector<int>& arr){
    if(arr.size() < 2){
        return -1;
    }

    int large = INT_MIN;
    int second_large = INT_MIN;

    for(auto ele:arr){
        if(ele > large){
            second_large = large;
            large = ele;
        }
        else if (ele > second_large && ele != large) {
            second_large = ele;
        }
    }

    if(second_large == INT_MIN){
        return -1;
    }
    return second_large;
}

int main(){
    vector<int> arr{1,2,3,4,5,6,7,8,9,10,11,112,566,334};
    cout << secondLargest(arr);

    return 0;
}