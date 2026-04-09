// User function template in C++

class Solution {
  public:
    // Function to find total number of unique paths.
    int NumberOfPath(int a, int b) {
        // code here
        vector<int>dp(b,1);
    for (int i=a-2;i>=0;i--) {
        for (int j=b-2;j>=0;j--) {
            dp[j]+=dp[j+1];
        }
    }
    return dp[0];
    }
};
