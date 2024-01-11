#include<iostream>
using namespace std;
int main(){
    
    int n;
    cout<< "enter n"<<endl;
    cin>>n;
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if( i==n-1 || j==0 || i==j){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    //numric
    // int n;
    // cout<< "enter n"<<endl;
    // cin>>n;
    // for (int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         if( i==n-1 || j==0 || i==j){
    //             cout<<j+1;
    //         }
    //         else{
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }

    return 0;
}