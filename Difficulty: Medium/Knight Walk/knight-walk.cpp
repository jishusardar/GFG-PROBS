class Solution {
  public:
    int rows[8]={-1,1,-1,1,2,2,-2,-2};
    int colms[8]={2,2,-2,-2,-1,1,-1,1};
    bool valid(int i,int j,int N)
    {
        return i>=0&&j>=0&&i<N&&j<N;
    }
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
        // Code here
        TargetPos[0]--;
        TargetPos[1]--;
        KnightPos[0]--;
        KnightPos[1]--;
        if(TargetPos[0]==KnightPos[0]&&KnightPos[1]==TargetPos[1])
        return 0;
        vector<vector<int>>grid(N,vector<int>(N,0));
        queue<pair<int,int>>q;
        int step=0;
        q.push({KnightPos[0],KnightPos[1]});
        grid[KnightPos[0]][KnightPos[1]]=1;
        while(!q.empty()){
            int count=q.size();
            while(count--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<8;k++){
                    if(valid(i+rows[k],j+colms[k],N)&&!grid[i+rows[k]][j+colms[k]]){
                        if(TargetPos[0]==i+rows[k]&&TargetPos[1]==j+colms[k])
                        return step+1;
                        grid[i+rows[k]][j+colms[k]]=1;
                        q.push({i+rows[k],j+colms[k]});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};