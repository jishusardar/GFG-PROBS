class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        vector<int>ans;
        int m=arr.size()+1;
        for(int i=0;i<arr.size();i++){
            arr[(arr[i]-1)%m]+=m;
            if(arr[(arr[i]-1)%m]/m>1)
            ans.push_back(((arr[i]-1)%m)+1);
        }
        return ans;
    }
};