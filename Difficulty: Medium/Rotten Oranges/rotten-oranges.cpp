class Solution {
  public:
    int rows[4]={-1,1,0,0};
    int colms[4]={0,0,-1,1};
    int n;
    int m;
    bool valid(int i,int j)
    {
        return i>=0&&i<n&&j>=0&&j<m;
    }
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        queue<pair<int,int>>q;
        int timer=0;
        n=mat.size();
        m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2)
                q.push(make_pair(i,j));
            }
        }
        while(!q.empty()){
            int size=q.size();
            timer++;
            while(size--){
                int ni=q.front().first;
                int nj=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    if(valid(ni+rows[k],nj+colms[k])&&mat[ni+rows[k]][nj+colms[k]]==1){
                        mat[ni+rows[k]][nj+colms[k]]=2;
                        q.push(make_pair(ni+rows[k],nj+colms[k]));
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1)
                return -1;
            }
        }
        return timer>0?timer-1:0;
    }
};