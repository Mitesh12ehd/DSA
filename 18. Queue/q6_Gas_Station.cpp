#include<iostream>
#include<vector>
using namespace std;

//BRUTE FORCE TIME = O(n^2) SPACE = O(N)
// int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//     int n  = gas.size();
//     for(int starting=0; starting<n; starting++){
//         int filled = 0;

//         int j = starting;
//         bool isPossible = true;

//         //starting point to end of array
//         while(j < n){
//             filled = filled + gas[j];

//             if(filled >= cost[j]){
//                 filled = filled - cost[j];
//             }
//             else{
//                 isPossible = false;
//                 break;
//             }
//             j++;
//         }

//         if(!isPossible){
//             continue;
//         }

//         //0 to starting point-1;
//         j = 0;
//         while(j <= starting-1){
//             filled = filled + gas[j];

//             if(filled >= cost[j]){
//                 filled = filled - cost[j];
//             }
//             else{
//                 isPossible = false;
//                 break;
//             }
//             j++;
//         }


//         if(!isPossible){
//             continue;
//         }else{
//             return starting;
//         }
//     }
//     return -1;
// }
 
//method 3
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int deficit = 0;
    int balance = 0;
    int start = 0;

    for(int i=0; i<gas.size(); i++){
        balance = balance + gas[i] - cost[i];
        if(balance < 0){
            deficit = deficit + abs(balance);
            start = i+1;
            balance = 0;
        }
    }
    if(balance >= deficit){
        return start;
    }
    else{
        return -1;
    }
}
int main(){
    vector<int> gas{1,2,3,4,5};
    vector<int> cost{3,4,5,1,2};
    cout << canCompleteCircuit(gas,cost);
    return 0;
}