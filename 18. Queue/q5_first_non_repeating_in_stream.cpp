#include<iostream>
#include<queue>
using namespace std;

string FirstNonRepeating(string str){
	int freq[26] = {0};
    queue<char> q;
    string ans = "";

    for(int i=0; i<str.length(); i++){
        char ch = str[i];

        //increament frequency
        freq[ch-'a']++;
        //push into queue
        q.push(ch);

        //find ans from front
        while(!q.empty()){
            if(freq[q.front()-'a'] > 1){
                q.pop();
            }
            else if(freq[q.front()-'a'] == 1){
                //save ans
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

int main(){
    string str = "aabc";
    cout << FirstNonRepeating(str);
    return 0;
}