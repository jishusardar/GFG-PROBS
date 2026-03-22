class Solution {
  public:
    bool find(int sum,vector<int>&arr,int index,int n){
        if(sum==0)
        return 1;
        if(index==n)
        return 0;
        if(sum<arr[index])
        return find(sum,arr,index+1,n);
        else
        return find(sum-arr[index],arr,index+1,n)||find(sum,arr,index+1,n);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        return find(sum,arr,0,n);
    }
};