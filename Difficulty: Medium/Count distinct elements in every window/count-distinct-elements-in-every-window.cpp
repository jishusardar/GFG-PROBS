class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int count=0;
        unordered_map<int,int>mm;
        for(int i=0;i<k;i++){
            if(mm[arr[i]]==0)
            count++;
            mm[arr[i]]++;
        }
        vector<int>ans;
        ans.push_back(count);
        for(int i=k;i<arr.size();i++){
            mm[arr[i-k]]--;
            if(mm[arr[i-k]]==0)
            count--;
            if(mm[arr[i]]==0)
            count++;
            ans.push_back(count);
            mm[arr[i]]++;
        }
        return ans;
    }
};