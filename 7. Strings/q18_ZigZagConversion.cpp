#include<iostream>
#include<vector>
using namespace std;

string convert(string s, int numRows) {
    if(numRows == 1){
        return s;
    }

    vector<string> zigzag(numRows);
                    //it create total numrows vector of string

    int i=0; 
    int row = 0;
    bool direction = 1;//1 denote top to bottom, 0 denote bottom to top

    while(true){
        //print first line top to bottom
        if(direction){
            while(row<numRows && i<s.length()){
                zigzag[row].push_back(s[i]);
                i++,row++;
            }
            row = numRows - 2;
            //here numrows - 2 because after printing numrows=3 character 
            //we reached at row = 3 ,
        }
        //print second line bottom to top
        else{
            while(row>=0 && i<s.length()){
                zigzag[row].push_back(s[i]);
                row--,i++;
            }
            row = 1;
        }
        if(i >= s.length()) {
            break;
        }
        direction = !direction;
    }
    string ans = "";
    for(int i=0; i<zigzag.size(); i++){
        ans = ans + zigzag[i];
    }
    return ans;
}

int main(){
    //leetcode 6
    string s = "PAYPALISHIRING";
    int numRows = 3;
    cout << convert(s,numRows);

    return 0;
}