class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        
        int i=0,ans=0;
        while(i<=s.size()-k){
            int x=k;
            vector<int>count(26,0);
            int diff=0;
            int j=i;
            while(x--){
                if(count[s[j]-'a']==0)
                diff++;
                count[s[j]-'a']++;
                j++;
            }
            if(diff==k-1)
            ans++;
            i++;
        }
        return ans;
        
    }
};