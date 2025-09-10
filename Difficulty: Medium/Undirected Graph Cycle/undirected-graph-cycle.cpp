class Solution {
  public:
    bool detect(vector<vector<int>>&Adjmat,int v,int parent,vector<bool>&visited)
    {
        visited[v]=1;
        for(int i=0;i<Adjmat[v].size();i++){
            if(Adjmat[v][i]==parent)
            continue;
            if(visited[Adjmat[v][i]])
            return 1;
            if(detect(Adjmat,Adjmat[v][i],v,visited))
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
        vector<bool>visited(V,0);
        for(int i=0;i<V;i++){
          if(!visited[i]&&detect(Adjmat,i,-1,visited))
          return 1;
        }
        return 0;
    }
};