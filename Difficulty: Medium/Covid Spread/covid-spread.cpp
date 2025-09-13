// User function Template for C++

class Solution {
  public:
    int rows[4]={1,-1,0,0};
    int colms[4]={0,0,1,-1};
    int n,m;
    bool valid(int i,int j)
    {
        return i>=0&&i<n&&j>=0&&j<m;
    }
    int helpaterp(vector<vector<int>> hospital) {
        // code here
        queue<pair<int,int>>q;
        n=hospital.size();
        m=hospital[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(hospital[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        if(q.empty())
        return 0;
        int timer=0;
        while(!q.empty()){
            timer++;
            int num=q.size();
            while(num--){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                if(valid(i+rows[k],j+colms[k])&&hospital[i+rows[k]][j+colms[k]]==1){
                    hospital[i+rows[k]][j+colms[k]]=2;
                    q.push({i+rows[k],j+colms[k]});
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(hospital[i][j]==1)
            return -1;
        }
    }
    return timer-1;
    }
};
