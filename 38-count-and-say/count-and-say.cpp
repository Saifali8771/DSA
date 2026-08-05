#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        if (n <= 0) return "";
        
        std::string current = "1";
        
        for (int i = 2; i <= n; ++i) {
            std::string next = "";
            int count = 1;
            
            for (size_t j = 1; j < current.length(); ++j) {
               
                if (current[j] == current[j - 1]) {
                    count++;
                } else {
                    next += std::to_string(count) + current[j - 1];
                    count = 1; 
                }
            }
            next += std::to_string(count) + current.back();
            current = next;
        }     
        return current;
    }
};