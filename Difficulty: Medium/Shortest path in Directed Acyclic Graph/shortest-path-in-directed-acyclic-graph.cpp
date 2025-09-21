// User function Template for C++
class Solution {
  public:
    void DFS(int node,vector<vector<pair<int,int>>>&Adj,vector<bool>&visited,stack<int>&st)
    {
        visited[node]=1;
        for(int i=0;i<Adj[node].size();i++){
            if(!visited[Adj[node][i].first]){
                DFS(Adj[node][i].first,Adj,visited,st);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>Adj(V);
        for(int i=0;i<edges.size();i++){
            Adj[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
        }
        vector<bool>visited(V,0);
        stack<int>st;
        DFS(0,Adj,visited,st);
        vector<int>dist(V,INT_MAX);
        dist[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(int i=0;i<Adj[node].size();i++){
                dist[Adj[node][i].first]=min(dist[node]+Adj[node][i].second,dist[Adj[node][i].first]);
            }
        }
        for(int i=0;i<dist.size();i++){
            if(dist[i]==INT_MAX)
            dist[i]=-1;
        }
        return dist;
    }
};
