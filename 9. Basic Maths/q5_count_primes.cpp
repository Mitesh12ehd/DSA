#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//leetcode 204 
//count primes

//naive time = O(n*sqrt(n))
bool checkPrime(int n){
    if(n < 2){
        return 0;
    }

    int count = 0;
    for(int i=1; i*i<=n; i++){
        if(n % i == 0){
            count++;
            if(n/i != i){
                count++;
            }
        } 
    }
    if(count == 2){
        return true;
    }
    return false;
}
int countPrimes(int n) {
    int ans = 0;
    for(int i=2; i<n; i++){
        if(checkPrime(i)){
            ans++;
        }
    }
    return ans;
}


//seive of Eratosthenes Time = O(n*loglog n)
int countPrimes(int n) {
    vector<bool> prime(n,true);
    prime[0] = prime[1] = false;

    for(int i=2; i<n; i++){
        if(prime[i]){
            int j = i*2;
            while(j < n){
                prime[j] = false;
                j = j + i;
            }
        }
    }
    //count true marked number
    int ans = 0;
    for(int i=0; i<n; i++){
        if(prime[i]){
            ans++;
        }
    }
    return ans;
}

//intiution 
//ex n=25
//---optimization 1---
//2 -> 4,6,8,10,12,14,16,18,20,22,24
//3 -> 6,9,12,15,18,21,24
//5 -> 10,15,20
//we can notice that each time we have to start with i*i , all element before
//are marked already

//---optimization 2---
//here inner loop says that it start from i*i hence after i=5
//inner loop not run so we can run outer loop till sqrt(i)

//optimized seive of Eratosthenes
int countPrimes(int n) {
    vector<bool> prime(n,true);
    prime[0] = prime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(prime[i]){
            int j = i*i;  //first unmarked number is at i*i,
                          //before i*i are already marked
            while(j < n){
                prime[j] = false;
                j = j + i;
            }
        }
    }
    //count true marked number
    int ans = 0;
    for(int i=0; i<n; i++){
        if(prime[i]){
            ans++;
        }
    }
    return ans;
}

int main(){
    return 0;
}