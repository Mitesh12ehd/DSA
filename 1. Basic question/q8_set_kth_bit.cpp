#include<iostream>
using namespace std;

int setKthBit(int N, int K){
    int mask = 1 << K;
    cout << "mask = " << mask << endl ;
    int ans = N | mask;
    return ans;
}

int main(){
    int N,k;
    // cout<<"enter N = ";
    // cin>>N;
    // cout<<"enter k = ";
    // cin>>k;
    cout<<setKthBit(10,2);

    return 0;
    
}