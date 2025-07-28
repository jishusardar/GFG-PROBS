class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int jumps=0,currEnd=0,far=0;
        for(int i=0;i<arr.size()-1;i++){
            far=max(far,i+arr[i]);
            if(far<=i)
            return -1;
            if(i==currEnd){
                jumps++;
                currEnd=far;
            }
        }
        return jumps;
    }
};
