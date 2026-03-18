class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]==1||grid[n-1][m-1]==1)
        return 0;
        vector<vector<int>>dp(n,vector<int>(m,0));
        dp[n-1][m-1]=1;
        for(int i=n-2;i>=0;i--){
            if(!grid[i][m-1])
                dp[i][m-1]=1;
            else
            break;
        }
        for(int i=m-2;i>=0;i--){
            if(!grid[n-1][i])
                dp[n-1][i]=1;
            else
            break;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(!grid[i][j]){
                    dp[i][j]=dp[i+1][j]+dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
};