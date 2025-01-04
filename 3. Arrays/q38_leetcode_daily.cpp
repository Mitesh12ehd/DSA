#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//leetcode 2491
//divide the players into equalls skills

//intituion: a lowest skilled player always make pair with highest skilled players

long long dividePlayers(vector<int>& skill) {
    sort(skill.begin(),skill.end());
    int start = 0;
    int end = skill.size()-1;
    long long chemistry = 0;
    int totalskill = skill[start] + skill[end];

    while(start < end){
        if(totalskill != skill[start] + skill[end]){
            return -1;
        }

        int multi = skill[start] * skill[end];
        chemistry = chemistry + multi;

        start++,end--;
    }

    return chemistry;
}

int main(){
    return 0;
}