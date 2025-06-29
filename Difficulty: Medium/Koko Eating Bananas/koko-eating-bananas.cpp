class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int start=0,end=INT_MIN;
        for(int i=0;i<arr.size();i++){
            start+=arr[i];
            end=max(end,arr[i]);
        }
        start/=k;
        if(start==0)
        start++;
        int ans;
        while(start<=end){
            int mid=start+(end-start)/2;
            int time=0;
            for(int i=0;i<arr.size();i++){
                time+=arr[i]/mid;
                if(arr[i]%mid)
                time++;
            }
            if(time>k){
                start=mid+1;
            }
            else{
                ans=mid;
                end=mid-1;
            }
        }
        return ans;
    }
};