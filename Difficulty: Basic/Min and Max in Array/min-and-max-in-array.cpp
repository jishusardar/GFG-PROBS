// User function Template for C++
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        // code here
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
        }
        for(int i=0;i<arr.size();i++)
        mini=min(mini,arr[i]);
        pair<int,int>ans;
        ans.first=mini;
        ans.second=maxi;
        return ans;
    }
};