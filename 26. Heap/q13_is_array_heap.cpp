#include<iostream>
using namespace std;

//gfg
//does array represent heap

bool isMaxHeap(int arr[], int n){
    for(int i=0; i<n; i++){
        int left = 2*i+1;
        int right = 2*i+2;
            
        if(left>=0 && left<n){
            if(arr[left] > arr[i]){
                return false;
            }
        }
        if(right>=0 && right<n){
            if(arr[right] > arr[i]){
                return false;
            }
        }
    }
        
    return true;
}

int main(){
    return 0;
}