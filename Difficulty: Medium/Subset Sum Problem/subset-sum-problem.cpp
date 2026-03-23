class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
vector<int>dp(sum+1,0);
    vector<int>next(sum+1,0);
    dp[0]=1;
    next[0]=1;
    for (int i=n-1;i>=0;i--) {
        for (int j=1;j<=sum;j++) {
            if (j<arr[i])
                dp[j]=next[j];
            else
                dp[j]=next[j-arr[i]]||next[j];
        }
        next=dp;
    }
    return dp[sum];
    }
};