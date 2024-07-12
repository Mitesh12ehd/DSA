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

//euclidian algorithm clear using recursion
int solveProblem(int m,int n){
        if(n == 0){
            return m;
        }
        
        return solveProblem(n,m%n);
    }
int gcd(int a, int b){
    if(a==0){
        return a;
    }
    if(b==0){
        return b;
    }
        
    int m = max(a,b);
    int n = min(a,b);
    return solveProblem(m,n);
}

int main(){
    int a=100, b=125;
    cout << findGCD(a,b);

    return 0;
}