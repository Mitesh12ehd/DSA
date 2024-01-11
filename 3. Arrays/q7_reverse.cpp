#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11};
    int size = sizeof(arr) / 4;


    //method 1 using another array
    // int reverse[size];

    // for(int i=0; i<size; i++){
    //     reverse[size-i-1] = arr[i];
    // }
    // for(int i=0; i<size; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0; i<size; i++){
    //     cout<<reverse[i]<<" ";
    // }


    //method 2 --swap
    int start = 0;
    int end = size - 1;

    while (start<=end){

        int temp; 
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // swap(arr[start],arr[end]); //predifined function
        start++;
        end--;
    }
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}