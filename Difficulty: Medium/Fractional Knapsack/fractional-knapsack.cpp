bool comp(pair<double,int>a,pair<double,int>b)
{
    return a.first>b.first;
}
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        priority_queue<pair<double,int>>pq;
    for (int i=0;i<n;i++) {
        double temp=val[i];
        temp/=wt[i];
        pq.push({temp,i});
    }
    double ans=0;
    while (capacity!=0&&!pq.empty()) {
        if (wt[pq.top().second]<=capacity) {
            capacity-=wt[pq.top().second];
            ans+=val[pq.top().second];
        }
        else {
            ans+=pq.top().first*capacity;
            capacity=0;
        }
        pq.pop();
    }
    return ans;
        
    }
};
