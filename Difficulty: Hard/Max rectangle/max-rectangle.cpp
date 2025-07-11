class Solution {
  public:
    int areofrect(vector<int>&height)
    {
        int ans=0;
        stack<int>st;
        int n=height.size();
        for(int i=0;i<n;i++){
            while(!st.empty()&&height[st.top()]>height[i]){
                int index=st.top();
                st.pop();
                if(!st.empty())
                ans=max(ans,height[index]*(i-st.top()-1));
                else
                ans=max(ans,height[index]*i);
            }
            st.push(i);
        }
        while(!st.empty()){
            int index=st.top();
            st.pop();
            if(!st.empty())
            ans=max(ans,height[index]*(n-st.top()-1));
            else
            ans=max(ans,height[index]*n);
        }
        return ans;
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int ans=0;
        vector<int>height(mat[0].size(),0);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0)
                height[j]=0;
                else
                height[j]+=1;
            }
            ans=max(ans,areofrect(height));
        }
        return ans;
    }
};