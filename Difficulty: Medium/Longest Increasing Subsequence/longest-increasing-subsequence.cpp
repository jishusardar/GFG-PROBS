class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>temp(n,1);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(arr[i]>arr[j]){
                    temp[i]=max(temp[i],temp[j]+1);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,temp[i]);
        }
        return ans;
    }
};