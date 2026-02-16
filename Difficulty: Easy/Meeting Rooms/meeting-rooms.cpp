class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(int i=0;i<arr.size();i++){
            q.push({arr[i][1],arr[i][0]});
        }
        while(q.size()>1){
            pair<int,int>temp=q.top();
            q.pop();
            if(temp.first>q.top().second)
            return 0;
        }
        return 1;
        
    }
};