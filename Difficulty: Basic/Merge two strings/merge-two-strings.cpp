//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

string merge (string s1, string s2);

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << merge (s1, s2) << endl;
    
cout << "~" << "\n";
}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends



string merge(string S1, string S2) {
    // your code here
    string ans;
    int i=0,j=0;
    while(i<S1.size()&&j<S2.size()){
        ans.push_back(S1[i]);
        ans.push_back(S2[j]);
        i++,j++;
    }
    while(i<S1.size()){
        ans.push_back(S1[i]);
        i++;
    }
    while(j<S2.size()){
        ans.push_back(S2[j]);
        j++;
    }
    return ans;
}