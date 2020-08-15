class Solution {
public:
    string addStrings(string num1, string num2)
    {
        bool bLength = num1.length() > num2.length();
        string& s1 = bLength ? num1 : num2;
        string& s2 = bLength ? num2 : num1;
        auto it1 = s1.rbegin();
        auto it2 = s2.rbegin();
        int carry = 0;
        for (; it2 != s2.rend(); ++it1, ++it2) {
            int num = *it1 - '0' + *it2 - '0' + carry;
            *it1 = '0' + char(num % 10);
            carry = num / 10;
        }

        while (carry != 0) {
            if (it1 == s1.rend()) {
                it1 = string::reverse_iterator(1 + s1.insert(it1.base(), '0'));
            }
            int num = *it1 - '0' + carry;

            *it1 = '0' + char(num % 10);
            carry = num / 10;
            it1++;
        }
        return s1;
    }
};