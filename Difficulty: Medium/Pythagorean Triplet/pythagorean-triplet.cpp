class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        unordered_map<int,int>mm;
        for(int i=0;i<arr.size();i++){
            mm[arr[i]*arr[i]]++;
        }
        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++){
                if(mm[(arr[i]*arr[i])+(arr[j]*arr[j])])
                return 1;
            }
        }
        return 0;
    }
};