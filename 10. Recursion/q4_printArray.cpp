#include<iostream>
using namespace std;

void print(int arr[],int n,int i){
    //base condition
    if(i >= n){
        return;
    }
    //processing
    cout << arr[i] << " ";
    //recursive condiotion
    print(arr,n,i+1);
}

int main(){
    int arr[5] = {10,20,30,40,50};
    int n = 5;
    int i = 0;
    print(arr,5,0);

    return 0;
}