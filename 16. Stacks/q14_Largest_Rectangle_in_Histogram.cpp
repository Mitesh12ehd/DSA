#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

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

//intitution:
//1. extend left untill we got smaller element
//2. extend right untill we got smaller element

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