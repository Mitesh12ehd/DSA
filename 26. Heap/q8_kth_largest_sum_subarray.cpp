#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//naukri.com

//brute force
//time = O(n^2 * logn) space = o(n^2)
// bool myComp(int a,int b){
// 	return a>b;
// }
// int getKthLargest(vector<int> &arr, int k)
// {
// 	//	Write your code here.
// 	vector<int> v;
// 	int n = arr.size(); 

// 	for(int i=0; i<n; i++){
// 		int sum = 0; 
// 		for(int j=i; j<n; j++){
// 			sum = sum + arr[j];
// 			v.push_back(sum);
// 		}
// 	}

// 	sort(v.begin(),v.end(),myComp);
// 	if(k<v.size()){
// 		return v[k-1];
// 	}
// 	else{
// 		return v.back();
// 	}
// }

//time=O(n^2) space = O(k)
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
    priority_queue<int,vector<int>,greater<int>> minheap;
    int n = arr.size();
    for(int i=0; i<n; i++){
        int sum =0;
        for(int j=i; j<n; j++){
            sum = sum + arr[j];
            if(minheap.size() < k){
                minheap.push(sum);
            }
            else{
                if(sum > minheap.top()){
					minheap.pop();
                	minheap.push(sum);
				}
            }
        }
    }

    return minheap.top();
}

int main(){
    return 0;
}