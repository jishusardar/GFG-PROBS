class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        for(int i=0;i<arr.size();i++)
        arr[i]--;
        for(int i=0;i<arr.size();i++){
            arr[arr[i]%n]+=n;
        }
        vector<int>ans(2,0);
        for(int i=0;i<arr.size();i++){
            if(arr[i]/n>1)
            ans[0]=i+1;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]/n==0)
            ans[1]=i+1;
        }
        return ans;
    }
};