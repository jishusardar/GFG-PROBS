class Solution {
  public:
    int find(int i,int j,string &s1, string &s2,vector<vector<int>>&dp){
        if(i==0||j==0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s1[i-1]==s2[j-1])
        return dp[i][j]=1+find(i-1,j-1,s1,s2,dp);
        else
        return dp[i][j]=max(find(i-1,j,s1,s2,dp),find(i,j-1,s1,s2,dp));
    }
    int lcs(string &s1, string &s2) {
        // code here
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return find(s1.size(),s2.size(),s1,s2,dp);
    }
};
