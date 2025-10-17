class Solution {
  public:
    // Function to remove duplicates from the given array.
    vector<int> removeDuplicates(vector<int> &arr) {
        // code here
        vector<int>ans;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]!=arr[i+1]){
                ans.push_back(arr[i]);
            }
        }
        if(ans.size()&&ans[ans.size()-1]!=arr[arr.size()-1])
        ans.push_back(arr[arr.size()-1]);
        else if(!ans.size()&&arr.size())
        ans.push_back(arr[arr.size()-1]);
        return ans;
    }
};