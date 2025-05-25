class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> t_map;
        unordered_map<char,int> s_map;

        for(int i=0;i<t.size();i++){
            t_map[t[i]]++;
        }
        
        int left=0;
        int start=0;
        int minlen=INT_MAX;
        int formed=0;
        int required = t_map.size();

        
        for(int right=0;right<s.size();right++){
           char c=s[right];
            s_map[c]++;

            if(t_map.count(c) && s_map[c]==t_map[c]){
                formed++;
            }
            while(formed==required){
                if(right- left+1<minlen){
                    minlen=right-left+1;
                    start=left;
                }

                char leftchar=s[left];
                s_map[leftchar]--;
                if (t_map.count(leftchar) && s_map[leftchar] < t_map[leftchar]) {
                    formed--;
                }
                left++;
            }
        }
        if (minlen == INT_MAX) return "";
        return s.substr(start, minlen);

    }
};