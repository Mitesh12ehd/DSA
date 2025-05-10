#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//see notes

//time = O(nlogn)
//space = O(1)
int findWaitTimeSJF(vector<int>& brustTime){
    int n = brustTime.size();

    sort(brustTime.begin(),brustTime.end());
    int wait = 0;
    int time = 0;
    for(int i=0; i<n; i++){
        wait = wait + time;
        time = time + brustTime[i];
    }   
    return wait/n;
}

int main(){
    return 0;
}