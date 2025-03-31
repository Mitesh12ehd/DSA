#include<iostream>
using namespace std;

//leetcode 50
//Pow x,n

//what if n is nagative
//ex 5 ^ -2  == 1/25  
//divide 1 by answer	

int fastExpontiation(int x,int n){
    //Time = O(log(n))
    int ans = 1;
    while(n > 0){
        if(n % 2 == 1){
            //n is odd
            ans = ans * x;
            n--;
        }
        x = x * x;
        n = n / 2;
    }
    return ans;
}

//time = O(n)
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