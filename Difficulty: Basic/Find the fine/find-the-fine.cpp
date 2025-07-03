

class Solution {
  public:
    long long int totalFine(int date, vector<int> &car, vector<int> &fine) {
        // code here
        long long int ans=0;
        for(int i=0;i<car.size();i++){
            if(car[i]%2!=date%2)
            ans+=fine[i];
        }
        return ans;
    }
};