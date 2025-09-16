// User function Template for C++

class Solution {
  public:
  int n;
  int m;
    bool valid(int i,int j)
    {
        return i>=0&&i<n&&j>=0&&j<m;
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int count=0;
        queue<pair<int,int>>q;
        n=adj.size();
        m=adj.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(adj[i][j]==1){
                    q.push({i,j});
                    count++;
                    while(!q.empty()){
                        int ni=q.front().first;
                        int nj=q.front().second;
                        adj[ni][nj]=0;
                        q.pop();
                        for(int k=0;k<m;k++){
                            if(valid(ni,k)&&adj[ni][k]==1){
                                adj[ni][k]=0;
                                q.push({k,ni});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};