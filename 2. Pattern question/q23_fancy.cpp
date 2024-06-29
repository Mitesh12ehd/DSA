#include<iostream>
using namespace std;
int main(){
    //this pattern is limited from n = 1 to 9


    int n; 
    cout<<"enter n"<<endl;
    cin>>n;

    //option 1
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

    //option 2
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<8-i; j++){
    //         cout << "*";
    //     }

    //     bool astrick = false;
    //     for(int j=0; j<2*i+1; j++){
    //         if(!astrick){
    //             cout << i;
    //             astrick = true;
    //         }
    //         else{
    //             cout << "*";
    //             astrick = false;
    //         }
    //     }

    //     for(int j=0; j<8-i; j++){
    //         cout << "*";
    //     }

    //     cout << endl;
    // }
    return 0;
}