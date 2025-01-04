#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int countsieves(int n){
    //method 3 Sieve of Eratosthenes Time = O(n*loglog n)
    // if(n == 0){
    //     return 0;
    // }

    // vector<bool> sieve(n,true);
    // sieve[0] = sieve[1] = false;

    // for(int i=2; i<n; i++){
    //     if(sieve[i]){
    //         int j = i*2;
    //         while(j < n){
    //             sieve[j] = false;
    //             j = j + i;
    //         }
    //     }
    // }
    // //count true marked number
    // int ans = 0;
    // for(int i=0; i<n; i++){
    //     if(sieve[i]){
    //         ans++;
    //     }
    // }
    // return ans;


    // method 4 --optimized Sieve of eratothenes
    //intiution ex n=25
    //---optimization 1---
    //2 -> 4,6,8,10,12,14,16,18,20,22,24
    //3 -> 6,9,12,15,18,21,24
    //5 -> 10,15,20
    //we can notice that each time we have to start with i*i , all element before
    //are marked already

    //---optimization 2---
    //here inner loop says that it start from i*i hence after i=5
    //inner loop not run so we can run outer loop till sqrt(i) 
    if(n == 0){
        return 0;
    }
    vector<bool> sieve(n,true);//all are marked sieve
    sieve[0] = sieve[1] = false;

    for(int i=2; i*i<=n; i++){
        if(sieve[i]){
            int j=i*i; //first unmarked number is at i*i,
                        //before i*i are already marked
            while(j<n){
                sieve[j] = false;
                j = j + i;
            }
        }
    }

    //count prime
    int count = 0;
    for(int i=0; i<n; i++){
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