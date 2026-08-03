#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;
        if (s.empty() || words.empty()) return result;

        int numWords = words.size();
        int wordLen = words[0].length();
        int totalLen = numWords * wordLen;
        int sLen = s.length();

        if (sLen < totalLen) return result;

        std::unordered_map<std::string, int> wordCount;
        for (const std::string& word : words) {
            wordCount[word]++;
        }

      
        for (int i = 0; i < wordLen; ++i) {
            int left = i;
            int right = i;
            int count = 0;
            std::unordered_map<std::string, int> currentCount;

           
            while (right + wordLen <= sLen) {
                std::string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordCount.count(word)) {
                    currentCount[word]++;
                    count++;

                    while (currentCount[word] > wordCount[word]) {
                        std::string leftWord = s.substr(left, wordLen);
                        currentCount[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    currentCount.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};