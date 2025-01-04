#include<iostream>
using namespace std;

//google
int DivisorSum(int n,int a,int b){
    int ans = 0;
    for(int i=1; i<=n; i++){
        if((i%a == 0) || (i%b == 0)){
            ans = ans + i;
        }
    }
    return ans;
}

int DivisorSum(int n,int a,int b){
    //ans = (divisable by a) + (divisable by b) - (divisable by LCM(a,b))
    //                                              //divisable by both 

    
}

int main(){
    int n = 20;
    int a = 4;
    int b = 6;
    cout << DivisorSum(n,a,b);

    return 0;
}