
class Solution {
  public:
    void arrange(vector<long long>& arr) {
        //  code here
        int n=arr.size();
        for(int i=0;i<n;i++){
            arr[i]+=n*(arr[arr[i]%n]%n);
        }
        for(int i=0;i<n;i++){
            arr[i]=arr[i]/n;
        }
    }
};