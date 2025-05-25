class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char> st;
        string ans;
        for(int i=0;i<s.size();i++){
            char c= s[i];
            if(!st.empty() && st.top()==c){
                st.pop();
            }
            else{
                st.push(c);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }

};