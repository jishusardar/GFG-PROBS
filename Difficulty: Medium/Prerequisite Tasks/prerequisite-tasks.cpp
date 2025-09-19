class Solution {
  public: 
    bool DFS(int node,vector<bool>&paths,vector<bool>&visited,vector<vector<int>>&Adj)
    {
        paths[node]=1;
        visited[node]=1;
        for(int i=0;i<Adj[node].size();i++){
            if(paths[Adj[node][i]])
            return 1;
            if(visited[Adj[node][i]])
            continue;
            if(DFS(Adj[node][i],paths,visited,Adj))
            return 1;
        }
        paths[node]=0;
        return 0;
    }
    bool isPossible(int N, int P, vector<pair<int, int> >& pre) {
        // Code here
        vector<bool>visited(N,0);
        vector<bool>paths(N,0);
        vector<vector<int>>Adj(N);
        for(int i=0;i<pre.size();i++){
            Adj[pre[i].second].push_back(pre[i].first);
        }
        for(int i=0;i<N;i++){
            if(!visited[i]){
                if(DFS(i,paths,visited,Adj))
                return 0;
            }
        }
        return 1;
    }
};