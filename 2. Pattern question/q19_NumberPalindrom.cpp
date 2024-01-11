#include<iostream>
using namespace std;
int main(){
    int n;
    cout<< "enter n"<<endl;
    cin>>n;
    int c;
    for(int i=0; i<n; i++){
        c=1;
        for(int j=0; j<n-i-1; j++){
            cout<<" ";
        }

        for(int j=0; j<2*i+1; j++){
            if(j<i+1){
                cout<<c;
                c++;
            }
            else if(j==i+1){
                c = c-2;
                cout<<c;
                c--;
            }
            else{
                cout<<c;
                c--;
            }
        }
        cout<<endl;
    }

    return 0;
}