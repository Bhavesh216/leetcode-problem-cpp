#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream ss(title);
        string word, result = "";
        
        while (ss >> word) {
            if {
                // Capitalize the first letter and lowercase the rest
                word[0] = toupper(word[0]);
                for (int i = 1; i < word.length(); ++i) {
                    word[i] = tolower(word[i]);
                }
            }
            result += word + " ";
        }
        
        // Remove trailing space if any
        if (!result.empty()) {
            result.pop_back();
        }

        return result;
    }
};