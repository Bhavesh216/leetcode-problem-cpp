class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n= start.size();
        vector<pair<int,int>>meeting;
        
        for(int i=0;i<n;i++){
            meeting.push_back({end[i],start[i]});
        }
        sort(meeting.begin(),meeting.end());
        
        int count=0;
        int val=-1;
        
        for(int i=0;i<n;i++){
            if(meeting[i].second> val){
                count++;
                val=meeting[i].first;
            }
            
        }
       return count; 
    }
};
