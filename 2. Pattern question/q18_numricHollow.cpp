#include<iostream>
using namespace std;
int main(){
    int n;
    cout<< "enter n"<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n+1; j++){
            if(i==0 || j == i+1 || j==n){
                cout<<j;
            }
            else{
                cout<<" ";
            } 
        }
        cout<<endl;
    }

    return 0;
}