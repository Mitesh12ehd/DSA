#include<iostream>
using namespace std;

int fastExpontiation(int x,int n){
    //Time = O(log(n))
    int ans = 1;
    while(x > 0){
        if( x % 2 == 1){
            //n is odd
            ans = ans * x;
        }
        x = x * x;
        x = x / 2;
    }
    return ans;
}

int slowExpontiation(int a,int b){
    //Time = O(b)
    int ans = 1;  
    for(int i=1; i<=b; i++){
        ans = ans * a;
    }
    return ans;
}

int main(){
    cout << slowExpontiation(5,4) << endl;
    cout << fastExpontiation(2,11);

    return 0;
}