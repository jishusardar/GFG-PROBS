//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void stringtop(map<string,vector<string>>&mm,string s)
    {
        string temp=s;
        sort(s.begin(),s.end());
        mm[s].push_back(temp);
    }
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<vector<string>>ans;
        map<string,vector<string>>mm;
        for(int i=0;i<arr.size();i++){
            string temp=arr[i];
            stringtop(mm,temp);
        }
        for(auto i:mm){
            ans.push_back(i.second);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends