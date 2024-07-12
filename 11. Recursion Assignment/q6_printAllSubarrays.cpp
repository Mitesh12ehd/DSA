#include<iostream>
#include<vector>
using namespace std;

void printAll(vector<int> arr){
    int i = 0;
    while(i < arr.size()){
        int j = i;
        while(j < arr.size()){
            for(int m=i; m<=j; m++){
                cout<< arr[m] << " ";
            }
            cout << endl;
            j++;
        }
        i++;
    }
}

// Time O(n^2) , Space O(n) 
void printAllSubarrays(vector<int>& arr,int start,int end){
    //base case
    if(end == arr.size()){
        return;
    }

    //solve one case
    for(int i=start; i<= end; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    //recursive call
    printAllSubarrays(arr,start, end+1);
}
int main(){
    vector<int> arr{1,2,3,4,5};
    int start = 0;
    

    for(int start=0; start<arr.size(); start++){
        int end = start;
        printAllSubarrays(arr,start,end);  
    }
    return 0;
}