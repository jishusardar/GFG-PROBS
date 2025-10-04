// User function Template for C++

class Solution {
  public:
    int rows[4]={1,-1,0,0};
    int colms[4]={0,0,-1,1};
    bool valid(int i,int j,int N,int M)
    {
        return i>=0&&j>=0&&i<N&&j<M;
    }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(!A[0][0])
        return -1;
        if(X==0&&Y==0)
        return 0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        A[0][0]=0;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second.first;
            int step=q.front().second.second;
            q.pop();
            for(int k=0;k<4;k++){
                if(valid(i+rows[k],j+colms[k],N,M)&&A[i+rows[k]][j+colms[k]]==1){
                    if(i+rows[k]==X&&j+colms[k]==Y)
                    return step+1;
                    A[i+rows[k]][j+colms[k]]=0;
                    q.push({i+rows[k],{j+colms[k],step+1}});
                }
            }
        }
        return -1;
    }
};