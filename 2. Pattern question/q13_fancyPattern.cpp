#include<iostream>
using namespace std;
int main(){
    int n;
    cout<< "enter n"<<endl;
    cin>>n;
    // upr vala
    for (int i=0; i<n; i++){
        for(int j=0; j<2*i+1; j++){
            if(j%2 == 0){
                cout<<i+1;
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
    //niche vala
    for (int i=0; i<n; i++){
        for (int j=0; j<(2*n)-(2*i + 1); j++){
            if(j%2 == 0){
                cout<<n-i;
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }

    return 0;
}