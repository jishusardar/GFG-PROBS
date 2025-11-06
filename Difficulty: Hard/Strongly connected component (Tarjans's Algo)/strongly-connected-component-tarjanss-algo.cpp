// User function template for C++

class Solution {
  public:
    // Function to return a list of lists of integers denoting the members
    // of strongly connected components in the given graph.
    void DFS(int node,vector<int>adj[],vector<bool>&visited,vector<int>&disc,vector<int>&low,int &count,stack<int>&s,vector<bool>&Instack,vector<vector<int>>&ans)
    {
        visited[node]=1;
        disc[node]=low[node]=count;
        s.push(node);
        Instack[node]=1;
        for(int j=0;j<adj[node].size();j++){
            int neib=adj[node][j];
            if(!visited[neib]){
                count++;
                DFS(neib,adj,visited,disc,low,count,s,Instack,ans);
                low[node]=min(low[node],low[neib]);
            }
            else{
                if(Instack[neib])
                low[node]=min(low[node],disc[neib]);
            }
        }
        if(disc[node]==low[node]){
            vector<int>temp;
            while(Instack[node]){
                temp.push_back(s.top());
                Instack[s.top()]=0;
                s.pop();
            }
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
    }
    vector<vector<int>> tarjans(int v, vector<int> adj[]) {
        // code here
        vector<vector<int>>ans;
        vector<int>disc(v);
        vector<int>low(v);
        vector<bool>visited(v,0);
        int count=0;
        stack<int>s;
        vector<bool>Instack(v,0);
        for(int i=0;i<v;i++){
            if(!visited[i])
            DFS(i,adj,visited,disc,low,count,s,Instack,ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};