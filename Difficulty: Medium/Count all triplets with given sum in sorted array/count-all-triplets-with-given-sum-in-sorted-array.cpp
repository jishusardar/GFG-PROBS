//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int count=0;
        int n=arr.size();
        for(int i=0;i<n-2;i++){
            int start=i+1,end=n-1;
            while(start<end){
              if(arr[start]+arr[end]+arr[i]>target)
              end--;
              else if(arr[start]+arr[end]+arr[i]<target)
              start++;
              else if(arr[start]+arr[end]+arr[i]==target){
                    count++;
                    int temp=start+1;
                    while(temp<end&&arr[temp]==arr[temp-1]){
                        count++;
                        temp++;
                    }
                    end--;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends