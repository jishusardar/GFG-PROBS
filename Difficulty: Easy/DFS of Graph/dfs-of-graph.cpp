class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>ans;
        vector<bool>vis(adj.size(),0);
        stack<int>st;
        st.push(0);
        while(!st.empty()){
            int v=st.top();
            st.pop();
            if(!vis[v])
            ans.push_back(v);
            vis[v]=1;
            for(int i=adj[v].size()-1;i>=0;i--){
                if(!vis[adj[v][i]]){
                    st.push(adj[v][i]);
                }
            }
        }
        return ans;
    }
};