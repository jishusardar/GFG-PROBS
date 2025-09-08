class Solution {
  public:
    bool detect(vector<vector<int>>& Adjmat, int start, vector<bool>& visited) {
        queue<pair<int,int>> q; 
        q.push({start, -1});
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int neigh : Adjmat[node]) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q.push({neigh, node});
                } 
                else if (neigh != parent) {
                    return true; // cycle found
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>Adjmat(V);
        for(int i=0;i<edges.size();i++){
            Adjmat[edges[i][0]].push_back(edges[i][1]);
            Adjmat[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visited(Adjmat.size(),0);
         for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (detect(Adjmat, i, visited))
                    return true;
            }
        }
        return false;
    }
};