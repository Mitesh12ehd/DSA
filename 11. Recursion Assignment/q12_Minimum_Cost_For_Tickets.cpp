#include<iostream>
#include<vector>
using namespace std;

//Time O(3^n) , Space O(n) , n = size of days array
int mincostTickets_Helper(vector<int>& days, vector<int>& costs, int i){
    //base case
    if( i >= days.size()){
        return 0;
    }

    //solve one case
    //1 day pass
    int cost1 = costs[0] + mincostTickets_Helper(days, costs, i+1);
    //7 day pass
    int passEndday = days[i] + 6;
    int j = i;
    while(j < days.size() && days[j] <= passEndday){
        j++;
    }
    int cost7 = costs[1] + mincostTickets_Helper(days,costs, j);
    //30 day pass
    passEndday = days[i] + 29;
    j = i;
    while(j < days.size() && days[j] <= passEndday){
        j++;
    }
    int cost30 = costs[2] + mincostTickets_Helper(days,costs, j);

    return min(cost1,min(cost7,cost30));
}
int mincostTickets(vector<int>& days, vector<int>& costs) {
    int i = 0;
    return mincostTickets_Helper(days,costs,i);
}
int main(){
    //leetcode 983
    vector<int> days{2,5};
    vector<int> costs{1,4,15};
    cout << mincostTickets(days,costs);
    return 0;
}