#include<iostream>
#include<climits>
using namespace std;
int main(){

    int arr[] = {1,2,3,4,5,6,6,7,8,9};
    int size = sizeof(arr) / 4;

    int max = INT_MIN;
    int min = INT_MAX;

    for(int i=0; i<size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }

    cout<<"max = "<<max<<endl;
    cout<<"min = "<<min<<endl;

    return 0;
}