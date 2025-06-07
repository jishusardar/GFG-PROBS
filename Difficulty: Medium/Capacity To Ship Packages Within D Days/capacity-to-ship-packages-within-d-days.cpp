// User function Template for C++

class Solution {
  public:
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        int ans;
        int start=INT_MIN;
        int end=0;
        for(int i=0;i<n;i++){
            start=max(start,arr[i]);
            end+=arr[i];
        }
        while(start<=end){
            int mid=start+(end-start)/2;
            int weight=0,count=1;
            for(int i=0;i<n;i++){
                weight+=arr[i];
                if(weight>mid){
                    weight=arr[i];
                    count++;
                }
            }
            if(count<=d){
                ans=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        return ans;
    }
};