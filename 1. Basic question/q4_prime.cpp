#include<iostream>
using namespace std;

void printPrime(int n){
    for(int i=2; i<=n; i++){
        bool flag = true;
        for(int m=2; m<i;m++){
            if(i%m == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<i<<" ";
        }
    }
}

int main(){
    int n;
    cout<<"enter n" <<endl;
    cin>>n;

    printPrime(n);

    return 0;
}