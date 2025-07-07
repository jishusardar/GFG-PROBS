class Solution {
  public:
    int transitionPoint(vector<int>& arr) {
        // code here
        int ans=-1;
        int start=0,end=arr.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]>0){
                ans=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        return ans;
    }
};