class Solution {
  public:
    int stockBuySell(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(!j)
                dp[i][j]=max(-arr[i]+dp[i+1][1],dp[i+1][0]);
                else
                dp[i][j]=max(arr[i]+dp[i+1][0],dp[i+1][1]);
            }
        }
        return dp[0][0];
    }
};