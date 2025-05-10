#include<iostream>
#include<vector>
using namespace std;

//Leetcode 860
//Lemonade change

bool lemonadeChange(vector<int>& bills) {
    int coin_of_5 = 0;
    int coin_of_10 = 0;
    int n = bills.size();

    for(int i=0; i<n; i++){
        if(bills[i] == 5){
            coin_of_5++;
        }
        else if(bills[i] == 10){
            if(coin_of_5 > 0){
                coin_of_5--;
                coin_of_10++;
            }
            else{
                return false;
            }
        }
        else{
            if(coin_of_10 > 0 && coin_of_5 > 0){
                coin_of_10--;
                coin_of_5--;
            }
            else if(coin_of_5 > 2){
                coin_of_5 = coin_of_5 - 3;
            }
            else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    return 0;
}