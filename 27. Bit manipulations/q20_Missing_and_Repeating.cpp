#include<iostream>
#include<vector>
using namespace std;

//GFG
//Missing and Repeating

//ex.[4,3,6,2,1,1]

//to understand this problem first understand single number III

vector<int> findTwoElement(vector<int>& arr) {
    int n = arr.size();

    int xr = 0;
    for(int i=0; i<n; i++){
        xr = xr ^ arr[i];
        xr = xr ^ (i+1);
    }

    //now xr contains xor of missing and repeating number
    int rightMost = (xr & (xr-1)) ^ xr;
    int b1 = 0;
    int b2 = 0;
    for(int i=0; i<n; i++){
        if((arr[i] & rightMost) != 0){
            b1 = b1 ^ arr[i];
        }
        else{
            b2 = b2 ^ arr[i];
        }
    }
    for(int i=1; i<=n; i++){
        if((i & rightMost) != 0){
            b1 = b1 ^ i;
        }
        else{
            b2 = b2 ^ i;
        }
    }

    //now bucket b1 AND b2 have diffrent number, one is missing and
    //one is repeating

    //find out which one is missing and which one is repeating
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == b1){
            count++;
        }
    }
    if(count == 2) return {b1,b2};
    return {b2,b1};
}

int main(){
    return 0;
}