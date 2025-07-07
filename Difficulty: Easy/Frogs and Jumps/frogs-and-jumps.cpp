// User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        vector<int>count(leaves+1,0);
        for(int i=0;i<N;i++){
            int f=frogs[i];
            if(f<=leaves&&!count[f])
            {
                for(int j=f;j<=leaves;j+=f)
                count[j]+=1;
            }
        }
        int ans=0;
        for(int i=1;i<=leaves;i++){
            if(count[i]==0)
            ans++;
        }
        return ans;
    }
};
