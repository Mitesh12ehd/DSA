#include<iostream>
#include<cmath>
using namespace std;

int decimalToBinary(int num){
    int i=0;
    int ans=0;
    while(num>0){

        int bit = num & 1;
        ans = bit * pow(10,i) + ans;
        
        num = num>>1;
        i++;
    }
    return ans;
}

int main(){
    int num;
    cout<<"enter n"<<endl;
    cin>>num;

    int binary = decimalToBinary(num);
    cout<<"Binary = "<<binary;

    return 0;
}