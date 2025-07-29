class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int temp=0;
        for(int i=0;i<mat.size();i++){
            int sum=0;
            for(int j=0;j<mat[0].size();j++)
            sum+=mat[i][j];
            temp=max(temp,sum);
        }
        for(int i=0;i<mat[0].size();i++){
            int sum=0;
            for(int j=0;j<mat.size();j++)
            sum+=mat[j][i];
            temp=max(temp,sum);
        }
        int ans=0;
        for(int i=0;i<mat.size();i++){
            int sum=0;
            for(int j=0;j<mat[0].size();j++){
                sum+=mat[i][j];
            }
            ans+=temp-sum;
        }
        int fans=0;
        for(int i=0;i<mat[0].size();i++){
            int sum=0;
            for(int j=0;j<mat.size();j++){
                sum+=mat[j][i];
            }
            fans+=temp-sum;
        }
        return ans==fans?ans:min(ans,fans);
    }
};