// User function Template for C++

class Solution {
  public:
    void DFS(int node,int parent,vector<int>&disc,vector<int>&low,vector<bool>&art,vector<bool>&visited,int &count,vector<int>adj[])
    {
        visited[node]=1;
        disc[node]=low[node]=count;
        int child=0;
        for(int i=0;i<adj[node].size();i++){
            int neigh=adj[node][i];
            if(neigh==parent)
            continue;
            else if(visited[neigh]){
                low[node]=min(low[node],disc[neigh]);
            }
            else{
                child++;
                count++;
                DFS(neigh,node,disc,low,art,visited,count,adj);
                if(disc[node]<=low[neigh]&&parent!=-1){
                    art[node]=1;
                }
                low[node]=min(low[node],low[neigh]);
            }
        }
        if(child>1&&parent==-1)
        art[node]=1;
    }
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        vector<int>disc(V);
        vector<int>low(V);
        vector<bool>art(V,0);
        vector<bool>visited(V,0);
        int count=0;
        DFS(0,-1,disc,low,art,visited,count,adj);
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(art[i])
            ans.push_back(i);
        }
        if(ans.size()==0)
        return {-1};
        return ans;
    }
};