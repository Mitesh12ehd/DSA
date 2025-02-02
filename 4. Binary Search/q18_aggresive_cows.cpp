#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

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

//here we take search space to check possible answer
int solve(int n, int k, vector<int> &stalls) {
    sort(stalls.begin(),stalls.end());
    int start = 0;
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
    vector<int> stalls{1,2,4,8,9};
    int n = 5;
    int k = 3;
    int minimum_distance = solve(n,k,stalls);
    cout<<minimum_distance;

    return 0;
}