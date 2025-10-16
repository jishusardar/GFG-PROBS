class Solution {
  public:
    int findparent(int u,vector<int>&parent)
    {
        if(u==parent[u])
        return u;
        return parent[u]=findparent(parent[u],parent);
    }
    void UnionByRanks(int u,int v,vector<int>&parent,vector<int>&ranks)
    {
        int pu=findparent(u,parent);
        int pv=findparent(v,parent);
        if(ranks[pu]>ranks[pv]){
            parent[pv]=pu;
        }
        else if(ranks[pv]>ranks[pu]){
            parent[pu]=pv;
        }
        else{
            parent[pv]=pu;
            ranks[pv]++;
        }
    }
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>parent(V);
        vector<int>ranks(V,0);
        vector<pair<int,pair<int,int>>>arr;
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        for(int i=0;i<edges.size();i++){
            arr.push_back({edges[i][2],{edges[i][0],edges[i][1]}});
        }
        int ans=0,edge=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq(arr.begin(),arr.end());
        while(!pq.empty()){
            int wt=pq.top().first;
            int u=pq.top().second.first;
            int v=pq.top().second.second;
            pq.pop();
            if(findparent(u,parent)==findparent(v,parent))
            continue;
            ans+=wt;
            UnionByRanks(u,v,parent,ranks);
            edge++;
            if(edge==V-1)
            break;
        }
        return ans;
    }
};