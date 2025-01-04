#include<iostream>
#include<vector>
using namespace std;

//maximum points you can obtain

//[6,2,3,4,7,2,1,7,1]  k=4
//perform following operation k time
//  pick element from left end or right end and add them in score
//return maximum score you can obtain

//note: it is not suitable that you pick maximum for leftend and rightend beacuse 
//we don't know which element comes after that, and next elment can affect max score you can obtain
//ex. pick 6 , pick 2 , pick 3 , pick 4 gives score = 15
//but maximum score is 6 + 2 + 1 + 7 = 16;

//solution:
//here max score is any one from following option
//first four, first threee and last one, first two and last two, first one and last three,last four
//dry run

int maxScore(vector<int>& arr, int k) {
    int n = arr.size();

    int leftsum = 0;
    int rightsum = 0;
    for(int i=0; i<k; i++){
        leftsum = leftsum + arr[i];
    }

    int ans = leftsum + rightsum;
    int rightIndex = n-1;
    for(int i=k-1; i>=0; i--){
        leftsum = leftsum - arr[i];
        rightsum = rightsum + arr[rightIndex];
        rightIndex--;
        ans = max(ans, leftsum+rightsum);
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,1};
    int k = 3;
    cout << maxScore(arr,k);
    return 0;
}