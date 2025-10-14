class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        //without parent
        vector<bool>Mst(V,0);
        vector<vector<pair<int,int>>>Adj(V);
        for(int i=0;i<edges.size();i++){
            Adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            Adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,0});
        int ans=0;
        while(!q.empty()){
            int wt=q.top().first;
            int node=q.top().second;
            q.pop();
            if(Mst[node])
            continue;
            Mst[node]=1;
            ans+=wt;
            for(int i=0;i<Adj[node].size();i++){
                if(!Mst[Adj[node][i].first]){
                    q.push({Adj[node][i].second,Adj[node][i].first});
                }
            }
        }
        return ans;
    }
};