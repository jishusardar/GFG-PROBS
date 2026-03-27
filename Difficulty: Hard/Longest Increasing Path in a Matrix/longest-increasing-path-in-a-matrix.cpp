// User function Template for C++

class Solution {
  public:
    int rows[4]={0,0,1,-1};
    int colms[4]={1,-1,0,0};
    bool check(int i,int j,int n,int m){
        return i<n&&i>=0&&j<m&&j>=0;
    }
    void DFS(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&paths,int n,int m){
        paths[i][j]=1;
        for(int k=0;k<4;k++){
            if(check(i+rows[k],j+colms[k],n,m)&&matrix[i+rows[k]][j+colms[k]]>matrix[i][j]){
                if(!paths[i+rows[k]][j+colms[k]])
                DFS(i+rows[k],j+colms[k],matrix,paths,n,m);
                paths[i][j]=max(paths[i][j],1+paths[i+rows[k]][j+colms[k]]);
            }
        }
    }
    int longIncPath(vector<vector<int>> &matrix, int n, int m) {
        // Code here
        vector<vector<int>>paths(n,vector<int>(m,0));
        int total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!paths[i][j])
                DFS(i,j,matrix,paths,n,m);
                total=max(total,paths[i][j]);
            }
        }
        return total;
    }
};