class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n=mat.size();
        vector<pair<int,pair<int,int>>>temp;
        for(int i=0;i<n;i++){
            temp.push_back(make_pair(mat[i][0],make_pair(i,0)));
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q(temp.begin(),temp.end());
        int ans;
        while(k--){
            pair<int,pair<int,int>>p=q.top();
            q.pop();
            ans=p.first;
            int i=p.second.first;
            int j=p.second.second;
            if(j+1<n){
                q.push(make_pair(mat[i][j+1],make_pair(i,j+1)));
            }
        }
        return ans;
    }
};
