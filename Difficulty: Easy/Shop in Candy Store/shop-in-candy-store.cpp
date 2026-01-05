class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(prices.begin(),prices.end());
        int i=0,j=prices.size()-1;
        vector<int>ans(2,0);
        while(i<=j){
            ans[0]+=prices[i++];
            j-=k;
        }
        i=0,j=prices.size()-1;
        while(i<=j){
            ans[1]+=prices[j--];
            i+=k;
        }
        return ans;
    }
};