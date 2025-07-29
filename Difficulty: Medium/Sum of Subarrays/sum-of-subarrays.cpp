class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int sum=0;
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            sum+=(i+1)*(n-i)*arr[i];
        }
        return sum;
    }
};