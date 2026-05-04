class Solution {
  public:
    // Function to find the nth catalan number.
    int find(int left,int right,int n,vector<vector<int>>&dp){
        if(left+right==2*n)
        return 1;
        if(left>n||right>n)
        return 0;
        if(dp[left][right]!=-1)
        return dp[left][right];
        int ans=0;
        if(left<n)
        ans+=find(left+1,right,n,dp);
        if(right<left)
        ans+=find(left,right+1,n,dp);
        return dp[left][right]=ans;
    }
    int findCatalan(int n) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return find(0,0,n,dp);
    }
};