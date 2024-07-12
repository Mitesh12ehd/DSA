#include<iostream>
using namespace std;

int squareRoot(int n){
    int start = 0;
    int end = n;
    long long mid = start + (end-start)/2;
    int ans = -1;

    while(start<=end){
        if(mid*mid == n){
            return mid;
        }
        else if(mid*mid > n){
            //left part
            end = mid-1;
        }
        else{
            ans = mid;
            //right part
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int main(){
    int number;
    cout<<"enter number = ";
    cin>>number;
    int ans = squareRoot(number);
    cout<<"Square Root Integer= "<<ans<<endl<<endl;
    
    //find precesion number
    double finalAns = ans;
    int precision;
    cout<<"enter floating point number you want = ";
    cin>>precision;

    double step = 0.1;
    for(int i=0; i<precision; i++){
        for(double j=finalAns; j*j<=number; j=j+step){
            finalAns = j;
        } 
        step = step / 10;
    }

    cout<<"Square Root = "<<finalAns;
    return 0;
}