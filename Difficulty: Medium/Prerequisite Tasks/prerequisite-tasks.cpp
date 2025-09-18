class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& pre) {
        // Code here
        queue<int>q;
        vector<int>count(N,0);
        int n=pre.size();
        vector<vector<int>>adj(N);
        for(int i=0;i<n;i++){
            adj[pre[i].second].push_back(pre[i].first);
            count[pre[i].first]++;
        }
        for(int i=0;i<N;i++){
            if(count[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            N--;
            for(int i=0;i<adj[node].size();i++){
                count[adj[node][i]]--;
                if(count[adj[node][i]]==0)
                q.push(adj[node][i]);
            }
        }
       if(N)
       return 0;
       return 1;
    }
};