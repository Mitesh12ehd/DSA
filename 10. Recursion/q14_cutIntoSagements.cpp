#include<iostream>
#include<limits.h>
using namespace std;

int solveProblem(int n,int x,int y,int z){
    //base case
    if( n == 0){
        return 0;
    }
    if( n < 0){
        return INT_MIN;
    }

    int ans1 = solveProblem(n-x ,x,y,z) + 1;
    int ans2 = solveProblem(n-y ,x,y,z) + 1;
    int ans3 = solveProblem(n-z ,x,y,z) + 1;

    int ans = max(ans1,max(ans2,ans3));
    return ans;
}
int main(){
    int n = 7;
    int x=5, y=2, z=2;

    //it return maximum number of sagements
    int ans = solveProblem(n,x,y,z);
    if(ans < 0){
        ans = 0;
    }
    cout << ans;
    return 0;
}