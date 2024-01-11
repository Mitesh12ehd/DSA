#include<iostream>
#include<limits.h>
using namespace std;

void findMax(int arr[], int n, int i, int& maximum){
    //base condition
    if(i >= n){
        return;
    }
    //processing
    if(arr[i] > maximum){
        maximum = arr[i];
    }
    //recursive approach
    findMax(arr,n,i+1,maximum);
}

int main(){
    int arr[] = {10,20,30,60,40,50};
    int n = 8;

    int maximum = INT_MIN;
    int i = 0;
    findMax(arr,n,i,maximum);
    cout << maximum;

    return 0;
}