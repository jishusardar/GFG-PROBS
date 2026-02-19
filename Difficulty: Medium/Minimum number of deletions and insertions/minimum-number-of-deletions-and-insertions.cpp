class Solution {

  public:
    int find(int n,int m,string &s1, string &s2,vector<vector<int>>&dp){
        if(n==0||m==0)
        return 0;
        if(dp[n][m]!=-1)
        return dp[n][m];
        if(s1[n-1]==s2[m-1])
        return dp[n][m]=1+find(n-1,m-1,s1,s2,dp);
        else
        return dp[n][m]=max(find(n-1,m,s1,s2,dp),find(n,m-1,s1,s2,dp));
    }
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        int lcs=find(s1.size(),s2.size(),s1,s2,dp);
        return s1.size()-lcs+s2.size()-lcs;
    }
};