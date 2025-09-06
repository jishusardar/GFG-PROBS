class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int>ans;
        queue<int>q;
        vector<bool>visited(adj.size(),0);
        q.push(0);
        visited[0]=1;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(int i=0;i<adj[temp].size();i++){
                if(!visited[adj[temp][i]]){
                    visited[adj[temp][i]]=1;
                    q.push(adj[temp][i]);
                }
            }
        }
        return ans;
    }
};