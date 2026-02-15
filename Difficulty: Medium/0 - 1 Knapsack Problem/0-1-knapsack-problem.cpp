class Solution {
  public:
    int find(int index,int w,vector<int>&val,vector<int>&wt,vector<vector<int>>&dp){
        if(w==0)
        return 0;
        if(index==0)
        return 0;
        if(dp[index][w]!=-1)
        return dp[index][w];
        if(wt[index-1]>w)
        return dp[index][w]=find(index-1,w,val,wt,dp);
        else
        return dp[index][w]=max(val[index-1]+find(index-1,w-wt[index-1],val,wt,dp),find(index-1,w,val,wt,dp));
    }
    int knapsack(int W, vector<int> &val, vector<int>&wt) {
        // code here
        vector<vector<int>>dp(wt.size()+1,vector<int>(W+1,-1));
        return find(wt.size(),W,val,wt,dp);
    }
};