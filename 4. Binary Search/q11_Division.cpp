#include<iostream>
using namespace std;

int findDivision(int dividend,int divisor){
    int start = 0;
    int end = abs(dividend);
    int mid = start + (end-start)/2;
    int ans = 1;

    while(start <= end){
        if(abs(mid * divisor) == abs(dividend)){
            ans=mid;
            break;
        }
        else if(abs(mid * divisor) > abs(dividend)){
            //left search
            end = mid - 1;
        } 
        else{
            //right search
            ans = mid;
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    if( (divisor<0 && dividend<0) || (divisor>0 && dividend>0)){
        return ans;
    }
    else{
        return -ans;
    }
}
int main(){
    int dividend = -21;
    int divisor = 7;
    int ans = findDivision(dividend,divisor);
    cout<<ans;
    return 0;
}