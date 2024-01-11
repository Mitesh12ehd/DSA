#include<iostream>
using namespace std;
int main(){
    
    int n;
    cout<<"enter n"<<endl;
    cin>>n;

    int m;
    int x;
    for(int i=0; i<n; i++){
        //space
        for(int j=0; j<n-i; j++){
            cout<<" ";
        }

        //number
        m = i+1;
        for(int j=0; j<i+1; j++){
            cout<<m;
            m++;
        }

        //number reverse
        x=i*2;
        for(int j=0; j<i; j++){
            cout<<x;
            x--;
        }
        cout<<endl;
    }
    return 0;
}