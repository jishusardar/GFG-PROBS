//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void permute(string &s,string &temp,vector<bool>&visit,set<string>&ans)
    {
        if(temp.size()==s.size()){
            ans.insert(temp);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(visit[i]==0){
                visit[i]=1;
                temp.push_back(s[i]);
                permute(s,temp,visit,ans);
                visit[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        set<string>ans;
        string temp;
        vector<string>ansf;
        vector<bool>visit(s.size(),0);
        permute(s,temp,visit,ans);
        for(auto i:ans){
            ansf.push_back(i);
        }
        return ansf;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends