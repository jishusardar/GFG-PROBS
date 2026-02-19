// User function template for C++

class Solution {
  public:
    int countMin(string str) {
        // complete the function here
        int n=str.size();
        string s2=str;
        reverse(s2.begin(),s2.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(str[i-1]==s2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        return n-dp[n][n];
    }
};