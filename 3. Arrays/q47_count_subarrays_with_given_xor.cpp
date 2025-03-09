#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//count subarrays with xor k
//interviewbit

//read notes

//brute force, time n^2, space 1
int solve(vector<int> &A, int B) {
    int n = A.size();
    int ans = 0;
    
    for(int i=0; i<n; i++){
        int var = 0;
        for(int j=i; j<n; j++){
            var = var ^ A[j];
            if(var == B){
                ans++;
            }
        }
    }
    return ans;
}

//optimal
int solve(vector<int> &arr, int k) {
    int n = arr.size();
    int ans = 0;
    unordered_map<int,int> mp;

    int XR = 0;
    mp[XR]++;
    for(int i=0; i<n; i++){
        XR = XR ^ arr[i];

        if(mp.find(XR ^ k) != mp.end()){
            ans = ans + mp[XR ^ k];
        }

        mp[XR]++;
        
    }
    return ans;
}

int main(){
    return 0;
}