class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // code here
        sort(mices.begin(),mices.end());
        sort(holes.begin(),holes.end());
        int ans=INT_MIN;
        for(int i=0;i<mices.size();i++){
            ans=max(ans,abs(mices[i]-holes[i]));
        }
        return ans;
    }
};