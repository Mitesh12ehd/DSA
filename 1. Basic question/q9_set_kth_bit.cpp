#include<iostream>
using namespace std;

int setKthBit(int N, int K){
        int mask = 1 << K;
        int ans = N | mask;
        return ans;
}

int main(){
    int N,k;
    cout<<"enter N = ";
    cin>>N;
    cout<<"enter k = ";
    cin>>k;
    cout<<setKthBit(N,k);

    return 0;
    
}