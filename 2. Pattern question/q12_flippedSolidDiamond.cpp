#include<iostream>
using namespace std;
int main(){
    int n;
    cout<< "enter n"<<endl;
    cin>>n;
    //upr vala part
    for (int i=0; i<n; i++){
        //half pyaramid
        for(int j=0; j<n-i; j++){
            cout<<"*";
        }
        //space full pyramid
        for(int j=0; j<2*i+1; j++){
            cout<<" ";
        }
        // half pyramid 2
        for(int j=0; j<n-i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    //niche vala part
    for(int i=0; i<n; i++){
        //half pyramid
        for (int j=0; j<i+1; j++){
            cout<<"*";
        }
        //space pyramid
        for(int j=0; j<(2*n)-(2*i)-1; j++){
            cout<<" ";
        }
        for (int j=0; j<i+1; j++){
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}