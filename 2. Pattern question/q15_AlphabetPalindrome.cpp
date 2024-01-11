#include<iostream>
using namespace std;
int main(){
    int n;
    cout<< "enter n"<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        int j;
        for(j=0; j<i+1; j++){
            char ch = 'A' + j;
            cout<<ch;
        }
        j=j-1;
        //revere counting printing
        for( ; j>0; j--){
            char ch = 'A'+j-1;
            cout<<ch;
        }
        cout<<endl;
    }

    return 0;
}