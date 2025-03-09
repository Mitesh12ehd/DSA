#include<iostream>
#include<climits>
using namespace std;

//INT_MIN = -2147483648
//INT_MAX = 2147483647

int reverse(int x) {
    int ans = 0;
    bool isNeg = false;
    if(x==INT_MIN){
        //because if it becomes positive it exceed INT_MAX
        return 0;
        
    }
    if(x<0){
        isNeg = true;
        x = -x;
    }
    while(x>0){
        if(ans > INT_MAX / 10){
            return 0;
        }
        int digit = x % 10;
        ans = ans * 10 + digit;
        x = x / 10;
    }
    return isNeg ? -ans : ans;
}

//easy option
// int reverseInterger(int num){
//     int ans = 0;

//     while(num){
//         int lastbit = num % 10;
//         ans = (ans * 10) + lastbit;
//         num = num / 10;
//     }
//     return ans;
// }

int main(){
    cout<<"Hello"<<endl;

    int var = reverse(-123);
    cout<<"ans is = "<<var;

    return 0;
}