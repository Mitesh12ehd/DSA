#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//GFG
//N meetings in the room

//see notes

//another can question can be return the list of index of meeting 
//that can be schedule to maximize total number of meetings

//here we write code on based of both question

int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();

    vector<vector<int>> v; // {endtime,starttime,index of meeting}
    for(int index=0; index<n; index++){
        v.push_back({end[index],start[index],index});
    }
    sort(v.begin(),v.end());

    int count = 1;
    int freeTime = v[0][0];
    for(int i=1; i<n; i++){
        if(v[i][1] > freeTime){
            count++;
            freeTime = v[i][0];
        }
    }
    return count;
}  

int main(){
    return 0;
}