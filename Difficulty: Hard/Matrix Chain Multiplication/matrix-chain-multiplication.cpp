class Solution {
  public:
    int find(int start,int end,vector<int>&arr,vector<vector<int>>&dp){
        if(start+1==end)
        return 0;
        if(dp[start][end]!=-1)
        return dp[start][end];
        unsigned int ans=INT_MAX;
        for(int mid=start+1;mid<end;mid++){
            unsigned int temp=find(start,mid,arr,dp)+find(mid,end,arr,dp)+arr[start]*arr[mid]*arr[end];
            ans=min(ans,temp);
        }
        return dp[start][end]=ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return find(0,arr.size()-1,arr,dp);
    }
};