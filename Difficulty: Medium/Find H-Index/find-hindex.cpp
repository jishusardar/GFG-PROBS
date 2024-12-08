//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& cit) {
        // code here
        vector<int>arr(cit.size()+1,0);
        for(int i=0;i<cit.size();i++){
            if(cit[i]!=0&&cit[i]>=cit.size())
            arr[cit.size()]++;
            else
            arr[cit[i]]++;
        }
        int n=cit.size();
        int temp=arr[n];
        while(temp<n&&n>=0){
            n--;
            temp+=arr[n];
        }
        return n;
    }
};

//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends