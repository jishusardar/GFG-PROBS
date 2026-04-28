class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        vector<int>ans;
        unordered_map<int,int>mm;
        for(int i=0;i<a.size();i++){
            mm[a[i]]=1;
        }
        for(int i=0;i<b.size();i++){
            if(mm[b[i]]==1)
            mm[b[i]]++;
        }
        for(int i=0;i<b.size();i++){
            if(mm[b[i]]==2){
                ans.push_back(b[i]);
                mm[b[i]]=0;
            }
        }
        return ans;
    }
};