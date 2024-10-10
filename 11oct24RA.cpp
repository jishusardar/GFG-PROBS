vector<int> rearrange(const vector<int>& arr) {
        vector<int>ans(arr.size(),-1);
        unordered_map<int,bool>mm;
        for(int i=0;i<arr.size();i++){
            mm[arr[i]]=1;
        }
        for(int i=0;i<arr.size();i++){
            if(mm[i]){
                ans[i]=i;
            }
        }
        return ans;
