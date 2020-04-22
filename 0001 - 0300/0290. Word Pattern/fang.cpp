class Solution {
    vector<string> split(string& s) {
        regex reg{"\\s+"};
        return vector<string>{sregex_token_iterator(s.begin(), s.end(), reg, -1), sregex_token_iterator()};
    }

    vector<int> mode(vector<string>&& arr) {
        unordered_map<string, int> lookup;
        vector<int> order;
        int counts = 1;
        for (auto& elem : arr) {
            auto got = lookup.find(elem);
            if (got == lookup.end()) {
                order.push_back(counts);
                lookup.insert(make_pair(elem, counts++));
            } else {
                order.push_back(got->second);
            }
        }

        return order;
    }

    vector<int> mode(string& s) {
        unordered_map<char, int> lookup;
        vector<int> order;
        int counts = 1;
        for (auto& letter : s) {
            auto got = lookup.find(letter);
            if (got == lookup.end()) {
                order.push_back(counts);
                lookup.insert(make_pair(letter, counts++));
            } else {
                order.push_back(got->second);
            }
        }

        return order;
    }

public:
    bool wordPattern(string pattern, string str) {
        return mode(pattern) == mode(split(str));
    }
};