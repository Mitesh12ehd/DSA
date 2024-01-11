#include<iostream>
using namespace std;
int main(){
    //this pattern is limited from n = 1 to 9


    int n; 
    cout<<"enter n"<<endl;
    cin>>n;

    for(int i=0; i<n; i++){

        int num_index = 8-i;
        int end_index = i+1; //for raw 1 we want print 1 time only, for raw 2 print 2 time

        for(int j=0; j<17; j++){
            if( j==num_index && end_index>0){
                cout<<i+1;
                num_index = num_index +2;
                end_index--;
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
    return 0;
}