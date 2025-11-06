//Position this line where user code will be pasted.
class Solution {
  public:
    void topology(int node,vector<vector<int>>&adj,vector<bool>&visited,stack<int>&s)
    {
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]])
            topology(adj[node][i],adj,visited,s);
        }
        s.push(node);
    }
    void DFS(int node,vector<vector<int>>&adj,vector<bool>&visited)
    {
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]])
            DFS(adj[node][i],adj,visited);
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        stack<int>s;
        vector<bool>visited(adj.size(),0);
        for(int i=0;i<adj.size();i++){
            if(!visited[i])
            topology(i,adj,visited,s);
        }
        
        vector<vector<int>>adj2(adj.size());
        for(int i=0;i<adj.size();i++){
            int u=i;
            for(int j=0;j<adj[i].size();j++){
                int v=adj[i][j];
                adj2[v].push_back(u);
            }
        }
        for(int i=0;i<visited.size();i++)
        visited[i]=0;
        int scc=0;
        while(!s.empty()){
            int node=s.top();
            s.pop();
            if(!visited[node]){
                scc++;
                DFS(node,adj2,visited);
            }
        }
        return scc;
    }
};