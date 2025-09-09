class Solution {
  public:
    void DFS(vector<vector<int>>&Adj,int v,vector<bool>&visited,stack<int>&st)
    {
        visited[v]=1;
        for(int i=0;i<Adj[v].size();i++){
            if(!visited[Adj[v][i]]){
                DFS(Adj,Adj[v][i],visited,st);
            }
        }
        st.push(v);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>Adj(V);
        stack<int>st;
        vector<bool>visited(V,0);
        for(int i=0;i<edges.size();i++){
            Adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i=0;i<V;i++){
            if(!visited[i]){
                DFS(Adj,i,visited,st);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
    }
};