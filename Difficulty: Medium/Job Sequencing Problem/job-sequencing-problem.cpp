bool comp(pair<int,int> a,pair<int,int> b)
{
    return a.first>b.first;
}
int find(int num,vector<int>&parent)
{
    if(num==parent[num])
    return num;
    return parent[num]=find(parent[num],parent);
}
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int dead=0;
        for(int i=0;i<deadline.size();i++){
            dead=max(dead,deadline[i]);
        }
        vector<pair<int,int>>jobs;
        for(int i=0;i<deadline.size();i++){
            jobs.push_back({profit[i],deadline[i]});
        }
        sort(jobs.begin(),jobs.end(),comp);
        vector<int>parent(dead+1);
        for(int i=0;i<=dead;i++){
            parent[i]=i;
        }
        vector<int>ans(2,0);
        for(int i=0;i<jobs.size();i++){
            int slot=find(jobs[i].second,parent);
            if(slot>0){
                ans[0]++;
                ans[1]+=jobs[i].first;
                parent[slot]=slot-1;
            }
        }
        return ans;
    }
};