class Solution {
  public:
    bool detect(vector<vector<int>>&Adjmat,int v,vector<bool>&visited)
    {
        queue<pair<int,int>>q;
        q.push(make_pair(v,-1));
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(int i=0;i<Adjmat[node].size();i++){
                if(parent==Adjmat[node][i])
                continue;
                if(visited[Adjmat[node][i]])
                return 1;
                visited[Adjmat[node][i]]=1;
                q.push(make_pair(Adjmat[node][i],node));
            }
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
          if(!visited[i]&&detect(Adjmat,i,visited))
          return 1;
        }
        return 0;
    }
};