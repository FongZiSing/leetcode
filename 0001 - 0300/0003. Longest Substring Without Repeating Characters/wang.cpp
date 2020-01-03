// two pointers, sliding window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[256] = {0};
        int fast = -1;
        int slow = 0;
        int result = 0;
        while(slow < s.size())
        {
            if(fast + 1 < s.size() && !map[s[fast + 1]])
            {
                fast++;
                map[s[fast]] = 1;
            }
            else
            {
                map[s[slow]] = 0;
                slow++;
            }

            result = max(result, fast - slow + 1);
        }
        return result;
    }
};
