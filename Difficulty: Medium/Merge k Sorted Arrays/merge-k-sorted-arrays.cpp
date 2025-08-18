class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // code here
        vector<int>ans;
        vector<pair<int,pair<int,int>>>temp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            temp.push_back(make_pair(arr[i][0],make_pair(i,0)));
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q(temp.begin(),temp.end());
        while(!q.empty()){
            pair<int,pair<int,int>>p=q.top();
            q.pop();
            int num=p.first;
            int i=p.second.first;
            int j=p.second.second;
            ans.push_back(num);
            if(j+1<n){
                q.push(make_pair(arr[i][j+1],make_pair(i,j+1)));
            }
        }
        return ans;
    }
};