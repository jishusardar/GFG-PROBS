//Position this line where user code will be pasted.
class Solution {
  public:
    void DFS(int node,vector<vector<int>>&Adj,vector<bool>&visited,vector<int>&disc,vector<int>&low,int &count,stack<int>&s,vector<bool>&Instack,int &ans) {
    visited[node]=1;
    disc[node]=low[node]=count;
    s.push(node);
    Instack[node]=1;
    for (int i=0;i<Adj[node].size();i++) {
        int neib=Adj[node][i];
        if (!visited[neib]) {
            count++;
            DFS(neib,Adj,visited,disc,low,count,s,Instack,ans);
            low[node]=min(low[node],low[neib]);
        }
        else {
            if (Instack[neib])
                low[node]=min(low[node],disc[neib]);
        }
    }
    if (disc[node]==low[node]) {
            ans++;
            while (Instack[node]) {
                Instack[s.top()]=0;
                s.pop();
            }
            
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int V=adj.size();
        vector<bool>visited(V,0);
        vector<int>disc(V);
        vector<int>low(V);
        int count=0;
        stack<int>s;
        vector<bool>Instack(V,0);
        int ans=0;
        for(int i=0;i<V;i++){
            if(!visited[i])
            DFS(i,adj,visited,disc,low,count,s,Instack,ans);
        }
        return ans;
    }
};