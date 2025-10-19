class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        sort(arr,arr+n);
        long long ans=0;
        for(int i=0;i<n-2;i++){
            int start=i+1,end=n-1;
            while(start<end){
                if(arr[i]+arr[start]+arr[end]<sum){
                    ans+=end-start;
                    start++;
                }
                else
                end--;
            }
        }
        return ans;
    }
};