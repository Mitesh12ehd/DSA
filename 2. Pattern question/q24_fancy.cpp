#include<iostream>
using namespace std;
int main(){
    
    int n; 
    cout<<"enter n"<<endl;
    cin>>n;

    //PART 1
    int var = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout<<var;
            var++;
            
            if(j<i){
                cout<<"*";
            }
        }
        cout<<endl;
    }

    //PART 2
    //now var value is 16 cheked by console log
    int start = var - n;
    for(int i=0; i<n; i++){
        int var2 = start;
        for(int j=0; j<n-i; j++){
            cout<<var2;
            var2++;

            if(j<n-i-1){
                cout<<"*";
            }
        }
        start = start-n+i+1; //here i==0 so that we have add 1 extra
        cout<<endl;
    }

    //easy option 
    // int var = 1;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<2*i+1; j++){
    //         if(j % 2 != 0){
    //             cout  << "*";
    //         }
    //         else{
    //             cout <<var++;
    //         }
    //     }
    //     cout << endl;
    // }

    // int start = var - n;
    // for(int i=0; i<n; i++){
    //     int var2 = start;
    //     for(int j=0; j<2*(n-i)-1; j++){
    //         if(j % 2 != 0){
    //             cout  << "*";
    //         }
    //         else{
    //             cout << var2;
    //             var2 ++;
    //         }
    //     }
    //     start = start - n+i+1;
    //     cout << endl;
    // }

    return 0;
}