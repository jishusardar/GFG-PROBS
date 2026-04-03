
class Solution {
  public:
    // Function to count the number of ways in which frog can reach the top.
    int countWays(int n) {

        // your code here
        int curr=1;
    int prev1=0;
    int prev2=0;
    for (int i=n-1;i>=0;i--) {
        int ans=curr+prev1+prev2;
        prev2=prev1;
        prev1=curr;
        curr=ans;
    }
    return curr;
        
    }
};
