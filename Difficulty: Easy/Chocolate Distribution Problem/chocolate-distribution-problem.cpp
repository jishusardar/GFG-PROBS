class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(a.begin(),a.end());
        int ans=INT_MAX;
        ans=min(ans,a[m-1]-a[0]);
        int j=1;
        for(int i=m;i<a.size();i++){
            ans=min(ans,a[i]-a[j]);
            j++;
        }
        return ans;
    }
};