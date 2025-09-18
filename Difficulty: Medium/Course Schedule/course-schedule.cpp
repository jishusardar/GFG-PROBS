class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> pre) {
        // code here
        vector<int>ans;
        queue<int>q;
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            indeg[pre[i][0]]++;
        }
        for(int i=0;i<n;i++){
            if(indeg[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0;i<adj[node].size();i++){
                indeg[adj[node][i]]--;
                if(indeg[adj[node][i]]==0)
                q.push(adj[node][i]);
            }
        }
        if(ans.size()==n)
        return ans;
        return {};
    }
};