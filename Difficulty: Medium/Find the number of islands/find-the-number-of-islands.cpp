class Solution {
  public:
    int rows[8]={1,-1,0,0,-1,1,1,-1};
    int colms[8]={0,0,1,-1,-1,1,-1,1};
    int r;
    int c;
    bool valid(int i,int j)
    {
        return i>=0&&i<r&&j>=0&&j<c;
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        queue<pair<int,int>>q;
        int nums=0;
        r=grid.size();
        c=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='L'){
                    q.push({i,j});
                    nums++;
                    grid[i][j]='W';
                    while(!q.empty()){
                        int row=q.front().first;
                        int colm=q.front().second;
                        q.pop();
                        for(int k=0;k<8;k++){
                            if(valid(row+rows[k],colm+colms[k])&&grid[row+rows[k]][colm+colms[k]]=='L'){
                                grid[row+rows[k]][colm+colms[k]]='W';
                                q.push({row+rows[k],colm+colms[k]});
                            }
                        }
                    }
                }
            }
        }
        return nums;
    }
};