#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Leetcode 1504
// Count Submatrices With All Ones
// Important problem

/*
Approach 1: time = O(m^2 * n) space = O(n)

First what if we have only 1D array
[1,0,1,1,1,0]
ans = 1 + 1 + 2 + 3 = 7
we are taking consecutive ones count for each 1

Now extend problem for 2D matrix
[1,0,1]
[1,1,0]

- here we can find for each row again, but we also need to find for combining
  both row.
- here combined matrix count = 1
- because [1] there is only one set of consecutive ones in all row
          [1]

- if we have [1,1,0]
             [1,1,0]
             [1,1,0]
- then first we find for 
    1. for first row = 3
    2. then combining first and second row = 3 (because there is consecutive 1 two times in both row)
                (assume like there is 1D array {1,1} then our answer is 3)

    3. then combining first,second and third row = 3
    
    4. for second row = 3
    5. combining second and third row = 3
    
    6. for third row = 3

    total = 3 + 2 + 2 + 3 + 2 + 3 = 15

- hence we need startRow and endRow concept and we combining all ones in 1D array
    best way to do that is bitwise AND
- and after creating 1D array, we can easily find out answer for 1D array
*/


int oneDimArrayAns(vector<int>& v){
    int ans = 0;

    int count = 0;
    for(auto it:v){
        if(it == 0){
            count = 0;
        }
        else{
            count++;
        }
        ans = ans + count;
    }
    return ans;
}
int numSubmat(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    int ans = 0;
    
    for(int startRow=0; startRow<m; startRow++){
        vector<int> oneDim(n,1); // initialize with 1 because we are taking &
        for(int endRow=startRow; endRow<m; endRow++){
            for(int col=0; col<n; col++){
                oneDim[col] = oneDim[col] & mat[endRow][col]; 
            }
            ans = ans + oneDimArrayAns(oneDim); 
        }
    }
    return ans;
}

/*
Approach 2:

    [1,0,1]
    [1,1,0]
    [1,1,0]

- we try to find each submatrix with all ones that are ending(bottom-right) at current 1
- likewise we checking for all 1 in matrix

- let's write count of submatrix end at each ones
    [1,0,1]
    [2,2,0]     TOTAL = 13
    [3,4,0]

- but how we can find ?
- we can use height concept
- let's write height of ones, and now we need to just find ans for each row.
    [1,0,1]
    [2,1,0]
    [3,2,0]

now for each position count of submatrix that end at current position
    = height * gap 
        where gap = current index - prev smaller index

- let's understand by single array
- if we have height of 2nd row is [1,2,3,2,1]
        [0,0,1,0,0]
        [0,1,1,1,0]
        [1,1,1,1,1]

    for first element count = 1
    for second element count = (height * gap == 2 * 1) + ans[0] =  3
    for third element count = (height * gap == 2 * 1) + ans[1] =  6
    for fourth element count = (height * gap == 3 * 3) + ans[0] =  6
    for fifth element count = (height * gap == 1 * 5) =  5

- so that conclusion is 
    count of matrix that ends(bottom-right) for each element 
        = (height * gap) + count[prev_smaller_index]
*/

vector<int> findPrevSmaller(vector<int>& arr){
    int n = arr.size();

    vector<int> ans(n,-1);
    stack<int> st;

    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        if(!st.empty()){
            ans[i] = st.top();
        }
        
        st.push(i);
    }
    return ans;
}
int countRectangles(vector<int>& arr){
    int n = arr.size();

    int ans = 0;
    vector<int> count(n,0);
    vector<int> prevSmaller = findPrevSmaller(arr);

    for(int i=0; i<n; i++){
        int prevSmallerIndex = prevSmaller[i];
        
        // find gap
        int gap = i - prevSmaller[i];

        // find height 
        int height = arr[i];

        count[i] = (gap * height) + (prevSmallerIndex != -1 ? count[prevSmallerIndex] : 0);
        ans = ans + count[i];
    }
    return ans;
}
int numSubmat(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    int ans = 0;
    vector<int> height(n,0);

    for(int i=0; i<m; i++){

        // count height
        for(int j=0; j<n; j++){
            if(mat[i][j] == 0){
                height[j] = 0;
            }
            else{
                height[j]++;
            }
        }

        // now for each element in row, count rectangle that end at current element
        ans = ans + countRectangles(height);
    }
    return ans;
}

int main(){
    return 0;
}