class Solution {
  public:
    int find(int n,int m,string &s,vector<vector<int>>&dp){
        if(n==0||m==0)
        return 0;
        if(dp[n][m]!=-1)
        return dp[n][m];
        if(s[n-1]==s[m-1]&&n!=m)
        return dp[n][m]=1+find(n-1,m-1,s,dp);
        else
        return dp[n][m]=max(find(n-1,m,s,dp),find(n,m-1,s,dp));
    }
    int LongestRepeatingSubsequence(string &s) {
        // Code here
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return find(n,n,s,dp);
    }
};