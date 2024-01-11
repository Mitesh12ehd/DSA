#include<iostream>
using namespace std;
int main(){  
    int n;
    cout<< "enter number" <<endl;
    cin>>n;
    bool flag = true;
    for(int i=2; i<n;i++){
        if(n%i == 0){
            flag = false;
            break;
        }
    }
    if(flag){
        cout<<endl<<"number is prime";
    }
    else{
        cout<<"number is not prime";
    }
    
    return 0;
}