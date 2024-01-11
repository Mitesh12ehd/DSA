#include<iostream>
#include<cmath>
using namespace std;

int binaryToDecimal(int num){
    int ans = 0;
    int i=0;
    while(num){
        int bit = num % 10;
        ans = ans + bit * pow(2,i);
        num = num/10;
        i++;
    }
    return ans;
}

int main(){
    int num;
    cout<<"enter n"<<endl;
    cin>>num;

    int decimal = binaryToDecimal(num);
    cout<<endl<<"Decimal = "<<decimal;

    return 0;
}