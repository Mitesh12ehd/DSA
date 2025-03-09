#include<iostream>
#include<cmath>
using namespace std;

//print all factors

//time = O(n)
// void print_divisors(int n) {
//     for(int i=1; i<n; i++){
//         if(n % i == 0){
//             cout << i <<" ";
//         }
//     }
// }

//ex n=36
// if one divisor is 1 then other divisor is n/1 = 36/1 = 36
// if one divisor is 2 then other divisor is n/2 = 36/2 = 18
// if one divisor is 3 then other divisor is n/3 = 36/3 = 12
// if one divisor is 4 then other divisor is n/4 = 36/4 = 9
// if one divisor is 6 then other divisor is n/6 = 36/6 = 6

// if one divisor is 9 then other divisor is n/9 = 36/9 = 4
// if one divisor is 12 then other divisor is n/12 = 36/12 = 3
// if one divisor is 18 then other divisor is n/18 = 36/18 = 2
// if one divisor is 36 then other divisor is n/36 = 36/36 = 1

//observation
//in intial iterration first number is smaller than second number
//then it become equal (not mandotary) ex 6 * 6
//after first number is greater than second number

//beyond squareroot(n) number will grow

//time = O(squareroot(n))
void print_divisors(int n) {
    for(int i=1; i*i<=n; i++){
        if(n % i == 0){
            cout << i << " ";
            if(n / i != i){
                cout << n/i << " ";
            }
        }
    }
}

int main(){
    print_divisors(36);

    return 0;
}