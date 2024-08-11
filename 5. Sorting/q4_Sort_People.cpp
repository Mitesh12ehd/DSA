#include<iostream>
#include<vector>
using namespace std;

vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    int n = names.size();
    for(int i=0; i<n; i++){
        int maxi = heights[i];
        int maximumIndex = i;
        for(int j=i+1; j<n; j++){
            if(heights[j] > maxi){
                maxi = heights[j];
                maximumIndex = j;
            }
        }

        swap(names[i],names[maximumIndex]);
        swap(heights[i],heights[maximumIndex]);
    }

    return names;
}

int main(){
    

    return 0;
}