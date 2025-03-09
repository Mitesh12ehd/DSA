#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//leetcode 1482
//Minimum number of days to make m bouquets

//bloomday = [7,7,7,7,13,11,12,7]  m=2  k=3
//ex. on 13th day all the flowers is bloomed
//            we can pick any two set 
//            each set have 3 continoues bloomed flowers
//            success : we can make two set which have continues set
//            store ans = 13
//ex. on 12th day all flowers bloomed except 13
//            again here we can make two set
//            success : we can make 2 sets
//            store and = 12;
//ex. on 11th day all flowers bloomed except 13,12
//            here we can't two set such that each set have 3 continoues flowers
//so final answer is 12

bool possible(vector<int>& bloomDay,int day,int m,int k){
    int bouqueCount = 0;
    int count = 0; //denote  continueous flower count

    for(int i=0; i<bloomDay.size(); i++){
        if(bloomDay[i] < day){
            count++;
        }
        else{
            bouqueCount = bouqueCount + (count / k);
            count = 0;
        }
    }
    //to check after last index of array
    bouqueCount = bouqueCount + (count / k); 
    return bouqueCount >= m;
}

//brute force time = (maxi-mini+1) * n
int minDays(vector<int>& bloomDay, int m, int k) {
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(auto it:bloomDay){
        mini = min(mini,it);
        maxi = max(maxi,it);
    }
    for(int i=mini; i<=maxi; i++){
        if(possible(bloomDay,i,m,k)){
            return i;
        }
    }
    return -1;
}

//optimal time = log(maxi-mini+1) * n
int minDays(vector<int>& bloomDay, int m, int k) {
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(auto it:bloomDay){
        mini = min(mini,it);
        maxi = max(maxi,it);
    }
    
    int start = mini;
    int end = maxi;
    int ans = INT_MAX;
    while(start <= end){
        int mid = (start+end)/2;
        if(possible(bloomDay,mid,m,k)){
            ans = min(ans,mid);
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}

int main(){
    return 0;
}