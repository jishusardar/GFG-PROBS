//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        vector<int>pos;
        vector<int>neg;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0)
            pos.emplace_back(arr[i]);
            else
            neg.emplace_back(arr[i]);
        }
        vector<int>ans;
        int i=0,j=0;
        while(i<pos.size()&&j<neg.size()){
            ans.emplace_back(pos[i]);
            ans.emplace_back(neg[j]);
            i++,j++;
        }
        while(i<pos.size()){
            ans.emplace_back(pos[i]);
            i++;
        }
        while(j<neg.size()){
            ans.emplace_back(neg[j]);
            j++;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=ans[i];
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends