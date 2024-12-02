//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int minChar(string s){
    string str=s;
    reverse(str.begin(),str.end());
    s+='$';
    s+=str;
    vector<int>lps(s.size(),0);
    int pre=0,suff=1;
    while(suff<s.size())
    {
        if(s[pre]==s[suff])
        {
            lps[suff]=pre+1;
            pre++,suff++;
        }
        else
        {
            if(pre==0)
            {
                lps[suff]=0;
                suff++;
            }
            else
            pre=lps[pre-1];
        }
    }
    return str.size()-lps[s.size()-1];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends