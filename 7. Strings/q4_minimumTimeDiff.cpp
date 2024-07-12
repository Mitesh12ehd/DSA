#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

// time = O(nlogn) , space = O(n)
int findMinDifference(vector<string>& timePoints) {
    vector<int> minutesArray;
    for(int i=0; i<timePoints.size(); i++){
        string curr = timePoints[i];

        int hour = stoi( curr.substr(0,2) );
        int minute = stoi( curr.substr(3,2) );
        int totalminutes = hour*60 + minute;
        minutesArray.push_back(totalminutes);
    }
    sort(minutesArray.begin(),minutesArray.end());

    int mini = INT_MAX;
    for(int i=0; i<minutesArray.size()-1; i++){
        int diff = minutesArray[i+1] - minutesArray[i];
        mini = min(mini , diff); 
    }

    //explicit case
    int lastDiff = (minutesArray[0] + 1440) - minutesArray[minutesArray.size()-1];
    mini = min(mini , lastDiff);
    return mini;
}
int main(){
    vector<string> arr{"12:10","10:15","13:15","17:20","18:00","19:47","23:59"};
    int ans = findMinDifference(arr);
    // cout<<ans;

    return 0;
}