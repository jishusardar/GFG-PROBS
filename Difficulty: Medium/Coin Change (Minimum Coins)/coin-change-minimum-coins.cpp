class Solution {
  public:
    int find(int sum,vector<int>&coins,vector<int>&dp) {
        if(sum==0)
        return 0;
        if(sum<0)
        return INT_MAX;
        int mincoins=INT_MAX;
        if(dp[sum]!=-1)
        return dp[sum];
        for(int i=0;i<coins.size();i++){
            int res=find(sum-coins[i],coins,dp);
            if(res!=INT_MAX)
            mincoins=min(mincoins,res+1);
        }
        return dp[sum]=mincoins;
    }
    int minCoins(vector<int> &coins, int sum) {
        // code here
        if(sum==0)
        return 0;
        vector<int>dp(sum+1,-1);
        int ans=find(sum,coins,dp);
        return ans==INT_MAX?-1:ans;
    }
};