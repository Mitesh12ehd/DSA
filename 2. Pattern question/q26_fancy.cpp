#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n"<<endl;
    cin>>n;

    //for pascal triangle
    //there is formula
    // C = C * (i-j) / j  where
    //                      i = 1 to n
    //                      j = 1 to i

    for(int i=1; i<=n; i++){
        int C = 1;
        for(int j=1; j<=i; j++){
            cout<<C<<" ";
            C = C * (i-j) / j;
        }
        cout<<endl;
    }
    
    return 0;
}