class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n=coins.size();
    vector<int>dp(sum+1,0);
        dp[0]=1;
    for (int i=1;i<=n;i++) {
        for (int j=coins[i-1];j<=sum;j++) {
            dp[j]=dp[j-coins[i-1]]+dp[j];
        }
    }
    return dp[sum];
    }
};