#include<iostream>
using namespace std;

int factorial(int n){
    //base condition
    if(n == 1){
        return 1;
    }
    //recursive approach
    return n * factorial(n-1);
}
int main(){
    cout << factorial(5);
    return 0;
}