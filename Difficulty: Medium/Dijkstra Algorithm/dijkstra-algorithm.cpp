// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>Adj(V);
        for(int i=0;i<edges.size();i++){
            Adj[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
            Adj[edges[i][1]].push_back(make_pair(edges[i][0],edges[i][2]));
        }
        vector<bool>visited(V,0);
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push(make_pair(0,src));
        while(!q.empty()){
            int index=q.top().second;
            q.pop();
            visited[index]=1;
            for(int i=0;i<Adj[index].size();i++){
                int v=Adj[index][i].first;
                int weight=Adj[index][i].second;
                if(!visited[v]&&dist[v]>dist[index]+weight){
                    dist[v]=dist[index]+weight;
                    q.push(make_pair(dist[v],v));
                }
            }
        }
        return dist;
    }
};