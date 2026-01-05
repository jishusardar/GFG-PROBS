class Solution {
  public:
    int findMin(int n) {
        // code here
        int ans=0;
        vector<int>coins={10,5,2,1};
        for(int i=0;i<4;i++){
            while(n/coins[i]>0){
                ans+=n/coins[i];
                n=n%coins[i];
            }
        }
        return ans;
    }
};