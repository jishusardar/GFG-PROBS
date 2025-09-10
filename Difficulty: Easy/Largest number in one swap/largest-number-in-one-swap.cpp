class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        bool flag=true;
        char c=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]!=c)
            flag=false;
        }
        if(flag)
        return s;
        vector<int>count(s.size());
        int maxi=s[s.size()-1]-'0';
        int index=s.size()-1;
        count[s.size()-1]=s.size()-1;
        for(int i=s.size()-2;i>=0;i--){
            int temp=s[i]-'0';
            if(temp>maxi){
                maxi=temp;
                index=i;
            }
            count[i]=index;
        }
        for(int i=0;i<s.size();i++){
            int temp=s[i]-'0';
            if(s[count[i]]!=s[i]){
                swap(s[i],s[count[i]]);
                break;
            }
        }
        return s;
        
    }
};