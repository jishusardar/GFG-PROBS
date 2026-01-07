bool comp(pair<double,int>a,pair<double,int>b)
{
    return a.first>b.first;
}
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<pair<double,int>>perweight(val.size());
        for(int i=0;i<val.size();i++){
            double temp=val[i];
            temp/=wt[i];
            perweight[i]={temp,i};
        }
        sort(perweight.begin(),perweight.end(),comp);
        double ans=0;
        for(int i=0;i<n;i++){
            if(capacity!=0){
                if(capacity>=wt[perweight[i].second]){
                    ans+=val[perweight[i].second];
                    capacity-=wt[perweight[i].second];
                }
                else{
                    ans+=capacity*perweight[i].first;
                    capacity=0;
                }
            }
        }
        return ans;
        
    }
};
