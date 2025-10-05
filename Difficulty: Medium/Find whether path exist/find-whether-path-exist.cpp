
class Solution {
  public:
    // Function to find whether a path exists from the source to destination.
    int rows[4]={-1,1,0,0};
    int colms[4]={0,0,-1,1};
    bool valid(int i,int j,int n){
        return i>=0&&j>=0&&i<n&&j<n;
    }
    bool is_Possible(vector<vector<int>>& grid) {
        // code here
        queue<pair<int,int>>q;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                q.push({i,j});
            }
        }
        if(q.empty())
        return 0;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                if(valid(i+rows[k],j+colms[k],n)){
                    if(grid[i+rows[k]][j+colms[k]]==2)
                    return 1;
                    if(grid[i+rows[k]][j+colms[k]]==3){
                        grid[i+rows[k]][j+colms[k]]=0;
                        q.push({i+rows[k],j+colms[k]});
                    }
                }
            }
        }
        return 0;
    }
};