#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

//see notes

//brute force time=O(n^2) space=O(n)
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int ans = INT_MIN;

    for(int i=0; i<n; i++){
        //extend left
        int count = 0;
        for(int j=i-1; j>=0; j--){
            if(heights[j] >= heights[i]){
                count++;
            }
            if(heights[j] < heights[i]){
                break;
            }
        }

        //extend right
        for(int j=i; j<n; j++){
            if(heights[j] >= heights[i]){
                count++;
            }
            if(heights[j] < heights[i]){
                break;
            }
        }

        int area = heights[i] * count;
        ans = max(ans,area);
    }
    return ans;
}

//better approach
//here with we store index of next smaller and previous smaller element
vector<int> nextSmaller(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;

    for(int i=n-1; i>=0; i--){
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
vector<int> prevSmaller(vector<int>& arr){
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

//intitution:
//1. extend left untill we got smaller element
//2. extend right untill we got smaller element

int largestRectangleArea(vector<int>& heights) {
    vector<int> prev = prevSmaller(heights);
    vector<int> next = nextSmaller(heights);

    int maxArea = INT_MIN;

    for(int i=0; i<heights.size(); i++){
        if(next[i] == -1){
            next[i] = heights.size();
        }

        int length = heights[i];
        int width = next[i] - prev[i] - 1;
        int area = length * width;

        maxArea = max(maxArea,area);
    }
    return maxArea;
}

//most optimal appraoch
//time = O(2n) space = O(n)
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
        int height = st.top();
        st.pop();

        int nextSmallerOfStackTop = n;
        int prevSmallerOfStackTop = (st.empty()) ? -1 : st.top();
        int width = nextSmallerOfStackTop - prevSmallerOfStackTop - 1;

        maxArea = max(maxArea,height*width);
    }

    return maxArea;
}

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    cout << largestRectangleArea(heights);
    return 0;
}