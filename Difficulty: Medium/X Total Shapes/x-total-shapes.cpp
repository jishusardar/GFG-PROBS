

class Solution {
  public:
    // Function to find the number of 'X' total shapes.
    int rows[4]={0,0,-1,1};
    int colms[4]={-1,1,0,0};
    int n;
    int m;
    bool valid(int i,int j)
    {
        return i>=0&&i<n&&j>=0&&j<m;
    }
    int xShape(vector<vector<char>>& grid) {
        // Code here
        int count=0;
        n=grid.size();
        m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X'){
                    q.push({i,j});
                    count++;
                    while(!q.empty()){
                        int ni=q.front().first;
                        int nj=q.front().second;
                        q.pop();
                        grid[ni][nj]='O';
                        for(int k=0;k<4;k++){
                            if(valid(ni+rows[k],nj+colms[k])&&grid[ni+rows[k]][nj+colms[k]]=='X'){
                                grid[ni+rows[k]][nj+colms[k]]='O';
                                q.push({ni+rows[k],nj+colms[k]});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};