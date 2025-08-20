class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        int total=0;
        int sum=0;
        unordered_map<int,int>mm;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==0)
            total++;
            if(mm[sum]){
                total+=mm[sum];
            }
            mm[sum]++;
        }
        return total;
    }
};