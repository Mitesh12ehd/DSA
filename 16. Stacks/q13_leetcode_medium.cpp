#include<iostream>
#include<stack>
using namespace std;

//leetcode 1963
//minimum number of swaps to make string balanced

int minSwaps(string s) {
    int ans = 0;
    int extraClose = 0;

    for(auto it:s){
        if(it == '['){
            extraClose--;
        }
        else{
            extraClose++;
            ans = max(ans,extraClose);
        }
    }

    return (ans+1)/2;
}

int main(){
    

    return 0;
}