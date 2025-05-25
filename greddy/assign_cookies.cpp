class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int left=0;
        int right=0;
        int count=0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        while(left<g.size()&& right<s.size()){
            if(s[right]>=g[left]){
                left++;
            }
            right++;
        }
        return left;;
    }
};