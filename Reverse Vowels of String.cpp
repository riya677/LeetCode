#include <string>
#include <unordered_set>

class Solution {
public:
    std::string reverseVowels(std::string s) {
        int left = 0, right = s.length() - 1;
        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        while (left < right) {
            if (vowels.count(s[left]) && vowels.count(s[right])) {
                std::swap(s[left], s[right]);
                ++left;
                --right;
            } else if (vowels.count(s[left])) {
                --right;
            } else if (vowels.count(s[right])) {
                ++left;
            } else {
                ++left;
                --right;
            }
        }
        
        return s;
    }
};
