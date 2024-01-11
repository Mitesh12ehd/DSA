#include<iostream>
#include<limits.h>
using namespace std;

//Time O(k^n) space O(n)
int numRollsToTarget(int n, int k, int target) {
    //base case 
    if(target < 0){
        return 0;
    }
    if(n == 0 && target == 0){
        return 1;
    }
    if(n == 0 && target != 0){
        return 0;
    }
    if( n != 0 && target == 0){
        return 0;
    }

    int ans = 0;
    for(int i=1; i<=k; i++){
        ans = ans + numRollsToTarget(n-1, k, target-i);
    }
    return ans;
}
int main(){
    cout << numRollsToTarget(2,6,7);
    return 0;
}