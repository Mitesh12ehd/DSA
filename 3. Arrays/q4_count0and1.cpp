#include<iostream>
using namespace std;
int main(){
    int arr[] = {0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,1,0,0};
    int size = sizeof(arr) / 4;

    int numZero = 0;
    int numOne = 0;

    for(int i=0; i<size; i++){
        if(arr[i] == 0){
            numZero++;
        }
        else{
            numOne++;
        }
    }

    cout<<"Total 1 = "<<numOne<<endl;
    cout<<"Total 0 = "<<numZero<<endl;
    return 0;
}