class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
       vector<int>ans(n,-1);
    priority_queue<int,vector<int>,greater<int>>q;
    q.push(0);
    for (int i=0;i<k-1;i++) {
        q.push(arr[i]);
    }
    for (int i=k-1;i<n;i++) {
        if (arr[i]>q.top()) {
            if(!q.empty())
            q.pop();
            q.push(arr[i]);
        }
        ans[i]=q.top();
    }
    return ans;
    }
};