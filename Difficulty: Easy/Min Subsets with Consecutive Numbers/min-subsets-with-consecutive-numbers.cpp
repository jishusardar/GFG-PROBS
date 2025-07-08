class Solution {
  public:
    int numOfSubset(vector<int> &arr) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int ans=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]!=arr[i]-1)
            ans++;
        }
        return ans;
    }
};