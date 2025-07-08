// User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        vector<int>count(leaves+1,0);
        for(int i=0;i<N;i++){
            int num=frogs[i];
            if(num<=leaves&&count[num]==0){
                for(int j=num;j<=leaves;j+=num){
                    count[j]++;
                }
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
