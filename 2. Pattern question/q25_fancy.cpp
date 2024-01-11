#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n"<<endl;
    cin>>n;

    for(int i=0; i<n; i++){

        cout<<"*";
        
        int cond = (i <= n/2) ? (2*i) : (2*(n-i-1)) ;
            for(int j=0; j<=cond; j++){
                if(j<=cond/2){
                    cout<<j+1;
                }
                else{
                    cout<<cond-j+1;
                }


                //extra astric
                if(j == cond){
                    cout<<"*";
                }
            }
        cout<<endl;
    }


    return 0;
}