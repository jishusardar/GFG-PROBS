//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        vector<int>ans(arr.size(),0);
        int mul=1;
        int p=0;
        bool flag=1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0)
            mul*=arr[i];
            else{
            p++;
            flag=0;
            }
        }
        if(p>1)
        return ans;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0&&flag==false)
            ans[i]=0;
            else{
                if(arr[i]==0){
                    ans[i]=mul;
                }
                else
                ans[i]=mul/arr[i];
            }
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
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends