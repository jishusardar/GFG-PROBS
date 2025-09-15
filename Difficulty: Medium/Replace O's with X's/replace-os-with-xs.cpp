// User function Template for C++

class Solution {
  public:
    int rows[4]={-1,0,0,1};
    int colms[4]={0,-1,1,0};
    int n;
    int m;
    bool valid(int i,int j)
    {
        return i>=0&&i<n&&j>=0&&j<m;
    }
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        n=mat.size();
        m=mat[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<mat.size();i++){
            if(mat[i][0]=='O')
            q.push({i,0});
        }
        for(int i=1;i<mat[0].size();i++){
            if(mat[mat.size()-1][i]=='O')
            q.push({mat.size()-1,i});
        }
        for(int i=1;i<mat.size();i++){
            if(mat[i][mat[0].size()-1]=='O')
            q.push({i,mat[0].size()-1});
        }
        for(int i=1;i<mat[0].size();i++){
            if(mat[0][i]=='O')
            q.push({0,i});
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            mat[i][j]='V';
            for(int k=0;k<4;k++){
                if(valid(i+rows[k],j+colms[k])&&mat[i+rows[k]][j+colms[k]]=='O'){
                    mat[i+rows[k]][j+colms[k]]='V';
                    q.push({i+rows[k],j+colms[k]});
                }
            }
        }
        vector<vector<char>>ans(mat.size(),vector<char>(mat[0].size(),'X'));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]=='V')
                ans[i][j]='O';
            }
        }
        return ans;
        
    }
};