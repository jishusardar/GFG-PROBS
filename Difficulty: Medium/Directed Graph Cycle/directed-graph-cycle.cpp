class Solution {
  public:
     bool detect(vector<vector<int>>&Adjmat,int v,vector<bool>&visited,vector<bool>&paths)
    {
        visited[v]=1;
        paths[v]=1;
        for(int i=0;i<Adjmat[v].size();i++){
            if(paths[Adjmat[v][i]])
            return 1;
            if(detect(Adjmat,Adjmat[v][i],visited,paths))
            return 1;
        }
        paths[v]=0;
        return 0;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>Adjmat(V);
        for(int i=0;i<edges.size();i++){
            Adjmat[edges[i][0]].push_back(edges[i][1]);
        }
        vector<bool>visited(V,0);
        vector<bool>paths(V,0);
        for(int i=0;i<V;i++){
          if(!visited[i]&&detect(Adjmat,i,visited,paths))
          return 1;
        }
        return 0;
    }
};