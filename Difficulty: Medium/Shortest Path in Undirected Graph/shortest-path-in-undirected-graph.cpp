class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& Adj, int src) {
        // code here
        vector<bool>visited(Adj.size(),0);
        vector<int>dist(Adj.size(),-1);
        dist[src]=0;
        visited[src]=1;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<Adj[node].size();i++){
                int neigh=Adj[node][i];
                if(!visited[neigh]){
                    visited[neigh]=1;
                    dist[neigh] = dist[node] + 1;
                    q.push(Adj[node][i]);
                }
            }
        }
        return dist;
    }
};