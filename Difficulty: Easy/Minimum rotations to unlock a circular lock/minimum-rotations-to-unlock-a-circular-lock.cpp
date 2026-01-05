// User function Template for C++

class Solution {
  public:
    int rotationCount(long long R, long long D) {
        // code here
        int ans=0;
        while(R!=0){
            int rem1=R%10;
            int rem2=D%10;
            R/=10;
            D/=10;
            ans+=min(abs(rem1-rem2),10-abs(rem2-rem1));
        }
        return ans;
    }
};