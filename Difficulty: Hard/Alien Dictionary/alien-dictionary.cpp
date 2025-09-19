class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        unordered_map<char,unordered_set<char>>Adj;
        vector<int>indegree(26,-1);
        for(int i=0;i<words.size()-1;i++){
            string s1=words[i],s2=words[i+1];
            int j=0,k=0;
            while(j<s1.size()&&k<s2.size()&&s1[j]==s2[k]){
                j++,k++;
            }
            if(j==s1.size())
            continue;
            if(k==s2.size())
            return "";
            Adj[s1[j]].insert(s2[k]);
        }
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                indegree[words[i][j]-'a']=0;
            }
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(indegree[i]==0)
            count++;
        }
        for(auto i:Adj){
            for(auto j:i.second){
                indegree[j-'a']++;
            }
        }
        queue<char>q;
        for(int i=0;i<26;i++){
            if(indegree[i]==0){
                char c='a'+i;
                q.push(c);
            }
        }
        string ans;
        while(!q.empty()){
            char node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto i:Adj[node]){
                indegree[i-'a']--;
                if(indegree[i-'a']==0)
                q.push(i);
            }
        }
        return ans.size()==count?ans:"";
        
    }
};