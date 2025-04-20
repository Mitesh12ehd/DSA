#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Leetcode 42
//Trapping rain water

// see notes

//brute force 
//time = n^2 space = O(1)
int trap(vector<int>& height) {
    int n = height.size();
    int total = 0;
    for(int i=0; i<n; i++){
        int leftMax = 0;

        //why we take j=i not i-1, see notes
        for(int j=i; j>=0; j--){
            leftMax = max(leftMax,height[j]);
        }

        int rightMax = 0; 
        for(int j=i; j<n; j++){
            rightMax = max(rightMax,height[j]);
        }

        total = total + min(leftMax,rightMax) - height[i];
    }
    return total;
}

//better approach
//time = O(3n) space=O(2n)
int trap(vector<int>& height) {
    int n = height.size();

    vector<int> prefixMax(n);
    vector<int> suffixMax(n);

    prefixMax[0] = height[0];
    for (int i = 1; i < n; i++) {
        prefixMax[i] = max(prefixMax[i - 1], height[i]);
    }
    suffixMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffixMax[i] = max(suffixMax[i + 1], height[i]);
    }

    int total = 0;
    for(int i=0; i<n; i++){
        int leftMax = prefixMax[i];
        int rightMax = suffixMax[i];
        total = total + min(leftMax,rightMax) - height[i];
    }
    return total;
}

//optimal approach
//time = O(n) space = O(1)

// ex. when we at left = 2  and right=2
// and height[left] < height[right] 
// then we add water in answer by considering maxLeft
// but then why there is large height than height[right]
// then total calculate wrong because then we have to calculate based on height[right]

// ans it never happens?
// because we move pointer when it is small :) 

int trap(vector<int>& height){
    int n = height.size();
    int left = 0, right = n-1;
    int total = 0;
    int maxLeft = 0, maxRight = 0;

    while(left <= right){
        if(height[left] <= height[right]){
            if(height[left] >= maxLeft){
                //we can't store water
                maxLeft = height[left];
            }
            else{
                //we can store water
                total = total + maxLeft - height[left];
            }
            left++;
        }
        else{
            if(height[right] >= maxRight){
                //we can't store water
                maxRight = height[right];
            }
            else{
                //we can store water
                total = total + maxRight - height[right];
            }
            right--;
        }
    }
    return total;
}

int main(){
    return 0;
}