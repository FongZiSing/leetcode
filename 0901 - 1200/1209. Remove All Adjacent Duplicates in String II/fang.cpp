class Solution {
public:
    string removeDuplicates(string s, int k) {
        deque<char> s1;
        deque<int> s2;
        char l;
        int cnt;
        s1.push_back('#');
        s2.push_back(1);
        k--;
        for (auto& letter : s) {
            l = s1.back();
            cnt = s2.back();
            if (l != letter) {
                s1.push_back(letter);
                s2.push_back(1);
            } else if (cnt == k) {
                while (cnt--) {
                    s1.pop_back();
                    s2.pop_back();
                }
            } else {
                s1.push_back(letter);
                s2.push_back(cnt + 1);
            }
        }

        return string(s1.begin() + 1, s1.end());
    }
};