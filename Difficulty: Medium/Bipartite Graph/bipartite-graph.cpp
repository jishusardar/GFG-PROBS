class Solution {
  public:
    bool detect(vector<vector<int>>&Adj,int v,int parent,vector<int>&colors)
    {
        colors[v]=!colors[parent];
        for(int i=0;i<Adj[v].size();i++){
            if(colors[Adj[v][i]]==-1){
                if(!detect(Adj,Adj[v][i],v,colors))
                return 0;
            }
            if(colors[Adj[v][i]]==colors[v])
            return 0;
        }
        return 1;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>>Adj(V);
        for(int i=0;i<edges.size();i++){
            Adj[edges[i][0]].push_back(edges[i][1]);
            Adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>colors(V,-1);
        colors[0]=0;
        for(int i=1;i<V;i++){
            if(colors[i]==-1){
                if(!detect(Adj,i,0,colors))
                return 0;
            }
        }
        return 1;
    }
};