class Solution {
  public:
     bool detect(vector<vector<int>>&Adjmat,int v,vector<bool>&visited)
    {
        vector<int>indeg(v,0);
        for(int i=0;i<Adjmat.size();i++)
        for(int j=0;j<Adjmat[i].size();j++)
        indeg[Adjmat[i][j]]++;
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indeg[i]==0)
            q.push(i);
        }
        if(q.empty())
        return 1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            visited[node]=1;
            for(int i=0;i<Adjmat[node].size();i++){
                indeg[Adjmat[node][i]]--;
                if(indeg[Adjmat[node][i]]==0)
                q.push(Adjmat[node][i]);
            }
        }
        bool flag=false;
        for(int i=0;i<visited.size();i++){
            if(visited[i]==0){
                flag=true;
                break;
            }
        }
        if(q.empty()&&flag)
        return 1;
        return 0;
        
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>Adjmat(V);
        for(int i=0;i<edges.size();i++){
            Adjmat[edges[i][0]].push_back(edges[i][1]);
        }
        vector<bool>visited(V,0);
        return detect(Adjmat,V,visited);
        
    }
};