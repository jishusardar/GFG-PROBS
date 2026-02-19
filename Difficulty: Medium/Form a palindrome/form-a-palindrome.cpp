// User function template for C++

class Solution {
  public:
    int find(int n,int m,string s1,string s2,vector<vector<int>>&dp){
        if(n==0||m==0)
        return 0;
        if(dp[n][m]!=-1)
        return dp[n][m];
        if(s1[n-1]==s2[m-1])
        return dp[n][m]=1+find(n-1,m-1,s1,s2,dp);
        else
        return dp[n][m]=max(find(n-1,m,s1,s2,dp),find(n,m-1,s1,s2,dp));
    }
    int countMin(string str) {
        // complete the function here
        int n=str.size();
        string s2=str;
        reverse(s2.begin(),s2.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return n-find(n,n,str,s2,dp);
    }
};