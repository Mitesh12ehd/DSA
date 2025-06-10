#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

// Leetcode 85
// Maximal Rectangle

// we try to memorize the past height using height array
// we use code of largest rectangle in histogram
// we maintain height array for each row and update that
// and we calculate area for each row and take maximum


// time = O(m*n)
// space = O(n)

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = INT_MIN;
    int n = heights.size();

    for(int i=0; i<n; i++){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            int height = st.top();
            st.pop();

            int nextSmallerOfStackTop = i;
            int prevSmallerOfStackTop = (st.empty()) ? -1 : st.top();
            int width = nextSmallerOfStackTop - prevSmallerOfStackTop - 1;

            maxArea = max(maxArea,height*width);
        }
        st.push(i);
    }

    //apply formula on remaining element on stack
    while(!st.empty()){
        int height = st.top();
        st.pop();

        int nextSmallerOfStackTop = n;
        int prevSmallerOfStackTop = (st.empty()) ? -1 : st.top();
        int width = nextSmallerOfStackTop - prevSmallerOfStackTop - 1;

        maxArea = max(maxArea,height*width);
    }

    return maxArea;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    int maxArea = 0;
    vector<int> height(n,0);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == '1'){
                height[j]++;
            }
            else{
                height[j] = 0;
            }
        }
        int area = largestRectangleArea(height);
        maxArea = max(maxArea,area);
    }
    return maxArea;
}

int main(){
    return 0;
}