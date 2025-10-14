// User function Template for C++

class Solution {
  public:
    void DFS(int node,vector<vector<int>>&Adj,vector<bool>&visited)
    {
        visited[node]=1;
        for(int i=0;i<Adj[node].size();i++){
            if(!visited[Adj[node][i]])
            DFS(Adj[node][i],Adj,visited);
        }
    }
    int isCircle(vector<string> &arr) {
        // code here
        vector<vector<int>>Adj(26,vector<int>());
        vector<int>in(26,0);
        vector<int>out(26,0);
        for(int i=0;i<arr.size();i++){
            string str=arr[i];
            int u=str[0]-'a';
            int v=str[str.size()-1]-'a';
            Adj[u].push_back(v);
            in[v]++;
            out[u]++;
        }
        for(int i=0;i<26;i++){
            if(in[i]!=out[i])
            return 0;
        }
        vector<bool>visited(26,0);
        DFS(arr[0][0]-'a',Adj,visited);
        for(int i=0;i<26;i++){
            if(in[i]&&!visited[i])
            return 0;
        }
        return 1;
    }
};