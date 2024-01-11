#include<iostream>
#include<algorithm>
using namespace std;

int findGCD(int A,int B){
    //method 1 -- Time = O(min(a,b))
    // int result = min(A,B);
    // while(result > 0){
    //     if(A % result == 0  &&  B % result == 0){
    //         break;
    //     }
    //     result--;
    // }
    // return result;

    //method 2 Euclid's algorithm -- Time = O(log(a*b)) or O(log a+b)
    if(A==0){
        return B;
    }
    if(B==0){
        return A;
    }
    while(A > 0 && B > 0){
        if(A > B){
            A = A - B;
        }
        else{
            B = B - A;
        }
    }
    return (A==0) ? (B) : (A);
}
int main(){
    int a=100, b=125;
    cout << findGCD(a,b);

    return 0;
}