//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(st.empty())
            st.push(s[i]);
            else if(st.top()=='('&&s[i]==')'){
                st.pop();
            }
            else if(st.top()=='{'&&s[i]=='}')
            st.pop();
            else if(st.top()=='['&&s[i]==']')
            st.pop();
            else
            st.push(s[i]);
        }
        if(st.empty())
        return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends