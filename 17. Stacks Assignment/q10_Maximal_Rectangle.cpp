#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

//Leetcode 85
//Maximal rectangle

//see notes

// time = O(m*n) + O(n* 2m)
// space = O(n*m) + O(n)

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = INT_MIN;
    int n = heights.size();

    for(int i=0; i<n; i++){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            int height = heights[st.top()];
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
        int height = heights[st.top()];
        st.pop();

        int nextSmallerOfStackTop = n;
        int prevSmallerOfStackTop = (st.empty()) ? -1 : st.top();
        int width = nextSmallerOfStackTop - prevSmallerOfStackTop - 1;

        maxArea = max(maxArea,height*width);
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    //convert char vector into int vector
    vector<vector<int>> v;
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0; i<n; i++){
        vector<int> t;
        for(int j=0; j<m; j++){
            t.push_back(matrix[i][j]-'0');
        }
        v.push_back(t);
    }

    int area = largestRectangleArea(v[0]);
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            //sum of rows
            if(v[i][j]){
                v[i][j] = v[i][j] + v[i-1][j];
            }
            else{
                v[i][j] = 0;
            }
        }
        area = max(area,largestRectangleArea(v[i]));
    }
    return area;
}

int main(){
    vector<vector<char>> matrix = {
            {'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','0','1','0'}};

    cout << maximalRectangle(matrix);
    return 0;
}