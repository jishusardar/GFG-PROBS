class Solution {
  public:
    int find(int index,int n,vector<int>&arr,int t,vector<vector<int>>&dp){
        if(index==n)
        return 0;
        if(dp[index][t]!=-1)
        return dp[index][t];
        if(!t)
        return dp[index][t]=max(-arr[index]+find(index+1,n,arr,1,dp),find(index+1,n,arr,0,dp));
        else
        return dp[index][t]=max(arr[index]+find(index+1,n,arr,0,dp),find(index+1,n,arr,1,dp));
    }
    int stockBuySell(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return find(0,n,arr,0,dp);
    }
};