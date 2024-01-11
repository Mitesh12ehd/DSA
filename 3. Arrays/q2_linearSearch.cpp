#include<iostream>
using namespace std;

int linearSearch(int arr[],int size,int key){
    for(int i=0; i<size; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[5] = {4,7,2,9,5};
    int size = sizeof(arr) / 4;
    int key = 9;

    int index = linearSearch(arr,size,key);
    cout<<index;
    return 0;
}