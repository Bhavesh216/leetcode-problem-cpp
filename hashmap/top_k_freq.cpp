class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int n = nums.size();

        for(int i=0; i<n; i++){
            map[nums[i]]++;
        }

        vector<pair<int, int>> vec;
        for(auto it : map){
            vec.push_back({it.second, it.first});
        }

        sort(vec.rbegin(), vec.rend());

        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(vec[i].second);
        }

        return res;
    }
};