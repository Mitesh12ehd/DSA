#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Naukri
//Ninja's training

//see notes

//recursion
//time = O(3^n)
//space = O(n)
int fun(int day,int lastTaskPerformed,vector<vector<int>> &points){
    if(day == 0){
        int maxMeritPoint = INT_MIN;
        for(int task=0; task<3; task++){
            if(task != lastTaskPerformed){
                maxMeritPoint = max(maxMeritPoint,points[0][task]);
            }
        }
        return maxMeritPoint;
    }

    //find which task we should perform today to get max merit point
    int maxMeritPoint = INT_MIN;
    for(int task=0; task<3; task++){
        if(task != lastTaskPerformed){
            int meritPoint = points[day][task] + fun(day-1,task,points);
            maxMeritPoint = max(maxMeritPoint,meritPoint);
        }
    }
    return maxMeritPoint;
}
int ninjaTraining(int n, vector<vector<int>> &points){
    //3 denote none task performed before
    return fun(n,3,points);
}

//memorization
//time = O(n*4*3)
//space = O(4*n + n)
int fun(int day,int lastTaskPerformed,vector<vector<int>>& points,vector<vector<int>> &dp){
    if(day == 0){
        int maxMeritPoint = INT_MIN;
        for(int task=0; task<3; task++){
            if(task != lastTaskPerformed){
                maxMeritPoint = max(maxMeritPoint,points[0][task]);
            }
        }
        return maxMeritPoint;
    }

    if(dp[day][lastTaskPerformed] != -1){
        return dp[day][lastTaskPerformed];
    }
    
    //find which task we should perform today to get max merit point
    int maxMeritPoint = INT_MIN;
    for(int task=0; task<3; task++){
        if(task != lastTaskPerformed){
            int meritPoint = points[day][task] + fun(day-1,task,points,dp);
            maxMeritPoint = max(maxMeritPoint,meritPoint);
        }
    }
    dp[day][lastTaskPerformed] = maxMeritPoint;
    return dp[day][lastTaskPerformed];
}
int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return fun(n-1,3,points,dp);
}

//tabulation
//time = O(n*4*3)
//space = O(n*4)
int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n,vector<int>(4,-1));

    //base case intialization
    // dp[0][0] = max(points[0][1], points[0][2]);
    // dp[0][1] = max(points[0][0], points[0][2]);
    // dp[0][2] = max(points[0][0], points[0][1]);
    // dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    for(int lastTaskPerformed=0; lastTaskPerformed<=3; lastTaskPerformed++){
        int maxi = 0;
        for(int task=0; task<3; task++){
            if(task != lastTaskPerformed){
                maxi = max(maxi,points[0][task]);
            }
        }
        dp[0][lastTaskPerformed] = maxi;
    }
    
    //logic
    for(int day=1; day<n; day++){
        for(int lastTaskPerformed=0; lastTaskPerformed<4; lastTaskPerformed++){
            int maxi = 0;
            for(int task=0; task<3; task++){
                if(task != lastTaskPerformed){
                    int meritPoint = points[day][task] + dp[day-1][task];
                    maxi = max(maxi,meritPoint);
                }
            }
            dp[day][lastTaskPerformed] = maxi;
        }
    }
    return dp[n-1][3];
}

//space optimization
//time = O(n*4*3)
//space = O(4)
int ninjaTraining(int n, vector<vector<int>> &points){
    vector<int> prev(4,0);

    for(int lastTaskPerformed=0; lastTaskPerformed<=3; lastTaskPerformed++){
        int maxi = 0;
        for(int task=0; task<3; task++){
            if(task != lastTaskPerformed){
                maxi = max(maxi,points[0][task]);
            }
        }
        prev[lastTaskPerformed] = maxi;
    }
    
    //logic
    for(int day=1; day<n; day++){
        vector<int> temp(4,0);
        for(int lastTaskPerformed=0; lastTaskPerformed<4; lastTaskPerformed++){
            int maxi = 0;
            for(int task=0; task<3; task++){
                if(task != lastTaskPerformed){
                    int meritPoint = points[day][task] + prev[task];
                    maxi = max(maxi,meritPoint);
                }
            }
            temp[lastTaskPerformed] = maxi;
        }
        prev = temp;
    }
    return prev[3];
}

int main(){
    return 0;
}