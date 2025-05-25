class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        unordered_map<char,int> map;
        
        int left=0;
        int right=0;
        int maxlen=-1;
        
       for(int right=0;right<s.size();right++){
            map[s[right]]++;
            
            while(map.size()>k){
                map[s[left]]--;
                if(map[s[left]]==0){
                    map.erase(s[left]);
                }
                left++;
            }
            if(map.size()==k){
                maxlen=max(maxlen,right-left+1);
            }
          
        }
        return maxlen;
        
    }
};

