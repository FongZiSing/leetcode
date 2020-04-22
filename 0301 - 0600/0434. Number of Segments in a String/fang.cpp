class Solution {
    // 去除前面的空格
    string& trim(string& s) {
        if (!s.empty())
            s.erase(0, s.find_first_not_of(" "));
        return s;
    }

    // 使用正则表达式分割字符串
    vector<string> split(string& s) {
        regex reg{"\\s+"};
        return s.empty() ? vector<string>() : vector<string>{sregex_token_iterator(s.begin(), s.end(), reg, -1), sregex_token_iterator()};
    }

public:
    int countSegments(string s) {
        return split(trim(s)).size();
    }
};