class Solution {
    using PAIR = pair<char, int>;

public:
    string frequencySort(string s) {
        string result;
        unordered_map<char, int> frequency;
        for (auto&& c : s) {
            auto got = frequency.find(c);
            if (got == frequency.end())
                frequency.insert(make_pair(c, 1));
            else
                got->second++;
        }
        vector<PAIR> arr(frequency.begin(), frequency.end());
        sort(arr.begin(), arr.end(), [](const PAIR& lhs, const PAIR& rhs) -> bool { return lhs.second > rhs.second; });
        for_each(arr.begin(), arr.end(), [&result](const PAIR& val) -> void { int loop = val.second; while(loop--) result += val.first; });

        return result;
    }
};