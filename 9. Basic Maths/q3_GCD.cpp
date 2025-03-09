#include<iostream>
#include<algorithm>
using namespace std;

//naive approach O (min(a,b))
int findGCD(int a,int b){
    int ans = 1;
    int mini = min(a,b);
    for(int i=1; i<=mini; i++){
        if(a % i == 0 && b % i == 0){
            ans = i;
        }
    }
    return ans;
}

//better approach O (min(a,b))
int findGCD(int a,int b){
    int mini = min(a,b);
    for(int i=mini; i>=1; i--){
        if(a % i == 0 && b % i == 0){
            return i;
        }
    }
    return -1;
}

//Euclid's algorithm
// gcd(a,b) = gcd(a-b,b) untill one of them is 0,other number is GCD , assume a>b

//time = log(min(a,b)) , whenever division happening time are given in log terms

int findGCD(int a,int b){
    while(a > 0 && b > 0){
        if(a > b){
            a = a - b;
        }
        else{
            b = b - a;
        }
    }
    if(a == 0){
        return b;
    }
    else{
        return a;
    }
}

int findGCD(int a,int b){
    while(a > 0 && b > 0){
        if(a > b){
            a = a % b;
        }
        else{
            b = b % a;
        }
    }
    if(a == 0){
        return b;
    }
    else{
        return a;
    }
}

//recursive approach
int helper(int m,int n){
    if(n == 0){
        return m;
    }
        
    return helper(n,m%n);
}
int findGCD(int a, int b){
    int m = max(a,b);
    int n = min(a,b);
    return helper(m,n);
}

int main(){
    return 0;
}