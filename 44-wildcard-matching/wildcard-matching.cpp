#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int sIdx = 0, pIdx = 0;
        int starIdx = -1, match = 0;

        while (sIdx < s.length()) {
            // 1. Current characters match, or pattern has '?'
            if (pIdx < p.length() && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            }
            // 2. Pattern character is '*', save star location and assume '*' matches 0 chars
            else if (pIdx < p.length() && p[pIdx] == '*') {
                starIdx = pIdx;
                match = sIdx;
                pIdx++;
            }
            // 3. Mismatch occurs, but a prior '*' was seen: backtrack and expand '*' match length by 1
            else if (starIdx != -1) {
                pIdx = starIdx + 1;
                match++;
                sIdx = match;
            }
            // 4. Mismatch occurs with no '*' to backtrack to
            else {
                return false;
            }
        }

        // Consume any remaining trailing '*' characters in pattern
        while (pIdx < p.length() && p[pIdx] == '*') {
            pIdx++;
        }

        return pIdx == p.length();
    }
};