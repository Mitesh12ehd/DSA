#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n"<<endl;
    cin>>n;

    for(int i=0; i<n; i++){
        //space
        for(int j=0; j<n-i-1; j++){
            cout<<" ";
        }

        int m = 1;
        //number pyramid
        for(int j=0; j<2*i+1; j++){
            //first raw
            if(i==0){
                cout<<i+1;
            }
            //last raw
            else if(i==n-1){
                if(j%2 == 0){
                    cout<<m;
                    m++;
                }
                else{
                    cout<<" ";
                }
            }
            //first column
            else if(j==0){
                cout<<j+1;
            }
            //last column
            else if(j==2*i){
                cout<<i+1;
            }
            //space
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}