#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

//leetcode 355
//Design Twitter

//brute force
class Twitter {
public:
    vector<pair<int,int>> tweets; //userid,tweetid
    unordered_map<int,unordered_set<int>> followList;

    Twitter() {
        
    }
    
    //O(1)
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId,tweetId});
    }
    
    //O(totalTweets)
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        int i = tweets.size()-1;
        while(i>=0){
            int user = tweets[i].first;
            if(followList[userId].find(user) != followList[userId].end()){
                ans.push_back(tweets[i].second);
            }
            else if(userId == user){
                ans.push_back(tweets[i].second);
            }

            i--;
            if(ans.size() == 10){
                break;
            }
        }
        return ans;
    }
    
    //O(1)
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    //O(1)
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }
};

//optimal
class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> followList;
    int time = 0;

    Twitter() {
        
    }
    
    //O(1)
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({time,tweetId});
    }
    
    // if user follows total f user
    // and there is at max f elements in heap because we insert only last tweet of each following
    // time = O(f log f) , while loop run for at max 10 time only it take constant time
    vector<int> getNewsFeed(int userId) {
        //here we insert most recent tweet of each following
        //maxheap store {time,userId,size,tweet_id}
        //it give most recent tweet
        //we seclect most recent tweet and then we push previous tweet of selected tweet

        priority_queue<vector<int>> pq;
        vector<int> ans;
        for(auto it:followList[userId]){
            if(tweets[it].size() > 0){
                int t = tweets[it].back().first;
                int tweet_id = tweets[it].back().second;
                int size = tweets[it].size();
                pq.push({t,it,size-1,tweet_id});
            }
        }

        //push own tweets because it can be also shown on feed
        if(tweets[userId].size() > 0){
            int t = tweets[userId].back().first;
            int tweet_id = tweets[userId].back().second;
            int size = tweets[userId].size();
            pq.push({t,userId,size-1,tweet_id});
        }


        int k = 10;
        while(k>0 && !pq.empty()){
            vector<int> v = pq.top();
            pq.pop();
            ans.push_back(v[3]);

            //push previous of selected tweet
            if(v[2] > 0){
                int t = tweets[v[1]][v[2]-1].first;
                int tweet_id = tweets[v[1]][v[2]-1].second;
                int size = v[2]-1;
                pq.push({t,v[1],size,tweet_id});
            }
            k--;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }
};

int main(){
    return 0;
}