#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//GFG
//Minimum platforms 

// we can sort based on arrival and departure time

// ex. arr[] = [900, 940, 950, 1100, 1500, 1800], 
//     dep[] = [910, 1200, 1120, 1130, 1900, 2000]

//     (900,A),(910,D),(940,A),(950,A),(1100,A),(1120,D),
//         (1130,D),(1500,A),(1800,A),(1900,D),(2000,D)

//     count of train at station = 0,1,0,1,2,3,2,1,2,2,1,0
//     maximum train at station can be 3
//     so that we need 3 station

// here, we no need make pair (time, A/D)
// we can sort both array and and use two pointer
//         (similar two merge two sorted array)

//time = O(2 * (nlogn + n))
//space = O(1)

int findPlatform(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();

    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int maxTrain = 0;
    int count = 0;
    int i=0,j=0;

    while(i<n && j<n){
        if(arr[i] <= dep[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        maxTrain = max(maxTrain,count);
    }
    return maxTrain;
}

int main(){
    return 0;
}