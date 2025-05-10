#include<iostream>
#include<vector>
using namespace std;

//Leetcode 135
//Candy

// brute force
// here first, we try to satisfy condition by considering left child
//     i.e assign 1 candy more to the current than left if rating of curr > left
//         else assign 1 candy to has_trivial_default_constructor
// similar, we try to satisfy condition by considering right child and iterating from
//          behind
//     i.e assign 1 candy more to the current than right if rating of curr > right
//         else assign 1 candy to curr

// take max of both to find out number of candies each child got
// ex. arr = {0,2,4,3,2,1,1,3,5,6,4,0,0}
//    left = {1,2,3,1,1,1,1,2,3,4,1,1,1}
//   right = {1,2,4,3,2,1,1,2,3,4,2,1,1}
//     max = {1,2,4,3,2,1,1,2,3,4,2,1,1}

//time = O(3n)
//space = O(2n)
int candy(vector<int>& ratings) {
    int n = ratings.size();

    vector<int> left(n,0);
    vector<int> right(n,0);
    left[0] = 1;
    right[n-1] = 1;

    for(int i=1; i<n; i++){
        if(ratings[i] > ratings[i-1]){
            left[i] = left[i-1] + 1;
        }
        else{
            left[i] = 1;
        }
    }
    for(int i=n-2; i>=0; i--){
        if(ratings[i] > ratings[i+1]){
            right[i] = right[i+1] + 1;
        }
        else{
            right[i] = 1;
        }
    }
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += max(left[i],right[i]);
    }
    return sum;
}

//slightly better approach
//store only left and find right and calculate candy at that place directly
//time = O(2n)
//space = O(n)
int candy(vector<int>& ratings) {
    int n = ratings.size();

    vector<int> left(n,0);
    left[0] = 1;

    for(int i=1; i<n; i++){
        if(ratings[i] > ratings[i-1]){
            left[i] = left[i-1] + 1;
        }
        else{
            left[i] = 1;
        }
    }
    
    int sum = 0;
    int curr = 1;
    sum += max(curr,left[n-1]);
    for(int i=n-2; i>=0; i--){
        int candyRight;
        if(ratings[i] > ratings[i+1]){
            candyRight = curr+1;
        }
        else{
            candyRight = 1;
        }
        curr = candyRight;
        sum += max(curr,left[i]);
    }
    return sum;
}

//most optimal approach see notes
//dryrun to understand
int candy(vector<int>& ratings) {
    int n = ratings.size();

    int sum = 1;
    int i=1;
    while(i < n){
        if(ratings[i] == ratings[i-1]){
            sum += 1;
            i++;
        }
        else{
            //increasing slop
            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]){
                peak++;
                sum += peak;
                i++;
            }

            //decreasing slop
            int down = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                down++;
                sum += down;
                i++;
            }
            
            down++;
            if(down > peak){
                sum = sum - peak + down;
            }
        }
    }

    return sum;
}

int main(){
    return 0;
}