class Solution {
  public:
    long long sumOfDivisors(long long n) {
        // Code here
        long long ans=0;
        for(long long i=1;i<=n;i++){
            ans+=(n/i)*i;
        }
        return ans;
    }
};