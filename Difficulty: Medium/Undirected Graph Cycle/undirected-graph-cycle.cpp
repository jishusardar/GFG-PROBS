class Solution {
  public:
    bool detect(vector<vector<int>>&Adjmat,vector<bool>vis,int v,int parent)
    {
        vis[v]=1;
        for(int i=0;i<Adjmat[v].size();i++){
            if(Adjmat[v][i]==parent)
            continue;
            if(vis[Adjmat[v][i]])
            return 1;
            if(detect(Adjmat,vis,Adjmat[v][i],v))
            return 1;
        }
        return 0;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>Adjmat(V);
        for(int i=0;i<edges.size();i++){
            Adjmat[edges[i][0]].push_back(edges[i][1]);
            Adjmat[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>vis(V,0);
        for(int i=0;i<edges.size();i++){
            if(detect(Adjmat,vis,edges[i][0],edges[i][1]))
            return 1;
        }
        return 0;
    }
};