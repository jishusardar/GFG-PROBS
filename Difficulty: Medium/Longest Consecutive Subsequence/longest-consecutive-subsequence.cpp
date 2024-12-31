//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        unordered_map<int,int>mm;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(mm[arr[i]]==0){
            if(mm[arr[i]-1])
            mm[arr[i]]=mm[arr[i]-1];
            mm[arr[i]]++;
            }
        }
        int ans=INT_MIN;
        for(auto i:mm){
            ans=max(ans,i.second);
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
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends