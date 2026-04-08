// User function template for C++

class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n<=2)
        return n;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
            mini=min(mini,arr[i]);
        }
        int ans=2;
        vector<vector<int>>dp(n,vector<int>(maxi-mini+1,0));
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                int diff=arr[i]-arr[j];
                if(dp[j][diff]){
                    dp[i][diff]=max(dp[i][diff],1+dp[j][diff]);
                    ans=max(ans,dp[i][diff]);
                }
                else{
                    if(!dp[i][diff])
                    dp[i][diff]=2;
                }
            }
        }
        return ans;
    }
};