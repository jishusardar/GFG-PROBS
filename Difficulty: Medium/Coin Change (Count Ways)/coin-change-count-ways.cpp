class Solution {
  public:
    int find(int sum,int n,vector<int>&coins,vector<vector<int>>&dp) {
    if (sum==0)
        return 1;
    if (n==0)
        return 0;
    if (dp[n][sum]!=-1)
        return dp[n][sum];
    if (coins[n-1]>sum)
        return find(sum,n-1,coins,dp);
    return dp[n][sum]=find(sum-coins[n-1],n,coins,dp)+find(sum,n-1,coins,dp);
}
    int count(vector<int>& coins, int sum) {
        // code here.
        int n=coins.size();
    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    return find(sum,n,coins,dp);
    }
};