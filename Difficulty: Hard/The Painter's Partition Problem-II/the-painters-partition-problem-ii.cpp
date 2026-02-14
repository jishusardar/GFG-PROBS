class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        int start=INT_MIN,end=0;
        for(int i=0;i<arr.size();i++){
            start=max(start,arr[i]);
            end+=arr[i];
        }
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int count=1,sum=0;
            for(int i=0;i<arr.size();i++){
                sum+=arr[i];
                if(sum>mid){
                    sum=arr[i];
                    count++;
                }
            }
            if(count<=k){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};