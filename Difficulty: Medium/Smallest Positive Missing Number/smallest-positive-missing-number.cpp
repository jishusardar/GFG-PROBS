//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        unordered_map<int,int>mm;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            mm[arr[i]]+=1;
        }
        if(!mm[1])
        return 1;
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]>0&&arr[i]>0){
                if(arr[i]-arr[i-1]!=0&&arr[i]-arr[i-1]!=1){
                    return arr[i-1]+1;
                }
            }
        }
        return arr[arr.size()-1]+1;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
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
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends