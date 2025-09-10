class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>>Adj(V);
        for(int i=0;i<edges.size();i++){
            Adj[edges[i][0]].push_back(edges[i][1]);
            Adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        q.push(0);
        vector<int>colors(V,-1);
        colors[0]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<Adj[node].size();i++){
                if(colors[Adj[node][i]]==-1)
                {
                    q.push(Adj[node][i]);
                    colors[Adj[node][i]]=!colors[node];
                }
                if(colors[Adj[node][i]]==colors[node])
                return 0;
            }
        }
        return 1;
    }
};