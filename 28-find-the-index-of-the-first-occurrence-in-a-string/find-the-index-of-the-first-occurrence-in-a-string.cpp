#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        // find() returns std::string::npos if the substring isn't found
        size_t index = haystack.find(needle);
        
        return (index != std::string::npos) ? static_cast<int>(index) : -1;
    }
};