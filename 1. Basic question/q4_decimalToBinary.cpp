#include<iostream>
#include<cmath>
using namespace std;

// time = O(log 10 base num)

int decimalToBinary(int num){
    int i=0;
    int ans=0;
    while(num>0){

        int bit = num%2;
        ans = bit * pow(10,i) + ans;
        
        num = num / 2;
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