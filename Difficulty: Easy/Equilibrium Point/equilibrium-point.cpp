class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int sum=0;
        for(int i=0;i<arr.size();i++)
        sum+=arr[i];
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(count==sum-count-arr[i])
            return i;
            count+=arr[i];
        }
        return -1;
    }
};