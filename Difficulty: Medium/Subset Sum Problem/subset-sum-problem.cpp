class Solution {
  public:
    bool possible(int sum,vector<int>&arr,int n){
        if(sum==0)
        return 1;
        if(n==0||sum<0)
        return 0;
        return possible(sum-arr[n-1],arr,n-1)||possible(sum,arr,n-1);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        return possible(sum,arr,n);
    }
};