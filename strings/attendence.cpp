#include <string>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, l = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                a++;
            }
            if (i < n - 2 && s[i] == 'L' && s[i + 1] == 'L' && s[i + 2] == 'L') {
                l++;
            }
        }

        return a < 2 && l == 0;
    }
};
