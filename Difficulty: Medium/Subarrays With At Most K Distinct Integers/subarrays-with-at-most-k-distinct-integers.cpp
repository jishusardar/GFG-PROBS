class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int ans=0;
        int start=0,end=0,diff=0;
        unordered_map<int,int>mm;
        while(end<arr.size()){
            if(mm[arr[end]]==0)
            diff++;
            mm[arr[end]]++;
            end++;
            while(diff>k){
                mm[arr[start]]--;
                if(mm[arr[start]]==0)
                diff--;
                start++;
            }
            ans+=end-start;
        }
        return ans;
    }
};