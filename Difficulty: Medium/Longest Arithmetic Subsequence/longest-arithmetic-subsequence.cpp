// User function template for C++

class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        // code here
        int ans=2;
        int n=arr.size();
        if(n<=2)
        return n;
        unordered_map<int,int>mm[n];
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
               int d=arr[i]-arr[j];
               if(mm[j].count(d)){
                   mm[i][d]=max(mm[i][d],1+mm[j][d]);
                   ans=max(ans,mm[i][d]);
               }
               else{
                   if(!mm[i].count(d)){
                       mm[i][d]=2;
                   }
               }
            }
        }
        return ans;
        
    }
};