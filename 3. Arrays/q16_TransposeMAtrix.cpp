#include<iostream>
using namespace std;

void transpose(int arr[][3],int ans[][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ans[j][i] = arr[i][j];
        }
    }
}
int main(){
    int arr[3][3];
    //take input
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }
    int ans[3][3];
    transpose(arr,ans);
    cout<<"printing"<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}