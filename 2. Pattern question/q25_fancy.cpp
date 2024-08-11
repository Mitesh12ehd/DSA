#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n"<<endl;
    cin>>n;

    // for(int i=0; i<n; i++){

    //     cout<<"*";
        
    //     int cond = (i <= n/2) ? (2*i) : (2*(n-i-1)) ;
    //     for(int j=0; j<=cond; j++){
    //         if(j<=cond/2){
    //             cout<<j+1;
    //         }
    //         else{
    //             cout<<cond-j+1;
    //         }
            
    //         //extra astric
    //         if(j == cond){
    //             cout<<"*";
    //         }
    //     }
    //     cout<<endl;
    // }

    //better option
    int j_limit = 1;
    for(int i=0; i<n; i++){
        cout << "*";

        int var = 1;
        for(int j=0; j<j_limit; j++){
            cout << var;

            if(j <= (j_limit / 2) - 1){
                var++;
            }
            else{
                var--;
            }
        }
        if(i <= n/2 - 1){
            j_limit = j_limit + 2;
        }
        else{
            j_limit = j_limit - 2;
        }

        cout << "*";
        cout << endl;
    }

    return 0;
}