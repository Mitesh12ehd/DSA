#include<iostream>
using namespace std;
int main(){
    int arr[3][3];
    
    //take raw wise input and print normal array
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }
    cout<<"printing raw wise"<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //take column wise input and print normal array
    // for(int i=0; i<3; i++){
    //     for(int j=0; j<3; j++){
    //         cin >> arr[j][i];
    //     }
    // }
    // cout<<"printing column wise"<<endl;
    // for(int i=0; i<3; i++){
    //     for(int j=0; j<3; j++){
    //         cout << arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}