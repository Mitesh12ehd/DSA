#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<bool> getSieve(int n){
    vector<bool> sieve(n+1,true);
    sieve[0] = sieve[1] = false;

    for(int i=2; i*i<=n; i++){
        if(sieve[i]){
            int j=i*i;
            while(j<=n){
                sieve[j] = false;
                j = j + i;
            }
        }
    }
    return sieve;
}
vector<bool> segSieve(int L,int R){
    vector<bool> sieve = getSieve(sqrt(R));
    vector<int> basePrimes;
    for(int i=0; i<sieve.size(); i++){
        if(sieve[i]){
            basePrimes.push_back(i);
        }
    }

    vector<bool> segsieve(R-L+1,true);
    if(L==0 || L==1){
        segsieve[L] = false;
    }
    for(int i=0; i<basePrimes.size(); i++){
        int first_mul = (L/basePrimes[i]) * basePrimes[i];
        if(first_mul < L){
            first_mul = first_mul + basePrimes[i];
        }

        int j = max(first_mul , basePrimes[i] * basePrimes[i]);
        while( j <= R){
            segsieve[j - L] = false; //j-L because when 
            j = j + basePrimes[i];
        }
    }
    return segsieve;
}

int main(){
    int L = 110;
    int R = 130;
    vector<bool> temp = segSieve(L,R);
    for(int i=0; i<temp.size(); i++){
        if(temp[i]){
            cout << i + L << " "; 
        }
    }
    
    return 0;
}