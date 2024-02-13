#include<iostream>
#include<queue>
using namespace std;

void solve(int arr[],int n,int k){
    for(int i=0; i<n-k+1; i++){
        bool nagativeFind = false;
        
        for(int j=i; j<i+k; j++){
            if(arr[j] < 0){
                nagativeFind = true;
                cout << arr[j] << " ";
                break;
            }
        }
        if(nagativeFind == false){
            cout << "0";
        }
    }
}

void solve(int arr[],int n,int k){
    queue<int> q;

    //process first window of size k
    for(int i=0; i<k; i++){
        if(arr[i] < 0){
            q.push(i);
        }
    }
    //find ans of k window
    if(q.empty()){
        cout << "0 ";
    }
    else{
        cout << arr[q.front()] << " ";
    }

    //remaining window process hint: i pointing element that at end of window
    for(int i=k; i<n; i++){
        //remove element 
        if(!q.empty() && (i - q.front() >= k)){
            q.pop();
        }

        //insert element of next window
        if(arr[i] < 0){
            q.push(i);
        }

        //find ans of k window
        if(q.empty()){
            cout << "0 ";
        }
        else{
            cout << arr[q.front()] << " ";
        }
    }
}

int main(){
    int arr[] = {12,-1,-7,8,-15,30,16,28};
    int size = 8;
    int k = 3;
    solve(arr,size,k);

    return 0;
}