class Solution {
  public:
    void DFS(int node,vector<int>adj[],vector<bool>&visited)
    {
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]])
            DFS(adj[node][i],adj,visited);
        }
    }
    int isEulerCircuit(int V, vector<int> adj[]) {
        // Code here
        vector<int>degree(V,0);
        int odd=0;
        for(int i=0;i<V;i++){
            degree[i]=adj[i].size();
            if(degree[i]%2)
            odd++;
        }
        if(odd!=0&&odd!=2)
        return 0;
        vector<bool>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                DFS(i,adj,visited);
                break;
            }
        }
        for(int i=0;i<V;i++){
            if(degree[i]!=0&&visited[i]==0)
            return 0;
        }
        if(odd)
        return 1;
        return 2;
    }
};