#include <bits/stdc++.h>
using namespace std;

// [SYSTEM DESIGN] [HARD]

// NOT COMPLETELY A SYSTEM DESIGN QUES, DID THIS PROBLEM USING MAPS ONLY, THOUGH MULTIPLE SOLUTIONS COULD EXIST

class Twitter {
public:

    int timer = INT_MAX ;
    // why INT_MAX -> to store the tweets in ascending order wise in map -> with each tweet we would decrease the timer such that the next tweet should exist above the current tweet in the map

    // a map to record the user's follow / unfollow
    // 2-D map
    // to understand 2-D maps : https://iq.opengenus.org/2d-maps-in-cpp/#:~:text=C%2B%2B-,2D%20Map,type%20string%20and%20int%20values.
    unordered_map<int, unordered_map<int, bool>> mp ;

    // a map to store the tweets
    map <int, pair<int,int>> tweets ; // <time , <userId, tweetId>> -> timer is used to sort the tweets accoding to the tweet in the map -> since map stores the data according to the ascending order

    Twitter() {} // NO USE

    void postTweet(int userId, int tweetId) {
        tweets[timer--] = {userId, tweetId} ;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans ;
        for(auto it: tweets) {
            if(it.second.first == userId or mp[userId].count(it.second.first)) {
                ans.push_back(it.second.second) ;
            }
            if(ans.size() == 10){break ;}
        }
        return ans ;
    }

    void follow(int followerId, int followeeId) {

        mp[followerId][followeeId]= true ;

    }

    void unfollow(int followerId, int followeeId) {

        mp[followerId].erase(followeeId) ;

    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */