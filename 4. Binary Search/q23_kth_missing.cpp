#include<iostream>
#include<vector>
using namespace std;

//brute force
// ex. arr = [5,7,10,12] k=4
//      we can say 4th missing is 4
// if k = 6 for same array
//        1,2,3,4,    5    ,6,....
//so here we add 1 in k to find out kth missing number

//time = O(n)
int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    for(int i=0; i<n; i++){
        if(arr[i] <= k){
            k++;
        }
        else{
            break;
        }
    }
    return k;
}

//intitution :
//here we can't apply normal binary search 
//because missinig element not present in array
//or we can't apply on answer like search space because here no minimum maximum

//we find range where answer can lie
//ideally each element at ith index = i+1;
//ex. [2,3,4,7,11] k = 5
// at 7 there should be 4 hence there is three number missing
// at 11 there should be 5 hence there is six number missing

//we perform usual binary search
//at the end of binary search 
//high=3, low=4

//edge case
//when arr[] = [4,7,9]  k=3
//here after binary search low=0, high=-1

//now after binary search find formula for answer
//at high missing number = arr[high] - (high+1)
//how many more need to find answer = k - missing

//answer = arr[high] + more needed
//       = arr[high] + k - missing 
//       = arr[high] + k - arr[high] + high + 1
//answer = k + high + 1

//dryrun on first case to understand

int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    
    int start = 0;
    int end = n-1;
    while(start<=end){
        int mid = (start+end) / 2;
        int missing = arr[mid] - (mid+1);

        if(missing < k){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }

    return k + end + 1;
}


int main(){
    return 0;
}