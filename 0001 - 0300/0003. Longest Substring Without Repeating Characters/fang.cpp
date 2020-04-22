class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int len = s.size(), left = 0, res = 0;
        for (int right = 0; right < len; ++right) {
            while (set.find(s[right]) != set.end()) {
                set.erase(s[left++]);
            }
            set.insert(s[right]);
            res = max(static_cast<int>(set.size()), res);
        }
        return res;
    }
};