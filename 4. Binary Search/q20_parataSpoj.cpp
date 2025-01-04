#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossibleSolution(vector<int> rank,int nP,int mid){
    int cookedCount = 0;
    for(int i=0; i<rank.size(); i++){
        int j = 1;
        int timeTaked = 0;

        while(timeTaked + j*rank[i]  <=  mid){
            cookedCount++;
            timeTaked = timeTaked + j*rank[i];
            j++;
        }
        
        if(cookedCount >= nP){
            return true;
        }
    }
    return false;
}
int minimumTime(vector<int> rank,int nP){
    int start = 0;
    int highestRank = *max_element(rank.begin(),rank.end());
    int end = highestRank * (nP*(nP+1) / 2);
    int ans = -1;

    while(start<=end){
        int mid = start + (end-start) / 2;
        if(isPossibleSolution(rank,nP,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int nP,nC;
        cin >> nP >> nC;
        vector<int> rank;
        while(nC--){
            int R;
            cin>>R;
            rank.push_back(R);
        }
        cout<<minimumTime(rank,nP)<<endl;
    }
    return 0;
}