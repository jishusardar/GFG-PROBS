//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    char addproto(char c1,char c2){
        if(c1=='0'&&c2=='0')
        return '0';
        else if(c1=='0'&&c2=='1')
        return '1';
        else if(c1=='1'&&c2=='0')
        return '1';
        else if(c1=='1'&&c2=='1')
        return '0';
    }
    string addBinary(string s1, string s2) {
        // your code here
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        string ans="";
        bool rem=0;
        int i=0,j=0;
        while(i<s1.size()&&j<s2.size()){
            char c=addproto(s1[i],s2[j]);
            if(rem){
            if(c=='1'){
                if(s1[i]!='1')
                s1[i]='1';
                else if(s2[j]!='1')
                s2[j]='1';
            }
            c=addproto(c,'1');
            }
            if(s1[i]=='1'&&s2[j]=='1')
            rem=1;
            else
            rem=0;
            ans+=c;
            i++,j++;
        }
        while(i<s1.size()){
            char c=s1[i];
            if(rem){
                if(c=='1')
                rem=1;   
                else
                rem=0;
            c=addproto(c,'1');
            }
            ans+=c;
            i++;
        }
        while(j<s2.size()){
            char c=s2[j];
            if(rem){
                if(c=='1')
                rem=1;   
                else
                rem=0;
            c=addproto(c,'1');
            }
            ans+=c;
            j++;
        }
        if(rem){
            ans+='1';
        }
        if(s1.size()>1||s2.size()>1){
            while(ans[ans.size()-1]!='1')
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends