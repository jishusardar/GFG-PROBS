//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        stack<int>st;
        vector<int>ans(arr.size(),0);
        for(int i=0;i<arr.size();i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                int index=st.top();
                st.pop();
                if(st.empty()){
                    int range=i;
                    ans[range-1]=max(ans[range-1],arr[index]);
                }
                else{
                    int range=i-st.top()-1;
                    ans[range-1]=max(ans[range-1],arr[index]);
                }
            }
            st.push(i);
        }
        while(!st.empty()){
            int index=st.top();
            st.pop();
            if(st.empty()){
                int range=arr.size();
                ans[range-1]=max(ans[range-1],arr[index]);
            }
            else{
                int range=arr.size()-st.top()-1;
                ans[range-1]=max(ans[range-1],arr[index]);
            }
        }
        for(int i=arr.size()-2;i>=0;i--){
            ans[i]=max(ans[i],ans[i+1]);
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
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends