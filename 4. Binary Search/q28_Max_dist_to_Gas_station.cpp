#include<iostream>
#include<vector>
#include<queue>
#include <cmath>
using namespace std;

//GFG
//Minimize max distance to gas station
//see notes
//this is extreme hard problem
//rare for interviews

/*
------------------------Question explaination-------------------------------
ex. arr[] = {1,2,3,4,5} k=4

1. assume we add at follwing space
    {1,2,3,4,5,6,7,8,9}  max adjacent distance = 1

2. assume we add like this
    {1, 1.25, 1.5, 1.75, 2, 3, 4, 4.5, 5}  max adjacent distance = 1

3. assume we add like this
    {1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5} max adjacent distance = 0.5

so that answer is 0.5
*/

/*
------------------------Approach-------------------------------
1.  if we place new station outside the two boundary of array,
    maximum adjacent distance doesn't affect,
    but we want to reduce it, 
    so it doesn't make sense to place outside two boundaries,
    we place new gas station in between elements of array

2. ex. [1,7]  k=2
    if we place like this [1,2,4,7] max dist = 3
    we need to minimize three distances 1-2, 2-3, 4-7

    we place like [1,3,5,7]
    all distance is 2,
    we need to place so that distance divided in equal sector

*/

//brute force time = O(k*n + n)
double findSmallestMaxDist(vector<int> &stations, int k) {
    int n = stations.size();
    vector<int> howMany(n-1,0);

    //place k gas station
    for(int gasStation=1; gasStation<=k; gasStation++){
        double maxSection = -1;
        int maxIndex = -1;

        //this for loop find interval at new station can be inserted
        for(int i=0; i<n-1; i++){
            double diff = stations[i+1] - stations[i];
            double sectionLength = diff / (howMany[i] + 1);

            if (sectionLength > maxSection) {
                maxSection = sectionLength;
                maxIndex = i;
            }
        }

        //place station
        howMany[maxIndex]++;
    }

    double ans = -1;
    for(int i=0; i<n-1; i++){
        double diff = stations[i+1] - stations[i];
        double sectionLength = diff / (howMany[i] + 1);

        ans = max(ans,sectionLength);
    }
    return ans;
    ans = round(ans*100) / 100;
    return ans;
}

//better time = O(n*logn + k*logn) space = O(n)
double findSmallestMaxDist(vector<int> &stations, int k) {
    int n = stations.size();
    vector<int> howMany(n-1,0);

    priority_queue<pair<double,int>> pq;
    for(int i=0; i<n-1; i++){
        pq.push({stations[i+1] - stations[i], i});
    }

    //place k gas station
    for(int gasStation=1; gasStation<=k; gasStation++){
        int sectionIndex = pq.top().second;
        pq.pop();

        //place station
        howMany[sectionIndex]++;

        double intialLength = stations[sectionIndex+1] - stations[sectionIndex];
        double newSectionLength = intialLength / (double)(howMany[sectionIndex] + 1);
        pq.push({newSectionLength,sectionIndex});
    }

    double ans = pq.top().first;
    ans = round(ans*100) / 100;
    return ans;
}

//optimal time = O(n*logn + n)
int numberOfGasStationsRequired(double dist,vector<int> &stations){
    int count = 0;
    int n = stations.size();

    for(int i=0; i<n-1; i++){
        int numbersInBetween = (stations[i+1] - stations[i]) / dist;

        //check if it perfectly divisable 
        //if it is, then decrease stations can be placed
        if((stations[i+1] - stations[i]) / dist == numbersInBetween * dist){
            numbersInBetween--;
        }

        count = count + numbersInBetween;
    }
    return count;
}
double findSmallestMaxDist(vector<int> &stations, int k) {
    int n = stations.size();
    double start = 0;
    double end = 0;
    for(int i=0; i<n-1; i++){
        end = max(end,(double)stations[i+1]-stations[i]);
    }

    double diff = 1e-6;
    while(end-start > diff){
        double mid = (start+end) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, stations);
        if (cnt > k) {
            start = mid;
        }
        else {
            end = mid;
        }
    }
    
    double ans = end;
    ans = round(ans*100) / 100;
    return ans;
}

int main(){
    return 0;
}