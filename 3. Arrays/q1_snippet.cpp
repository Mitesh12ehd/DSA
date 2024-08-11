#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void increa(int arr[]){
    arr[0]++;
    cout<<arr[0]<<" "<<arr[1];
}
int main(){
    
    // int arr[10];
    // for (int i=0; i<10; i++){
    //     cin>>arr[i];
    // }
    // for (int i=0; i<10; i++){
    //     cout<<arr[i]<<" ";
    // }

    int arr[]  = {10,20};
    increa(arr);
    cout<<endl;
    cout<<arr[0]<<" "<<arr[1];


    return 0;
}