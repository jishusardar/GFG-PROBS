class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        if(arr.size()<2)
        return arr.size();
        int start=0,end=0,ans=0,diff=0;
        unordered_map<int,int>mm;
        while(end<arr.size()){
            if(mm[arr[end]]==0)
                diff++;
                mm[arr[end]]++;
                end++;
            while(diff>2){
                mm[arr[start]]--;
                if(mm[arr[start]]==0)
                diff--;
                start++;
            }
            ans=max(ans,end-start);
            
        }
        return ans;
    }
};