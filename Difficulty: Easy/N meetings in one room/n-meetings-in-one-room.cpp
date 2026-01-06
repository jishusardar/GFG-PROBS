class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int,int>>meetings;
        for(int i=0;i<start.size();i++){
            meetings.push_back({end[i],start[i]});
        }
        int ans=1;
        pair<int,int>l;
        sort(meetings.begin(),meetings.end());
        l={meetings[0].first,meetings[0].second};
        for(int i=1;i<meetings.size();i++){
            if(meetings[i].second>l.first){
                l={meetings[i].first,meetings[i].second};
                ans++;
            }
        }
        return ans;
    }
};