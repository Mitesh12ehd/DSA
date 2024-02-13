#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

vector<int> next_Smaller_Element_Index(vector<int> arr){
    vector<int> ans(arr.size());
    stack<int> st;
    st.push(-1);

    for(int i=arr.size()-1; i>=0; i--){
        int curr = arr[i];
        //pop element until we got smaller element than curr at st.top()
        while(st.top() != -1  &&  arr[st.top()] >= curr){
            st.pop();
        }
        // we got smaller element than current in st.top()
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
vector<int> prev_Smaller_Element_index(vector<int> arr){
    vector<int> ans(arr.size());
    stack<int> st;
    st.push(-1);

    for(int i=0; i<arr.size(); i++){
        int curr = arr[i];
        //pop element until we got smaller element than curr at st.top()
        while( st.top() != -1  &&  arr[st.top()] >= curr){
            st.pop();
        }
        // we got smaller element than current in st.top()
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    vector<int> prev = prev_Smaller_Element_index(heights);
    vector<int> next = next_Smaller_Element_Index(heights);

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

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    cout << largestRectangleArea(heights);
    return 0;
}