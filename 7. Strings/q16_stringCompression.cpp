#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int compress(vector<char>& s) {
    int index = 0;
    int count = 1;
    char prev = s[0];

    for(int i=1; i<s.size(); i++){
        if(s[i] == prev){
            count++;
        }
        else{
            s[index] = prev;
            index++;
            if(count>1){
                //reverese is handle to to digit character
                int start = index;
                while(count){
                    s[index] = (count%10) + '0';
                    count = count / 10;
                    index++;
                }
                reverse(s.begin()+start , s.begin() + index);
                                        //s.begin()+index is explicit,
                                        //till s.begin()+index-1 sorted.
            }
            prev = s[i];
            count = 1;
        }
    }
    s[index] = prev;
    index++;
    if(count > 1){
        int start = index;
        while(count){
            s[index] = (count%10) + '0';
            count = count / 10;
            index++;
        }
        reverse(s.begin()+start , s.begin() + index);
    }
    return index;
}
int main(){
    //leetcode 443
    vector<char> temp{'a','a','b','b','c','c','c'};
    cout << compress(temp);

    return 0;
}