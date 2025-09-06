class Solution {
  public:
    void traversal(vector<vector<int>>& adj,int v,vector<int>&ans,vector<bool>&vis)
    {
        vis[v]=1;
        ans.push_back(v);
        for(int i=0;i<adj[v].size();i++){
            if(!vis[adj[v][i]]){
                traversal(adj,adj[v][i],ans,vis);
            }
        }
        return;
        
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>ans;
        vector<bool>vis(adj.size(),0);
  
        traversal(adj,v,ans,vis);
        return ans;
    }
};