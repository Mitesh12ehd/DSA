#include<iostream>
#include<vector>
using namespace std;

//Leetcode 1922
//Count good numbers

//brute force 5^n using recursion
//5 call per call
//depth of tree  = n
int MOD = 1e9 + 7;
void helper(long long i,long long& n,int& ans){
    if(i == n){
        ans = (ans+1) % MOD;
        return;
    }

    if(i % 2 == 0){
        //even index
        for(int it=0; it<=8; it=it+2){
            //put even number at even index 
            //hypothetically put numbers because no need to store string :)
            helper(i+1,n,ans);
        }
    }
    else{
        //put prime number at odd index
        helper(i+1,n,ans); //2
        helper(i+1,n,ans); //3
        helper(i+1,n,ans); //5
        helper(i+1,n,ans); //7
    }
}
int countGoodNumbers(long long n) {
    int ans = 0;
    long long i=0;
    helper(i,n,ans);
    return ans;
}

//better way = O(n)
//using math permutation ans combination
int countGoodNumbers(long long n) {
    long long ans = 1;
    for(int i=0; i<n; i++){
        if(i%2 == 0){
            ans = ans * 5;
            ans = ans % MOD;
        }
        else{
            ans = ans * 4;
            ans = ans % MOD;
        }
    }
    int finalAns = ans % MOD;
    return finalAns;
}

//optimal log(n)
long long fast_expontiation(int x, long long n) {
    long long pow = n;
    long long ans = 1;
    while(pow > 0){
        if(pow % 2 == 1){
            //n is odd
            ans = (ans * x) % MOD;
            pow--;
        }
        x = (x * x) % MOD;
        pow = pow / 2;
    }
    return ans;
}
int countGoodNumbers(long long n) {
    long long evenPositionCount = (n+1)/2;
    long long oddPositionCount = n/2;

    int ans = ((fast_expontiation(5, evenPositionCount) % MOD) 
                * (fast_expontiation(4, oddPositionCount) % MOD)) % MOD;
    return ans;
}

void helper(int i,int num,string str,vector<string>& ans){
    if(i==num){
        ans.push_back(str);
        return;
    }

    helper(i+1,num,str+"0",ans); //put 0 at i
    if((i==0) || (i != 0 && str[i-1] != '1')){
        helper(i+1,num,str+"1",ans); //put 1 at i
    }
}
vector<string> generateBinaryStrings(int num){
    vector<string> ans;
    int i = 0;
    string str = "";
    helper(i,num,str,ans);
    return ans;
}

int main(){
    cout << countGoodNumbers(50);
    return 0;
}