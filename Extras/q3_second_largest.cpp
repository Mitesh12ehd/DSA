#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

vector<int> getSecondOrderElements(int n, vector<int> a) {
    vector<int> ans;

    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(int i=0; i<n; i++){
        if(a[i] < mini){
            mini = a[i];
        }
        if(a[i] > maxi){
            maxi = a[i];
        }
    }

    int second_max;
    int second_min;

    if(a[0] == maxi){
        second_max = a[1];
    }
    else{
        second_max = a[0];
    }

    if(a[0] == mini){
        second_min = a[1];
    }
    else{
        second_min = a[0];
    }


    for(int i=0; i<n; i++){
        if(a[i] != maxi && a[i] > second_max){
            second_max = a[i];
        }
        if(a[i] != mini && a[i] < second_min){
            second_min = a[i];
        }
    }
    ans.push_back(second_max);
    ans.push_back(second_min);
    return ans;
}