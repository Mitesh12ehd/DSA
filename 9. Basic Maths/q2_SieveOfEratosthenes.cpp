#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int countsieves(int n){
    //method 3 Sieve of Eratosthenes Time = O(n*loglog n)
    // if(n == 0){
    //     return 0;
    // }
    // vector<bool> sieve(n+1,true);//all are marked sieve
    // sieve[0] = sieve[1] = false;

    // for(int i=2; i<=n; i++){
    //     if(sieve[i]){
    //         int j=i*2;
    //         while(j<=n){
    //             sieve[j] = false;
    //             j = j + i;
    //         }
    //     }
    // }

    // method 4 --optimized Sieve of eratothenes
    if(n == 0){
        return 0;
    }
    vector<bool> sieve(n+1,true);//all are marked sieve
    sieve[0] = sieve[1] = false;

    for(int i=2; i*i<=n; i++){
        if(sieve[i]){
            int j=i*i; //first unmarked number is at i*i,
                        //before i*i are already marked
            while(j<=n){
                sieve[j] = false;
                j = j + i;
            }
        }
    }

    //count prime
    int count = 0;
    for(int i=0; i<n+1; i++){
        if(sieve[i]){
            count++;
        }
    }
    return count;
}

int main(){
    //leetcode 204
    int n = 35;
    cout << countsieves(n);

    return 0;
}