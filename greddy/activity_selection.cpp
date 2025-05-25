// Print the starting time of selected activities in sorted order separated by space
void activitySelection(vector<int> start, vector<int> finish) {
  // Write your code here
    vector<pair<int,int>> v;
    int n=start.size();
    
    for(int i =0;i<n;i++){
        v.push_back({finish[i],start[i]});
    }
    sort(v.begin(),v.end());
    int val=0;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(v[i].second>=val){
            ans.push_back(v[i].second);
            val=v[i].first;
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
     cout<<ans[i]<<" ";   
    }
}