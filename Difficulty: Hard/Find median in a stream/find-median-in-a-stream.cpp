class Solution {
  public:
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    void insert(int x)
    {
        if(left.empty())
        left.push(x);
        else{
            if(x>left.top())
            right.push(x);
            else
            left.push(x);
        }
    }
    void balance()
    {
        if(left.size()>right.size()+1){
            right.push(left.top());
            left.pop();
        }
        if(right.size()>left.size()){
            left.push(right.top());
            right.pop();
        }
    }
    double median()
    {
        if(left.size()-1==right.size())
        return left.top();
        else{
            double ans=left.top()+right.top();
            return ans/2;
        }
    }
    vector<double> getMedian(vector<int> &arr) {
        // code here
        vector<double>ans;
        for(int i=0;i<arr.size();i++){
            insert(arr[i]);
            balance();
            ans.push_back(median());
        }
        return ans;
    }
};
