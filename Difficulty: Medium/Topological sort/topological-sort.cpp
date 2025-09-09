class Solution {
  public:
    void BFS(vector<vector<int>>&Adj,vector<int>&ans,int v)
    {
        vector<int>indegnodes(v,0);
        queue<int>q;
        for(int i=0;i<Adj.size();i++){
            for(int j=0;j<Adj[i].size();j++){
                indegnodes[Adj[i][j]]++;
            }
        }
        for(int i=0;i<v;i++){
            if(indegnodes[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0;i<Adj[node].size();i++){
                indegnodes[Adj[node][i]]--;
                if(indegnodes[Adj[node][i]]==0){
                    q.push(Adj[node][i]);
                }
            }
        }
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>Adj(V);
        stack<int>st;
        vector<bool>visited(V,0);
        for(int i=0;i<edges.size();i++){
            Adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int>ans;
        BFS(Adj,ans,V);
        return ans;
        
    }
};