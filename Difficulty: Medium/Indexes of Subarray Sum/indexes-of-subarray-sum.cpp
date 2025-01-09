//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        vector<int>ans;
        unordered_map<int,int>mm;
        int sums=0;
        for(int i=0;i<arr.size();i++){
            sums+=arr[i];
            mm[sums]=i+1;
        }
        int prefix=0;
        for(int i=0;i<arr.size();i++){
            prefix+=arr[i];
            if(prefix==target&&!ans.size()){
            ans.push_back(i+1);
            ans.push_back(1);
            }
            else if(mm[prefix-target]&&!ans.size()){
            ans.push_back(i+1);
            ans.push_back(mm[prefix-target]);
                if(prefix-target!=0){
                    ans[ans.size()-1]++;
                }            
            }
        }
        if(!ans.size()){
            ans.push_back(-1);
            return ans;
        }
        reverse(ans.begin(),ans.end());
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
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends