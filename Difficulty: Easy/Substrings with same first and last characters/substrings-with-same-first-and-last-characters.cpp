//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        bool same=1;
        for(int i=0;i<s.size();i++){
            if(s[i]!=s[0])
            same=0;
        }
        if(same){
            int count=s.size();
            if(count%2){
                if(count==1)
                return 1;
                int num=count/2;
                if(count%2)
                num++;
                return count*num;
            }
            else{
                if(count==2)
                return 3;
                int num=count/2;
                return count*num+num;
            }
        }
        int count=s.size();
        unordered_map<char,int>mm;
        for(int i=0;i<s.size();i++){
            if(mm.find(s[i])!=mm.end())
            count+=mm[s[i]];
            mm[s[i]]++;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.countSubstring(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends