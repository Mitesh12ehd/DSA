#include<iostream>
using namespace std;
int main(){
    int n;
    cout<< "enter n"<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        int j;
        for(j=0; j<i+1; j++){
            cout<<j+1;
        }
        j = j-1;
        //revere counting printing
        for( ; j>0; j--){
            cout<<j;
        }
        cout<<endl;
    }

    return 0;
}