#include<iostream>
using namespace std;

bool isPossibleSolution(int arr[],int n,int k,long long sol){
    long long timeSum = 0;
    int count = 1;
    for(int i=0; i<n; i++){
        if(arr[i] > sol){
            return false;
        }
        if(timeSum + arr[i] > sol){
            count++;
            timeSum = arr[i];
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
long long findTimes(int arr[], int n, int k) {
    if(k > n){
        return -1;
    }
    long long start =0;
    long long end = 0;
    for(int i=0; i<n; i++){
        end = end + arr[i];
    }
    long long ans = -1;
    
    while(start <= end){
        long long mid = start + (end-start) / 2;
        if(isPossibleSolution(arr,n,k,mid)){
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
    int arr[] = {10,20,30,40};
    int n = 4;
    int k = 2;
    long long minimum_times = findTimes(arr,n,k);
    cout<<minimum_times;
    return 0;
}