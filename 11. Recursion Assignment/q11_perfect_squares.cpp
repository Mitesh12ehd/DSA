#include<iostream>
#include<limits.h>
#include<cmath>
using namespace std;

//Time O(n^n), Space O(n)
int numSquares(int n) {
    //base case
    if(n <= 0){
        return 0;
    }
    
    int ans = INT_MAX;
    int i = 1;
    while(i*i <= n){
        int perfectSquare = i*i;
        int numberOfPerfectSquare = 1 + numSquares(n - perfectSquare);
        ans = min(ans,numberOfPerfectSquare);
        i++;
    }
    return ans;
}
int main(){
    int n = 12;
    cout << numSquares(n);

    return 0;
}