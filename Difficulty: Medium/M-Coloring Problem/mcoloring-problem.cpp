class Solution {
  public:
    bool DFS(int node,vector<vector<bool>>&graph,int v,int m,vector<int>&color){
        for(int i=0;i<m;i++){
            bool Ispos=1;
            for(int j=0;j<v;j++){
                if(graph[node][j]&&color[j]==i){
                    Ispos=0;
                    break;
                }
            }
            if(!Ispos)
            continue;
            color[node]=i;
            Ispos=1;
            for(int j=0;j<v;j++){
                if(graph[node][j]&&color[j]==-1){
                    if(!DFS(j,graph,v,m,color)){
                        Ispos=0;
                        break;
                    }
                }
            }
            if(Ispos)
            return 1;
            color[node]=-1;
        }
        return 0;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<int>color(v,-1);
        vector<vector<bool>>graph(v,vector<bool>(v,0));
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]][edges[i][1]]=1;
        }
        for(int i=0;i<v;i++){
            if(!DFS(i,graph,v,m,color))
            return 0;
        }
        return 1;
        
        
    }
};