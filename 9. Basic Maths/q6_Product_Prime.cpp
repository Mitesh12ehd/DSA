#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isPrime(long long i){
    if(i <= 1){
        return false;
    }
    long long sqrtN = sqrt(i);
    for(long long m=2; m<=sqrtN; m++){
        if(i%m == 0){
            return false;
        }
    }
    return true;
}
    
long long primeProduct(long long L, long long R){
    long long i;
    vector<long long> vec;
    for(i=L; i<=R; i++){
        if(isPrime(i)){
            vec.push_back(i);
        }
    }
    long long ans = 1;
    for(auto it:vec){
        ans = (ans * it) % 1000000007;
    }
    return ans;
}

int main(){
    //question on gfg
    long long L = 1;
    long long R = 10;
    cout << primeProduct(L,R);

    return 0;
}