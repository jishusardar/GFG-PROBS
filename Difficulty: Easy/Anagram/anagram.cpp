//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        vector<int>chars(256,0);
        for(int i=0;i<s1.size();i++){
            chars[s1[i]]++;
        }
        for(int i=0;i<s2.size();i++){
            chars[s2[i]]++;
        }
        for(int i=0;i<256;i++){
            if(chars[i]!=0)
            {
                if(chars[i]%2)
                return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends