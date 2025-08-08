class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>q(arr.begin(),arr.end());
        int ans=0;
        while(q.size()!=1){
            int h1=q.top();
            q.pop();
            int h2=q.top();
            q.pop();
            ans+=h1+h2;
            q.push(h1+h2);
        }
        return ans;
    }
};