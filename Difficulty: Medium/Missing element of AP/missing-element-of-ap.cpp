//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int d=INT_MAX;
        for(int i=0;i<arr.size()-1;i++){
            d=min(d,arr[i+1]-arr[i]);
        }
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]+d!=arr[i+1])
            return arr[i]+d;
        }
        return arr[arr.size()-1]+d;
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

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends