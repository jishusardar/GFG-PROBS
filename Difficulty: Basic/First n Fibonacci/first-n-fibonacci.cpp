// User function template for C++

class Solution {
  public:
    // Function to return list containing first n fibonacci numbers.
    int find(int n,vector<int>&dp){
        if(n<=1)
        return n;
        if(dp[n]!=-1)
        return dp[n];
        return dp[n]=find(n-1,dp)+find(n-2,dp);
    }
    vector<int> fibonacciNumbers(int n) {
        // code here
        vector<int>dp(n,-1);
        dp[0]=0;
        dp[1]=1;
        find(n-1,dp);
        return dp;
    }
};