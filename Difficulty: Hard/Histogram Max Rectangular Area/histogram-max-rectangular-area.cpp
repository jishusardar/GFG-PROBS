//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code herest;
        int n=arr.size();
        stack<int>st;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            
            while(!st.empty()&&arr[st.top()]>arr[i]){
                int height=arr[st.top()];
                int index=st.top();
                st.pop();
                if(st.empty()){
                    ans=max(ans,height*(i));
                }
                else{
                    ans=max(ans,height*(i-st.top()-1));
                }
            }
            st.push(i);
            
        }
        while(!st.empty()){
            int height=arr[st.top()];
            st.pop();
            if(st.empty()){
                ans=max(ans,height*(n));
            }
            else{
                ans=max(ans,height*(n-st.top()-1));
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends