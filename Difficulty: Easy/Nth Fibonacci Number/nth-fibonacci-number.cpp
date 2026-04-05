class Solution {
  public:
    int find(int n,vector<int>&dp){
        if(n<=1)
        return n;
        if(dp[n]!=-1)
        return dp[n];
        return dp[n]=find(n-1,dp)+find(n-2,dp);
    }
    int nthFibonacci(int n) {
        // code here
        vector<int>dp(n+1,-1);
        return find(n,dp);
    }
};