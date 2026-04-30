
class Solution {
  public:
    int find(int n,vector<int>&dp){
        if(n==0)
        return 1;
        if(n<0)
        return 0;
        if(dp[n]!=-1)
        return dp[n];
        return dp[n]=find(n-1,dp)+find(n-2,dp)+find(n-3,dp);
    }
    int countWays(int n) {
        // your code here
        vector<int>dp(n+1,-1);
        return find(n,dp);
    }
};
