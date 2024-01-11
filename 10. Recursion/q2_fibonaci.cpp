#include<iostream>
using namespace std;

int fibonaci(int n){
    //base condition
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    //recursive approach
    return fibonaci(n-1) + fibonaci(n-2);
}
int main(){
    cout << endl << fibonaci(10);

    return 0;
}